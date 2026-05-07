#!/usr/bin/env python3
"""
Scene Generator
===============
Generates scene_with_workbench.xml with 8 randomized parts on the table:
    4 types (gear, square_gear, nut, bearing) x 2 each
    Random: appearance, scale, position (within safe table bounds)

It also writes a machine-readable metadata file next to the scene XML so
dataset tooling can reuse the exact part layout, size, and camera settings.

Usage:
        python3 generate_scene.py                    # generate + overwrite XML
        python3 generate_scene.py --preview          # just print XML to stdout
        python3 generate_scene.py --dataset-mode     # fixed tabletop layout for labeling
"""
import argparse
import json
import random
import struct
from functools import lru_cache
from pathlib import Path

# ── Paths ───────────────────────────────────────────────────────────────
SCRIPT_PATH = Path(__file__).resolve()


def resolve_scene_dir() -> Path:
    """Locate franka_description/mujoco/franka in either source or install layouts."""
    source_candidate = SCRIPT_PATH.parents[2] / 'franka_description' / 'mujoco' / 'franka'
    if source_candidate.is_dir():
        return source_candidate

    try:
        from ament_index_python.packages import get_package_share_directory

        share_candidate = Path(get_package_share_directory('franka_description')) / 'mujoco' / 'franka'
        if share_candidate.is_dir():
            return share_candidate
    except (ImportError, LookupError):
        pass

    raise FileNotFoundError(
        'Unable to locate franka_description/mujoco/franka from generate_scene.py. '
        'Expected either a source checkout under ros2_ws/src or an installed franka_description package.'
    )


SCENE_DIR = resolve_scene_dir()
ASSET_DIR = SCENE_DIR / 'assets'
OUTPUT_FILE = SCENE_DIR / 'scene_with_workbench.xml'
METADATA_FILE = SCENE_DIR / 'scene_with_workbench.metadata.json'

# ── Part definitions ────────────────────────────────────────────────────
PART_TYPES = [
    {'name': 'gear',        'stl': 'gear.stl',        'mesh_name': 'gear_mesh'},
    {'name': 'square_gear', 'stl': 'square_gear.stl', 'mesh_name': 'square_gear_mesh'},
    {'name': 'nut',         'stl': 'nut.stl',         'mesh_name': 'nut_mesh'},
    {'name': 'bearing',     'stl': 'bearing.stl',     'mesh_name': 'bearing_mesh'},
]

# ── Table geometry ──────────────────────────────────────────────────────
TABLE_X, TABLE_Y = 0.5, 0.0
TABLE_HALF_X = 0.30
TABLE_HALF_Y = 0.45
TABLE_SURFACE_Z = 0.4
SPAWN_Z = 0.6
CAMERA_NAME = 'vision_cam'
CAMERA_POS = (0.5, 0.0, 1.4)
CAMERA_FOVY_DEG = 45.0

# ── Randomization bounds ────────────────────────────────────────────────
SCALE_MIN, SCALE_MAX = 0.0015, 0.002   # mm → m conversion factor range
MASS_MIN, MASS_MAX   = 0.05, 0.20


