#!/usr/bin/env python3
"""
Scene Generator
===============
Generates scene_with_workbench.xml with 8 randomized parts on the table:
  4 types (gear, square_gear, nut, bearing) × 2 each
  Random: color, scale, position (within safe table bounds)

Usage:
    python3 generate_scene.py            # generate + overwrite XML
    python3 generate_scene.py --preview  # just print to stdout
"""
import random
import argparse
import os

# ── Paths ───────────────────────────────────────────────────────────────
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
SCENE_DIR = os.path.join(SCRIPT_DIR, '..', 'franka_description', 'mujoco', 'franka')
OUTPUT_FILE = os.path.join(SCENE_DIR, 'scene_with_workbench.xml')

# ── Part definitions ────────────────────────────────────────────────────
PART_TYPES = [
    {'name': 'gear',        'stl': 'gear.stl',        'mesh_name': 'gear_mesh'},
    {'name': 'square_gear', 'stl': 'square_gear.stl', 'mesh_name': 'square_gear_mesh'},
    {'name': 'nut',         'stl': 'nut.stl',         'mesh_name': 'nut_mesh'},
    {'name': 'bearing',     'stl': 'bearing.stl',     'mesh_name': 'bearing_mesh'},
]

# ── Table geometry ──────────────────────────────────────────────────────
TABLE_X, TABLE_Y = 0.5, 0.0      # table center in world
TABLE_HALF_X     = 0.30           # safe spawn zone (table half-size is 0.4)
TABLE_HALF_Y     = 0.45           # safe spawn zone (table half-size is 0.6)
SPAWN_Z          = 0.50           # slightly above table top (0.4)

# ── Randomization bounds ────────────────────────────────────────────────
SCALE_MIN, SCALE_MAX = 0.003, 0.007   # mm → m conversion factor range
MASS_MIN, MASS_MAX   = 0.05, 0.20


def random_color():
    """Generate a pleasant random RGBA color (avoid very dark or very light)."""
    r = random.uniform(0.15, 0.95)
    g = random.uniform(0.15, 0.95)
    b = random.uniform(0.15, 0.95)
    return f"{r:.2f} {g:.2f} {b:.2f} 1"


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


def generate_xml():
    # Assign 2 of each type, with unique body names
    parts = []
    for ptype in PART_TYPES:
        for idx in range(1, 3):
            scale_val = random.uniform(SCALE_MIN, SCALE_MAX)
            parts.append({
                'body_name': f"part_{ptype['name']}_{idx}",
                'mesh_name': f"{ptype['mesh_name']}_{idx}",
                'stl':       ptype['stl'],
                'scale':     f"{scale_val:.4f} {scale_val:.4f} {scale_val:.4f}",
                'color':     random_color(),
                'mass':      round(random.uniform(MASS_MIN, MASS_MAX), 3),
            })

    # Assign random positions (no overlap)
    positions = []
    for p in parts:
        x, y = random_position(positions)
        positions.append((x, y))
        p['x'], p['y'], p['z'] = x, y, SPAWN_Z

    # ── Build XML ───────────────────────────────────────────────────────
    mesh_lines = ""
    for p in parts:
        mesh_lines += f'    <mesh name="{p["mesh_name"]}" file="{p["stl"]}" scale="{p["scale"]}"/>\n'

    body_lines = ""
    for p in parts:
        body_lines += f"""
    <body name="{p['body_name']}" pos="{p['x']:.3f} {p['y']:.3f} {p['z']:.3f}">
      <freejoint/>
      <geom type="mesh" mesh="{p['mesh_name']}" rgba="{p['color']}" mass="{p['mass']}" friction="1 0.005 0.0001"/>
    </body>
"""

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

{mesh_lines}  </asset>

  <worldbody>
    <light pos="0 0 1.5" dir="0 0 -1" directional="true"/>
    <geom name="floor" size="0 0 0.05" type="plane" material="groundplane"/>

    <!-- Workbench -->
    <body name="table" pos="0.5 0 0.2">
      <geom type="box" size="0.4 0.6 0.2" rgba="0.7 0.6 0.5 1"/>
      <!-- Quadrant Dividers -->
      <geom type="box" name="divider_x" pos="0 0 0.201" size="0.4 0.005 0.001" rgba="0 0 0 1" contype="0" conaffinity="0"/>
      <geom type="box" name="divider_y" pos="0 0 0.201" size="0.005 0.6 0.001" rgba="0 0 0 1" contype="0" conaffinity="0"/>
    </body>

    <!-- Camera -->
    <camera name="vision_cam" pos="0.5 0 3" fovy="45" xyaxes="0 -1 0 1 0 0"/>

    <!-- Randomized Parts ({len(parts)} total: 4 types x 2 each) -->
{body_lines}
  </worldbody>
</mujoco>
"""
    return xml


def main():
    parser = argparse.ArgumentParser(description='Generate randomized MuJoCo scene')
    parser.add_argument('--preview', action='store_true', help='Print XML to stdout instead of writing')
    parser.add_argument('--seed', type=int, default=None, help='Random seed for reproducibility')
    args = parser.parse_args()

    if args.seed is not None:
        random.seed(args.seed)

    xml = generate_xml()

    if args.preview:
        print(xml)
    else:
        # Resolve the output path relative to the source tree
        out = os.path.abspath(OUTPUT_FILE)
        with open(out, 'w') as f:
            f.write(xml)
        print(f'✅ Generated: {out}')
        print(f'   Now run: colcon build --packages-select franka_description')


if __name__ == '__main__':
    main()
