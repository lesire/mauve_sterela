
#include <rtt/Component.hpp>
#include "ObstacleDetector-component.hpp"
#ifdef USE_LTTNG
#  define TRACEPOINT_DEFINE
#  define TRACEPOINT_PROBE_DYNAMIC_LINKAGE
#  include <mauve/mauve-tp.h>
#  include <unistd.h>
#  include <sys/syscall.h>
#  include <sys/types.h>
#endif
namespace sterela {std::string ObstacleDetector::__mauve_shell = "sterela.ObstacleDetectorShell";
std::string ObstacleDetector::__mauve_core = "sterela.ObstacleDetectorCore";
std::string ObstacleDetector::__mauve_statemachine_json = "{     \"graph\": {         \"directed\": true,         \"type\": \"statemachine\",         \"label\": \"ObstacleDetector\",         \"nodes\": [{                 \"id\": \"0\",                 \"type\": \"state\",                 \"label\": \"RUNNING\"             }],         \"edges\": [{                 \"source\": \"0\",                 \"target\": \"0\",                 \"directed\": true,                 \"label\": \"update\"             }]}     }";
std::string ObstacleDetector::__mauve_monitors_json = "{}";

ObstacleDetector::ObstacleDetector ( const std::string& name )
  : RTT::TaskContext(name, PreOperational)
  , __mauve_property_right_dist( 1.2 )
  , __mauve_property_arm_width( 1.5 )
  , __mauve_property_left_dist( 1.5 )
  , __mauve_property_max_range( 100 )
  , __mauve_period(0), __mauve_priority(0), __mauve_affinity(0), __mauve_deadline(0)
{
  this->addProperty("right_dist", this->__mauve_property_right_dist).doc("in [ 0 ; 10 ]");
  this->addProperty("arm_width", this->__mauve_property_arm_width).doc("in [ 0 ; 10 ]");
  this->addProperty("left_dist", this->__mauve_property_left_dist).doc("in [ 0 ; 10 ]");
  this->addProperty("max_range", this->__mauve_property_max_range).doc("in [ 0 ; 100 ]");
  this->addEventPort("laser_low", this->__mauve_port_laser_low, boost::bind(&ObstacleDetector::__mauve_new_data_callback, this, _1));
  __mauve_hasBeenRead[__mauve_port_laser_low.getName()] = false;
  __mauve_hasNewData[__mauve_port_laser_low.getName()] = false;
  this->addEventPort("laser_high", this->__mauve_port_laser_high, boost::bind(&ObstacleDetector::__mauve_new_data_callback, this, _1));
  __mauve_hasBeenRead[__mauve_port_laser_high.getName()] = false;
  __mauve_hasNewData[__mauve_port_laser_high.getName()] = false;
  this->addPort("distance", this->__mauve_port_distance);
  __mauve_hasBeenWritten[__mauve_port_distance.getName()] = false;

  this->addProperty("period", __mauve_period);
  this->addProperty("priority", __mauve_priority);
  this->addProperty("deadline", __mauve_deadline);
  this->addProperty("affinity", __mauve_affinity);
  this->addProperty("shell", __mauve_shell);
  this->addProperty("core", __mauve_core);
  this->addProperty("statemachine", __mauve_statemachine_json);
  this->addProperty("monitors", __mauve_monitors_json);
  this->addPort("state", __mauve_state_port);
  this->addPort("tick", __mauve_tick_port);
}
bool ObstacleDetector::configureHook() {
return true;
}
bool ObstacleDetector::__mauve_startHook() {
return true;
}
bool ObstacleDetector::startHook() {
  bool r = __mauve_startHook();
  if (r) {
    
    // init variables for PtLTL monitors
    
    // write values in PtLTL ports
    
    
    // write state
std_msgs::String s; s.data = "Running";
    __mauve_state_port.write(s);
  }
  return r;
}
void ObstacleDetector::cleanupHook() {
}
void ObstacleDetector::stopHook() {
}
void ObstacleDetector::__mauve_updateHook() {
double dN = __mauve_property_max_range;
double dW = __mauve_property_max_range;{
{
this->__mauve_var_d = __mauve_property_max_range;
if ((__mauve_read< ::sensor_msgs::LaserScan >(__mauve_port_laser_low,this->__mauve_var_l) == RTT::NewData)) {
{
dN = ::sterela::lttng::rightObstacleDistance(this->__mauve_var_l, __mauve_property_right_dist);
dW = ::sterela::lttng::leftObstacleDistance(this->__mauve_var_l, __mauve_property_left_dist);
this->__mauve_var_d = dN;
};
}
else {
{
;
};
};
if ((__mauve_read< ::sensor_msgs::LaserScan >(__mauve_port_laser_high,this->__mauve_var_l) == RTT::NewData)) {
{
this->__mauve_var_d = ::sterela::lttng::obstacleDistance(this->__mauve_var_l, (__mauve_property_arm_width / 2));
std::cout << "dN: " << dN << "; dW: " << dW << "; __mauve_var_d: " << __mauve_var_d << std::endl;
if (((dN < dW) && (dN < this->__mauve_var_d))) {
{
__mauve_write< ::std_msgs::Float32 >(__mauve_port_distance, ::sterela::lttng::toFloat32(dN));
};
}
else {
{
if (((dW < dN) && (dW < this->__mauve_var_d))) {
{
__mauve_write< ::std_msgs::Float32 >(__mauve_port_distance, ::sterela::lttng::toFloat32(__mauve_property_max_range));
};
}
else {
{
__mauve_write< ::std_msgs::Float32 >(__mauve_port_distance, ::sterela::lttng::toFloat32(this->__mauve_var_d));
};
};
};
};
};
}
else {
{
;
};
};
__mauve_write< ::std_msgs::Float32 >(__mauve_port_distance, ::sterela::lttng::toFloat32(this->__mauve_var_d));
};
}}
void ObstacleDetector::updateHook() {
#ifdef USE_LTTNG
  tracepoint(mauve, component, syscall(SYS_gettid), (char*)this->getName().c_str(), (char*)"begin");
#endif

  // Tick
  std_msgs::Time t; t.data = ros::Time::now(); 
  __mauve_tick_port.write(t);
  // PtLTL monitors checked before the execution of the component 

  // execution of component
  __mauve_updateHook();
  // PtLTL monitors checked after the execution of the component 

  // update ptltl variables for monitors
 
  // write values in PtLTL monitors


  __mauve_resetPorts();
#ifdef USE_LTTNG
  tracepoint(mauve, component, syscall(SYS_gettid), (char*)this->getName().c_str(), (char*)"end");
#endif

// if period = 0 and priority = 0 then permanent execution
if (__mauve_priority == 0 && __mauve_period == 0) this->trigger();
}

bool ObstacleDetector::setPeriod(RTT::Seconds s) {
  bool r = RTT::TaskContext::setPeriod(s);
  if (r) __mauve_period = s * 1000;
  return r;
}
} // namespace sterela
// Orocos Component
ORO_CREATE_COMPONENT(sterela::ObstacleDetector)