APPEARANCE_PRESETS = {
    'table_wood': {
        'rgba': '0.62 0.50 0.38 1',
        'specular': '0.10',
        'shininess': '0.08',
        'reflectance': '0.03',
    },
    'metal_silver': {
        'rgba': '0.78 0.80 0.84 1',
        'specular': '0.92',
        'shininess': '0.95',
        'reflectance': '0.35',
    },
    'metal_gunmetal': {
        'rgba': '0.30 0.33 0.37 1',
        'specular': '0.85',
        'shininess': '0.88',
        'reflectance': '0.28',
    },
    'metal_brass': {
        'rgba': '0.74 0.62 0.28 1',
        'specular': '0.90',
        'shininess': '0.90',
        'reflectance': '0.30',
    },
    'metal_blue': {
        'rgba': '0.34 0.47 0.66 1',
        'specular': '0.82',
        'shininess': '0.82',
        'reflectance': '0.22',
    },
    'wood_oak': {
        'rgba': '0.68 0.51 0.32 1',
        'specular': '0.18',
        'shininess': '0.14',
        'reflectance': '0.06',
    },
    'wood_walnut': {
        'rgba': '0.42 0.29 0.18 1',
        'specular': '0.12',
        'shininess': '0.10',
        'reflectance': '0.04',
    },
    'plastic_red': {
        'rgba': '0.80 0.24 0.20 1',
        'specular': '0.28',
        'shininess': '0.35',
        'reflectance': '0.08',
    },
    'plastic_white': {
        'rgba': '0.90 0.90 0.88 1',
        'specular': '0.22',
        'shininess': '0.26',
        'reflectance': '0.07',
    },
    'ceramic_ink': {
        'rgba': '0.16 0.18 0.22 1',
        'specular': '0.42',
        'shininess': '0.55',
        'reflectance': '0.12',
    },
}


PART_RGBA_PALETTE = [
    '0.95 0.27 0.27 1',
    '0.12 0.74 0.98 1',
    '0.98 0.84 0.16 1',
    '0.18 0.82 0.43 1',
    '0.96 0.38 0.14 1',
    '0.72 0.26 0.98 1',
]


def generate_material_assets() -> str:
    lines = []
    for material_name, props in APPEARANCE_PRESETS.items():
        if material_name != 'table_wood':
            continue
        lines.append(
            '    '
            f'<material name="{material_name}" '
            f'rgba="{props["rgba"]}" '
            f'specular="{props["specular"]}" '
            f'shininess="{props["shininess"]}" '
            f'reflectance="{props["reflectance"]}"/>'
        )
    return '\n'.join(lines) + '\n'


@lru_cache(maxsize=None)
def load_stl_bounds(stl_name: str):
    path = ASSET_DIR / stl_name
    raw = path.read_bytes()

    if len(raw) >= 84:
        tri_count = struct.unpack_from('<I', raw, 80)[0]
        expected_size = 84 + tri_count * 50
        if expected_size == len(raw):
            min_corner = [float('inf')] * 3
            max_corner = [float('-inf')] * 3
            for index in range(tri_count):
                offset = 84 + index * 50 + 12
                for vertex_index in range(3):
                    vx, vy, vz = struct.unpack_from('<fff', raw, offset + vertex_index * 12)
                    if vx < min_corner[0]:
                        min_corner[0] = vx
                    if vy < min_corner[1]:
                        min_corner[1] = vy
                    if vz < min_corner[2]:
                        min_corner[2] = vz
                    if vx > max_corner[0]:
                        max_corner[0] = vx
                    if vy > max_corner[1]:
                        max_corner[1] = vy
                    if vz > max_corner[2]:
                        max_corner[2] = vz
            return tuple(min_corner), tuple(max_corner)

    min_corner = [float('inf')] * 3
    max_corner = [float('-inf')] * 3
    for line in raw.decode('utf-8', errors='ignore').splitlines():
        stripped = line.strip()
        if not stripped.startswith('vertex '):
            continue
        _, x_str, y_str, z_str = stripped.split()[:4]
        vx, vy, vz = float(x_str), float(y_str), float(z_str)
        if vx < min_corner[0]:
            min_corner[0] = vx
        if vy < min_corner[1]:
            min_corner[1] = vy
        if vz < min_corner[2]:
            min_corner[2] = vz
        if vx > max_corner[0]:
            max_corner[0] = vx
        if vy > max_corner[1]:
            max_corner[1] = vy
        if vz > max_corner[2]:
            max_corner[2] = vz

    if min_corner[0] == float('inf'):
        raise ValueError(f'Unable to parse STL bounds from {path}')

    return tuple(min_corner), tuple(max_corner)


