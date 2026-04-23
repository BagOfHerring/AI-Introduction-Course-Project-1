#include "mujoco_ros2_control/mujoco_ros2_control.hpp"
#include <set>

namespace mujoco_ros2_control {

namespace {

bool is_unstarted_sim_time(const rclcpp::Time &time)
{
	return time.nanoseconds() <= 0;
}

class PreloadedResourceManager : public hardware_interface::ResourceManager
{
public:
	explicit PreloadedResourceManager(const hardware_interface::ResourceManagerParams &params)
	: hardware_interface::ResourceManager(params, false)
	{
	}

	void mark_components_initialized()
	{
		components_are_loaded_and_initialized_ = true;
	}
};

}  // namespace

std::string concatenateNamespace(const std::string ns1, const std::string ns2){
	if(ns1.back() == '/'){
		return ns1 + ns2;
	}
	else{
		return ns1 + '/' + ns2;
	}

}
std::string MujocoRos2ControlPluginPrivate::getURDF() const
{
	std::string urdf_string;

	using namespace std::chrono_literals;
	auto parameters_client = std::make_shared<rclcpp::AsyncParametersClient>(node_, robot_description_node_);
	while (!parameters_client->wait_for_service(0.5s)) {
		if (!rclcpp::ok()) {
			RCLCPP_ERROR(node_->get_logger(), "Interrupted while waiting for %s service. Exiting.",
			             robot_description_node_.c_str());
			return 0;
		}
		RCLCPP_ERROR(node_->get_logger(), "%s service not available, waiting again...", robot_description_node_.c_str());
	}

	RCLCPP_INFO(node_->get_logger(), "connected to service. %s asking for %s", robot_description_node_.c_str(),
	            this->robot_description_.c_str());
	
	// search and wait for robot_description on param server
	while (urdf_string.empty()) {

		try {
			auto f = parameters_client->get_parameters({ this->robot_description_ });
			if (f.wait_for(500ms) != std::future_status::ready) {
				RCLCPP_WARN(node_->get_logger(),
				           "Timed out waiting for %s from %s. Retrying...",
				           this->robot_description_.c_str(),
				           robot_description_node_.c_str());
				continue;
			}
			std::vector<rclcpp::Parameter> values = f.get();
			if (!values.empty() && values[0].get_type() == rclcpp::ParameterType::PARAMETER_STRING) {
				urdf_string = values[0].as_string();
			}
		} catch (const std::exception &e) {
			RCLCPP_ERROR(node_->get_logger(), "%s", e.what());
		}

		if (!urdf_string.empty()) {
			break;
		} else {
			RCLCPP_ERROR(node_->get_logger(),
			             "mujoco_ros2_control plugin is waiting for model"
			             " URDF in parameter [%s] on the ROS param server.",
			             this->robot_description_.c_str());
		}
		std::this_thread::sleep_for(std::chrono::microseconds(100000));
	}
	RCLCPP_INFO(node_->get_logger(), "Received URDF from param server");

	return urdf_string;
}

// MujocoRos2ControlPlugin::MujocoRos2ControlPlugin()
// {

// }

MujocoRos2ControlPlugin::~MujocoRos2ControlPlugin()
{
	// Stop controller manager thread
	if (!this->dataPtr_->controller_manager_) {
		return;
	}
	env_ptr_->RemoveNodeFromExecutor(this->dataPtr_->controller_manager_->get_node_base_interface());
	// this->dataPtr_->executor_->cancel();
	// this->dataPtr_->thread_executor_spin_.join();
}

mujoco_ros::CallbackReturn MujocoRos2ControlPlugin::on_configure(const rclcpp_lifecycle::State &/*previous_state*/){
	RCLCPP_INFO_STREAM(get_my_logger(), "Configuring mujoco_ros2_control plugin");
	mujoco_ros::declare_parameter_if_not_declared(
		this->get_node()->get_node_parameters_interface(),
		"namespace",
		rclcpp::ParameterValue("")
	);
	mujoco_ros::declare_parameter_if_not_declared(
		this->get_node()->get_node_parameters_interface(),
		"robot_description_node",
		rclcpp::ParameterValue("robot_state_publisher")
	);
	mujoco_ros::declare_parameter_if_not_declared(
		this->get_node()->get_node_parameters_interface(),
		"robot_description",
		rclcpp::ParameterValue("robot_description")
	);
	

	return mujoco_ros::CallbackReturn::SUCCESS;	
}

void MujocoRos2ControlPlugin::ControlCallback(const mjModel* /* model */, mjData* data)
{
	rclcpp::Time sim_time_mj =
		rclcpp::Time(static_cast<int64_t>(data->time * 1e9), this->dataPtr_->sim_clock_type_);
	if (is_unstarted_sim_time(sim_time_mj)) {
		return;
	}
	rclcpp::Duration sim_period(0, 0);
	if (!is_unstarted_sim_time(this->dataPtr_->last_update_sim_time_mj_)) {
		sim_period = sim_time_mj - this->dataPtr_->last_update_sim_time_mj_;
	}
	this->dataPtr_->controller_manager_->write(sim_time_mj, sim_period);
};
void MujocoRos2ControlPlugin::PassiveCallback(const mjModel* /* model */, mjData* data)
{
	rclcpp::Time sim_time_mj =
		rclcpp::Time(static_cast<int64_t>(data->time * 1e9), this->dataPtr_->sim_clock_type_);
	if (is_unstarted_sim_time(sim_time_mj)) {
		return;
	}
	rclcpp::Duration sim_period(0, 0);
	if (!is_unstarted_sim_time(this->dataPtr_->last_update_sim_time_mj_)) {
		sim_period = sim_time_mj - this->dataPtr_->last_update_sim_time_mj_;
	}
	this->dataPtr_->last_update_sim_time_mj_ = sim_time_mj;
	this->dataPtr_->controller_manager_->read(sim_time_mj, sim_period);
	this->dataPtr_->controller_manager_->update(sim_time_mj, sim_period);
};
void MujocoRos2ControlPlugin::RenderCallback(const mjModel* /* model */, mjData* /* data */, mjvScene* /* scene */)
{
};
void MujocoRos2ControlPlugin::LastStageCallback(const mjModel* /* model */, mjData* /* data */)
{
};
void MujocoRos2ControlPlugin::OnGeomChanged(const mjModel* /* model */, mjData* /* data */, const int /* geom_id */)
{
};

bool MujocoRos2ControlPlugin::Load(const mjModel *model, mjData *data)
{
	dataPtr_ = std::make_unique<MujocoRos2ControlPluginPrivate>();
	dataPtr_->node_ = get_node();
	RCLCPP_INFO_STREAM(dataPtr_->node_->get_logger(), "Namespace: " << get_node()->get_namespace() << "; Fully qualified name: " << get_node()->get_node_base_interface()->get_fully_qualified_name());

	RCLCPP_INFO_STREAM(dataPtr_->node_->get_logger(), "loading with given model and data");
	// TODO: Need to rearrange the params to come from own yaml tree, along with on_configure settings 

	// get the name of the robot_state_publisher node
	this->dataPtr_->robot_description_node_ = dataPtr_->node_->get_parameter("robot_description_node").as_string();
	RCLCPP_INFO_STREAM(dataPtr_->node_->get_logger(), "robot_description_node name is " << this->dataPtr_->robot_description_node_);


	// get the name of the srv from the node above that holds the URDF string
	// get the name of the robot_state_publisher node
	this->dataPtr_->robot_description_ = dataPtr_->node_->get_parameter("robot_description").as_string();
	RCLCPP_INFO_STREAM(dataPtr_->node_->get_logger(), "robot_description service name is " << this->dataPtr_->robot_description_);
	// todo: Make the logic for passing additional ros-args when initializing, like L292~ in ign_ros2_control_plugin.cpp

	// Construct the fully qualified robot_description_node's name.
	// The namespace will also be used for the nodes of this.
	std::string ns = dataPtr_->node_->get_parameter("namespace").as_string();
	if (ns.empty()) {
		ns = dataPtr_->node_->get_namespace();
	}

	// prevent exception: namespace must be absolute, it must lead with a '/'
	if (ns.empty() || ns[0] != '/') {
		ns = '/' + ns;
	}
	if (ns.length() > 1) {
		this->dataPtr_->robot_description_node_ = ns + "/" + this->dataPtr_->robot_description_node_;
	}
	else{
		this->dataPtr_->robot_description_node_ = ns + this->dataPtr_->robot_description_node_;
	}
	RCLCPP_INFO(dataPtr_->node_->get_logger(), "robot_description_node fully qualified name: %s", this->dataPtr_->robot_description_node_.c_str());

	// Create a default context, if not already
	if (!rclcpp::ok()) {
  		std::vector<const char *> _argv;
		rclcpp::init(static_cast<int>(_argv.size()), _argv.data()); // todo: make the logic for passing additional ros-args
	}

	RCLCPP_INFO_STREAM(dataPtr_->node_->get_logger(), "Fully qualified mujoco_ros2_control node name: " << this->dataPtr_->node_->get_node_base_interface()->get_fully_qualified_name());

	// executor creation
	this->dataPtr_->executor_ = env_ptr_->GetExecutorPtr();
	const bool use_sim_time =
		env_ptr_->has_parameter("use_sim_time") ? env_ptr_->get_parameter("use_sim_time").as_bool() : false;
	this->dataPtr_->sim_clock_type_ = use_sim_time ? RCL_ROS_TIME : RCL_STEADY_TIME;
	this->dataPtr_->last_update_sim_time_mj_ = rclcpp::Time((int64_t)0, this->dataPtr_->sim_clock_type_);
	// Read urdf from ros parameter server then
	// setup actuators and mechanism control node.
	// This call will block if ROS is not properly initialized.
	std::string urdf_string;
	std::vector<hardware_interface::HardwareInfo> control_hardware_info;
	try {
		urdf_string = this->dataPtr_->getURDF();
		control_hardware_info = hardware_interface::parse_control_resources_from_urdf(urdf_string);
	} catch (const std::runtime_error & ex) {
		RCLCPP_ERROR_STREAM(
		this->dataPtr_->node_->get_logger(),
		"Error parsing URDF in mujoco_ros2_control plugin, plugin not active : " << ex.what());
		return false;
	}

	hardware_interface::ResourceManagerParams resource_manager_params;
	resource_manager_params.robot_description = urdf_string;
	resource_manager_params.clock = this->dataPtr_->node_->get_clock();
	resource_manager_params.logger = this->dataPtr_->node_->get_logger();
	resource_manager_params.node_namespace = ns;
	resource_manager_params.executor = this->dataPtr_->executor_;
	resource_manager_params.update_rate = 1000;
	auto resource_manager_ = std::make_unique<PreloadedResourceManager>(resource_manager_params);
	try {
		this->dataPtr_->robot_hw_sim_loader_.reset(
		new pluginlib::ClassLoader<mujoco_ros2_control::MujocoRos2SystemInterface>(
			"mujoco_ros2_control",
			"mujoco_ros2_control::MujocoRos2SystemInterface"));
	} catch (pluginlib::LibraryLoadException & ex) {
		RCLCPP_ERROR(
		this->dataPtr_->node_->get_logger(), "Failed to create robot simulation interface loader: %s ",
		ex.what());
		return false;
	}
	for (unsigned int i = 0; i < control_hardware_info.size(); ++i) {
		std::string robot_hw_sim_type_str_ = control_hardware_info[i].hardware_plugin_name;
		std::unique_ptr<mujoco_ros2_control::MujocoRos2SystemInterface> mujocoRos2System;
		RCLCPP_DEBUG(
		this->dataPtr_->node_->get_logger(), "Load hardware interface %s ...",
		robot_hw_sim_type_str_.c_str());
		try {
			mujocoRos2System = std::unique_ptr<mujoco_ros2_control::MujocoRos2SystemInterface>(
				this->dataPtr_->robot_hw_sim_loader_->createUnmanagedInstance(robot_hw_sim_type_str_));
			RCLCPP_INFO(this->dataPtr_->node_->get_logger(), "createUnmanagedInstance");
		} catch (pluginlib::PluginlibException & ex) {
			RCLCPP_ERROR(
				this->dataPtr_->node_->get_logger(),
				"The plugin failed to load for some reason. Error: %s\n",
				ex.what());
			continue;
		}
		if (!mujocoRos2System->initSim(
			this->dataPtr_->node_,
			control_hardware_info[i],
			model,
			data,
			this->dataPtr_->update_rate))
		{
			RCLCPP_FATAL(
				this->dataPtr_->node_->get_logger(), "Could not initialize robot simulation interface");
				return false;	
		}
		RCLCPP_DEBUG(
			this->dataPtr_->node_->get_logger(), "Initialized robot simulation interface %s!",
			robot_hw_sim_type_str_.c_str());
		
		
		RCLCPP_DEBUG_STREAM(this->dataPtr_->node_->get_logger(), "resource-manager system comp size: " << resource_manager_->system_components_size());
		hardware_interface::HardwareComponentParams component_params;
		component_params.hardware_info = control_hardware_info[i];
		component_params.logger = this->dataPtr_->node_->get_logger();
		component_params.clock = this->dataPtr_->node_->get_clock();
		component_params.node_namespace = ns;
		component_params.executor = this->dataPtr_->executor_;
		resource_manager_->import_component(std::move(mujocoRos2System), component_params);
		
		RCLCPP_DEBUG_STREAM(this->dataPtr_->node_->get_logger(), "resource-manager system comp size: " << resource_manager_->system_components_size());
		RCLCPP_DEBUG(this->dataPtr_->node_->get_logger(), "Setting state of %s to active", control_hardware_info[i].name.c_str());
		rclcpp_lifecycle::State state(
			lifecycle_msgs::msg::State::PRIMARY_STATE_ACTIVE,
			hardware_interface::lifecycle_state_names::ACTIVE);
		resource_manager_->set_component_state(control_hardware_info[i].name, state);
	}
	resource_manager_->import_joint_limiters(urdf_string);
	resource_manager_->mark_components_initialized();

	// Create the controller manager

	// Get controller manager node name
	std::string controllerManagerNodeName{"controller_manager"};
	RCLCPP_INFO(this->dataPtr_->node_->get_logger(), "Loading controller_manager");
	// The node options are very specific. The two function(true) lines mimic what is set for controller_manager::get_cm_options();
	// without them, the controller manager will break.
	auto cm_options = rclcpp::NodeOptions().arguments({"--ros-args", 
														"--remap", controllerManagerNodeName + ":__node:=" + controllerManagerNodeName,
														"--remap", "joint_state_broadcaster:__node:=joint_state_broadcaster_alt"});
	cm_options.allow_undeclared_parameters(true);
	cm_options.automatically_declare_parameters_from_overrides(true);
	cm_options.append_parameter_override("use_sim_time", use_sim_time);

		// This part sometimes breaks with error munmap_chunk(): invalid pointer
	this->dataPtr_->controller_manager_.reset(
		new controller_manager::ControllerManager(
		std::move(resource_manager_),
		this->dataPtr_->executor_,
		controllerManagerNodeName,
		ns,
		cm_options));
	env_ptr_->AddNodeToExecutor(this->dataPtr_->controller_manager_->get_node_base_interface());
	RCLCPP_WARN_STREAM(this->dataPtr_->node_->get_logger(), this->dataPtr_->controller_manager_->get_fully_qualified_name() << ns << controllerManagerNodeName);
	if (!this->dataPtr_->controller_manager_->has_parameter("update_rate")) {
		RCLCPP_ERROR_STREAM(
		this->dataPtr_->node_->get_logger(),
		"controller manager doesn't have an update_rate parameter");
		return false;
	}
	
	this->dataPtr_->update_rate = this->dataPtr_->controller_manager_->get_update_rate();
	this->dataPtr_->control_period_ = rclcpp::Duration(
		std::chrono::duration_cast<std::chrono::nanoseconds>(
		std::chrono::duration<double>(1.0 / static_cast<double>(this->dataPtr_->update_rate))));
	
	return true;
}

void MujocoRos2ControlPlugin::Reset()
{
	RCLCPP_INFO_STREAM(dataPtr_->node_->get_logger(), "reset");
}

} // namespace mujoco_ros2

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(mujoco_ros2_control::MujocoRos2ControlPlugin, mujoco_ros::MujocoPlugin)