def compute_dimensions_m(stl_name: str, scale_value: float) -> dict:
    min_corner, max_corner = load_stl_bounds(stl_name)
    return {
        'x': (max_corner[0] - min_corner[0]) * scale_value,
        'y': (max_corner[1] - min_corner[1]) * scale_value,
        'z': (max_corner[2] - min_corner[2]) * scale_value,
    }


def random_position(existing_positions, min_dist=0.08):
    """Pick a random XY on table that is at least min_dist from all others."""
    for _ in range(200):
        x = TABLE_X + random.uniform(-TABLE_HALF_X, TABLE_HALF_X)
        y = TABLE_Y + random.uniform(-TABLE_HALF_Y, TABLE_HALF_Y)
        too_close = False
        for ex, ey in existing_positions:
            if ((x - ex)**2 + (y - ey)**2) ** 0.5 < min_dist:
                too_close = True
                break
        if not too_close:
            return x, y
    # fallback
    return (TABLE_X + random.uniform(-TABLE_HALF_X, TABLE_HALF_X),
            TABLE_Y + random.uniform(-TABLE_HALF_Y, TABLE_HALF_Y))


def generate_scene(static_parts: bool = False):
    # Assign 2 of each type, with unique body names
    parts = []
    color_palette = PART_RGBA_PALETTE.copy()
    random.shuffle(color_palette)
    color_index = 0
    for ptype in PART_TYPES:
        for idx in range(1, 3):
            scale_val = random.uniform(SCALE_MIN, SCALE_MAX)
            dimensions_m = compute_dimensions_m(ptype['stl'], scale_val)
            parts.append({
                'body_name': f"part_{ptype['name']}_{idx}",
                'part_type':  ptype['name'],
                'mesh_name': f"{ptype['mesh_name']}_{idx}",
                'stl':       ptype['stl'],
                'scale_value': scale_val,
                'scale':     f"{scale_val:.4f} {scale_val:.4f} {scale_val:.4f}",
                'rgba':      color_palette[color_index % len(color_palette)],
                'mass':      round(random.uniform(MASS_MIN, MASS_MAX), 3),
                'dimensions_m': dimensions_m,
            })
            color_index += 1

    # Assign random positions (no overlap)
    positions = []
    for p in parts:
        x, y = random_position(positions)
        positions.append((x, y))
        p['x'], p['y'] = x, y
        p['yaw'] = random.uniform(-3.141592653589793, 3.141592653589793)
        if static_parts:
            p['z'] = TABLE_SURFACE_Z + p['dimensions_m']['z'] / 2.0 + 0.0005
        else:
            p['z'] = SPAWN_Z

    # ── Build XML ───────────────────────────────────────────────────────
    mesh_lines = ""
    for p in parts:
        mesh_lines += f'    <mesh name="{p["mesh_name"]}" file="{p["stl"]}" scale="{p["scale"]}"/>\n'

    body_lines = ""
    for p in parts:
        body_open = (
            f"    <body name=\"{p['body_name']}\" "
            f"pos=\"{p['x']:.3f} {p['y']:.3f} {p['z']:.3f}\" "
            f"euler=\"0 0 {p['yaw']:.6f}\">"
        )
        freejoint_line = '' if static_parts else '      <freejoint/>\n'
        body_lines += f"""
{body_open}
{freejoint_line}      <geom type="mesh" mesh="{p['mesh_name']}" rgba="{p['rgba']}" mass="{p['mass']}" friction="1 0.005 0.0001"/>
    </body>
"""

    material_lines = generate_material_assets()

    xml = f"""<mujoco model="panda scene with workbench">

  <include file="panda.xml"/>

  <statistic center="0.3 0 0.4" extent="1"/>

  <visual>
    <headlight diffuse="0.6 0.6 0.6"  ambient="0.3 0.3 0.3" specular="0 0 0"/>
    <rgba haze="0.15 0.25 0.35 1"/>
    <global azimuth="120" elevation="-20"/>
  </visual>

  <asset>
    <texture type="skybox" builtin="gradient" rgb1="0.3 0.5 0.7" rgb2="0 0 0" width="512"
        height="3072"/>
    <texture type="2d" name="groundplane" builtin="checker" mark="edge" rgb1="0.2 0.3 0.4"
        rgb2="0.1 0.2 0.3" markrgb="0.8 0.8 0.8" width="300" height="300"/>
    <material name="groundplane" texture="groundplane" texuniform="true" texrepeat="5 5"
        reflectance="0.2"/>
{material_lines}

{mesh_lines}  </asset>

  <worldbody>
    <light pos="0 0 1.5" dir="0 0 -1" directional="true"/>
    <geom name="floor" size="0 0 0.05" type="plane" material="groundplane"/>

    <!-- Workbench -->
    <body name="table" pos="0.5 0 0.2">
            <geom type="box" size="0.4 0.6 0.2" material="table_wood"/>
      <!-- Quadrant Dividers -->
      <geom type="box" name="divider_x" pos="0 0 0.201" size="0.4 0.005 0.001" rgba="0 0 0 1" contype="0" conaffinity="0"/>
      <geom type="box" name="divider_y" pos="0 0 0.201" size="0.005 0.6 0.001" rgba="0 0 0 1" contype="0" conaffinity="0"/>
    </body>

    <!-- Camera -->
    <camera name="{CAMERA_NAME}" pos="{CAMERA_POS[0]} {CAMERA_POS[1]} {CAMERA_POS[2]}" fovy="{CAMERA_FOVY_DEG:g}" xyaxes="0 -1 0 1 0 0"/>

    <!-- Randomized Parts ({len(parts)} total: 4 types x 2 each) -->
{body_lines}
  </worldbody>
</mujoco>
"""
    metadata = {
        'scene_file': str(OUTPUT_FILE),
        'metadata_file': str(METADATA_FILE),
        'static_parts': static_parts,
        'table_surface_z': TABLE_SURFACE_Z,
        'camera': {
            'name': CAMERA_NAME,
            'position_xyz': list(CAMERA_POS),
            'fovy_deg': CAMERA_FOVY_DEG,
        },
        'class_names': ['bearing', 'square_gear', 'nut', 'gear'],
        'parts': [
            {
                'body_name': p['body_name'],
                'part_type': p['part_type'],
                'mesh_name': p['mesh_name'],
                'stl': p['stl'],
                'scale_value': p['scale_value'],
                'rgba': p['rgba'],
                'mass': p['mass'],
                'position_xyz': [p['x'], p['y'], p['z']],
                'yaw_rad': p['yaw'],
                'dimensions_m': p['dimensions_m'],
            }
            for p in parts
        ],
    }
    return xml, metadata


def main():
    parser = argparse.ArgumentParser(description='Generate randomized MuJoCo scene')
    parser.add_argument('--preview', action='store_true', help='Print XML to stdout instead of writing')
    parser.add_argument('--seed', type=int, default=None, help='Random seed for reproducibility')
    parser.add_argument(
        '--dataset-mode',
        action='store_true',
        help='Place static tabletop parts for image/label generation instead of floating free joints.',
    )
    parser.add_argument(
        '--metadata',
        type=Path,
        default=METADATA_FILE,
        help='Where to write the scene metadata JSON.',
    )
    args = parser.parse_args()

    if args.seed is not None:
        random.seed(args.seed)

    xml, metadata = generate_scene(static_parts=args.dataset_mode)

    if args.preview:
        print(xml)
    else:
        # Resolve the output path relative to the source tree
        out = OUTPUT_FILE.resolve()
        with open(out, 'w') as f:
            f.write(xml)
        metadata_path = args.metadata.resolve()
        metadata_path.write_text(json.dumps(metadata, indent=2), encoding='utf-8')
        print(f'✅ Generated: {out}')
        print(f'✅ Metadata:  {metadata_path}')
        print(f'   Now run: colcon build --packages-select franka_bringup franka_description')


if __name__ == '__main__':
    main()
