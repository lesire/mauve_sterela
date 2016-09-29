
#include <rtt/Component.hpp>
#include "SafePilot-component.hpp"
#ifdef USE_LTTNG
#  define TRACEPOINT_DEFINE
#  define TRACEPOINT_PROBE_DYNAMIC_LINKAGE
#  include <mauve/mauve-tp.h>
#  include <unistd.h>
#  include <sys/syscall.h>
#  include <sys/types.h>
#endif
namespace sterela {std::string SafePilot::__mauve_shell = "sterela.SafePilotShell";
std::string SafePilot::__mauve_core = "sterela.SafePilotCore";
std::string SafePilot::__mauve_statemachine_json = "{     \"graph\": {         \"directed\": true,         \"type\": \"statemachine\",         \"label\": \"SafePilot\",         \"nodes\": [{                 \"id\": \"0\",                 \"type\": \"state\",                 \"label\": \"Zone3\"             },{                 \"id\": \"1\",                 \"type\": \"state\",                 \"label\": \"Zone2\"             },{                 \"id\": \"2\",                 \"type\": \"state\",                 \"label\": \"Zone1\"             }],         \"edges\": [{                 \"source\": \"0\",                 \"target\": \"2\",                 \"directed\": true,                 \"label\": \"t1\"             },{                 \"source\": \"0\",                 \"target\": \"1\",                 \"directed\": true,                 \"label\": \"t2\"             },{                 \"source\": \"1\",                 \"target\": \"2\",                 \"directed\": true,                 \"label\": \"t1\"             },{                 \"source\": \"1\",                 \"target\": \"0\",                 \"directed\": true,                 \"label\": \"t3\"             },{                 \"source\": \"2\",                 \"target\": \"0\",                 \"directed\": true,                 \"label\": \"t3\"             },{                 \"source\": \"2\",                 \"target\": \"1\",                 \"directed\": true,                 \"label\": \"t2\"             }]     }     }";
std::string SafePilot::__mauve_monitors_json = "{}";

SafePilot::SafePilot ( const std::string& name )
  : RTT::TaskContext(name, PreOperational)
  , __mauve_property_dist_zone2( 3 )
  , __mauve_property_dist_zone1( 1 )
  , __mauve_period(0), __mauve_priority(0), __mauve_affinity(0), __mauve_deadline(0)
{
  this->addProperty("dist_zone2", this->__mauve_property_dist_zone2).doc("in [ 0 ; 10 ]");
  this->addProperty("dist_zone1", this->__mauve_property_dist_zone1).doc("in [ 0 ; 1 ]");
  this->addEventPort("obstacle_distance", this->__mauve_port_obstacle_distance, boost::bind(&SafePilot::__mauve_new_data_callback, this, _1));
  __mauve_hasBeenRead[__mauve_port_obstacle_distance.getName()] = false;
  __mauve_hasNewData[__mauve_port_obstacle_distance.getName()] = false;
  this->addEventPort("desired_command", this->__mauve_port_desired_command, boost::bind(&SafePilot::__mauve_new_data_callback, this, _1));
  __mauve_hasBeenRead[__mauve_port_desired_command.getName()] = false;
  __mauve_hasNewData[__mauve_port_desired_command.getName()] = false;
  this->addPort("command", this->__mauve_port_command);
  __mauve_hasBeenWritten[__mauve_port_command.getName()] = false;

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
bool SafePilot::configureHook() {
return true;
}
bool SafePilot::__mauve_startHook() {
return true;
}
bool SafePilot::startHook() {
  bool r = __mauve_startHook();
  if (r) {
    __mauve_state_machine.__mauve_state = StateMachine::__mauve_state_Zone3;
__mauve_Zone3_entry();
std_msgs::String state_machine_state;
state_machine_state.data = "Zone3";
__mauve_state_port.write(state_machine_state);

    // init variables for PtLTL monitors
    
    // write values in PtLTL ports
    
    
    // write state
std_msgs::String s; s.data = "Running";
    __mauve_state_port.write(s);
  }
  return r;
}
void SafePilot::cleanupHook() {
}
void SafePilot::stopHook() {
}
void SafePilot::__mauve_updateHook() {
switch (__mauve_state_machine.__mauve_state) {
case StateMachine::__mauve_state_Zone3: {
  __mauve_Zone3_run();
  if (__mauve_Zone3_t1_guard()) {
    __mauve_Zone3_exit();
    __mauve_Zone3_t1_effect();
    __mauve_state_machine.__mauve_state = StateMachine::__mauve_state_Zone1;
    std_msgs::String state_machine_state;
state_machine_state.data = "Zone1";
__mauve_state_port.write(state_machine_state);
    __mauve_Zone1_entry();
    break;
  }
  if (__mauve_Zone3_t2_guard()) {
    __mauve_Zone3_exit();
    __mauve_Zone3_t2_effect();
    __mauve_state_machine.__mauve_state = StateMachine::__mauve_state_Zone2;
    std_msgs::String state_machine_state;
state_machine_state.data = "Zone2";
__mauve_state_port.write(state_machine_state);
    __mauve_Zone2_entry();
    break;
  }
  __mauve_Zone3_handle();
  std_msgs::String state_machine_state;
state_machine_state.data = "Zone3";
__mauve_state_port.write(state_machine_state);
  break;
}case StateMachine::__mauve_state_Zone2: {
  __mauve_Zone2_run();
  if (__mauve_Zone2_t1_guard()) {
    __mauve_Zone2_exit();
    __mauve_Zone2_t1_effect();
    __mauve_state_machine.__mauve_state = StateMachine::__mauve_state_Zone1;
    std_msgs::String state_machine_state;
state_machine_state.data = "Zone1";
__mauve_state_port.write(state_machine_state);
    __mauve_Zone1_entry();
    break;
  }
  if (__mauve_Zone2_t3_guard()) {
    __mauve_Zone2_exit();
    __mauve_Zone2_t3_effect();
    __mauve_state_machine.__mauve_state = StateMachine::__mauve_state_Zone3;
    std_msgs::String state_machine_state;
state_machine_state.data = "Zone3";
__mauve_state_port.write(state_machine_state);
    __mauve_Zone3_entry();
    break;
  }
  __mauve_Zone2_handle();
  std_msgs::String state_machine_state;
state_machine_state.data = "Zone2";
__mauve_state_port.write(state_machine_state);
  break;
}case StateMachine::__mauve_state_Zone1: {
  __mauve_Zone1_run();
  if (__mauve_Zone1_t3_guard()) {
    __mauve_Zone1_exit();
    __mauve_Zone1_t3_effect();
    __mauve_state_machine.__mauve_state = StateMachine::__mauve_state_Zone3;
    std_msgs::String state_machine_state;
state_machine_state.data = "Zone3";
__mauve_state_port.write(state_machine_state);
    __mauve_Zone3_entry();
    break;
  }
  if (__mauve_Zone1_t2_guard()) {
    __mauve_Zone1_exit();
    __mauve_Zone1_t2_effect();
    __mauve_state_machine.__mauve_state = StateMachine::__mauve_state_Zone2;
    std_msgs::String state_machine_state;
state_machine_state.data = "Zone2";
__mauve_state_port.write(state_machine_state);
    __mauve_Zone2_entry();
    break;
  }
  __mauve_Zone1_handle();
  std_msgs::String state_machine_state;
state_machine_state.data = "Zone1";
__mauve_state_port.write(state_machine_state);
  break;
}}
}
void SafePilot::updateHook() {
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
void SafePilot::__mauve_Zone3_entry() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone3", "entry", (char*)"begin");
#endif

  {
__mauve_write< ::geometry_msgs::TwistStamped >(__mauve_port_command, this->__mauve_var_cmd);
}
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone3", "entry", (char*)"end");
#endif

}
void SafePilot::__mauve_Zone3_exit() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone3", "exit", (char*)"begin");
#endif

  
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone3", "exit", (char*)"end");
#endif

}
void SafePilot::__mauve_Zone3_run() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone3", "run", (char*)"begin");
#endif

  {
{
__mauve_read< ::geometry_msgs::TwistStamped >(__mauve_port_desired_command,this->__mauve_var_cmd);
__mauve_read< ::std_msgs::Float32 >(__mauve_port_obstacle_distance,__mauve_state_machine.__mauve_var_d);
};
}
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone3", "run", (char*)"end");
#endif

}
void SafePilot::__mauve_Zone3_handle() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone3", "handle", (char*)"begin");
#endif

  {
__mauve_write< ::geometry_msgs::TwistStamped >(__mauve_port_command, this->__mauve_var_cmd);
}
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone3", "handle", (char*)"end");
#endif

}
void SafePilot::__mauve_Zone3_t1_effect() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t1", "effect", (char*)"begin");
#endif

  
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t1", "effect", (char*)"end");
#endif

}
bool SafePilot::__mauve_Zone3_t1_guard() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t1", "guard", (char*)"begin");
#endif

  bool r = (::sterela::lttng::toDouble(__mauve_state_machine.__mauve_var_d) < __mauve_property_dist_zone1);
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t1", "guard", (char*)"end");
#endif

  return r;
}
void SafePilot::__mauve_Zone3_t2_effect() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t2", "effect", (char*)"begin");
#endif

  
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t2", "effect", (char*)"end");
#endif

}
bool SafePilot::__mauve_Zone3_t2_guard() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t2", "guard", (char*)"begin");
#endif

  bool r = (::sterela::lttng::toDouble(__mauve_state_machine.__mauve_var_d) < __mauve_property_dist_zone2);
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t2", "guard", (char*)"end");
#endif

  return r;
}
void SafePilot::__mauve_Zone2_entry() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone2", "entry", (char*)"begin");
#endif

  {
__mauve_write< ::geometry_msgs::TwistStamped >(__mauve_port_command, this->__mauve_var_cmd);
}
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone2", "entry", (char*)"end");
#endif

}
void SafePilot::__mauve_Zone2_exit() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone2", "exit", (char*)"begin");
#endif

  
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone2", "exit", (char*)"end");
#endif

}
void SafePilot::__mauve_Zone2_run() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone2", "run", (char*)"begin");
#endif

  {
{
__mauve_read< ::geometry_msgs::TwistStamped >(__mauve_port_desired_command,this->__mauve_var_cmd);
__mauve_read< ::std_msgs::Float32 >(__mauve_port_obstacle_distance,__mauve_state_machine.__mauve_var_d);
};
}
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone2", "run", (char*)"end");
#endif

}
void SafePilot::__mauve_Zone2_handle() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone2", "handle", (char*)"begin");
#endif

  {
__mauve_write< ::geometry_msgs::TwistStamped >(__mauve_port_command, this->__mauve_var_cmd);
}
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone2", "handle", (char*)"end");
#endif

}
void SafePilot::__mauve_Zone2_t1_effect() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t1", "effect", (char*)"begin");
#endif

  
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t1", "effect", (char*)"end");
#endif

}
bool SafePilot::__mauve_Zone2_t1_guard() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t1", "guard", (char*)"begin");
#endif

  bool r = (::sterela::lttng::toDouble(__mauve_state_machine.__mauve_var_d) < __mauve_property_dist_zone1);
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t1", "guard", (char*)"end");
#endif

  return r;
}
void SafePilot::__mauve_Zone2_t3_effect() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t3", "effect", (char*)"begin");
#endif

  
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t3", "effect", (char*)"end");
#endif

}
bool SafePilot::__mauve_Zone2_t3_guard() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t3", "guard", (char*)"begin");
#endif

  bool r = (::sterela::lttng::toDouble(__mauve_state_machine.__mauve_var_d) > __mauve_property_dist_zone2);
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t3", "guard", (char*)"end");
#endif

  return r;
}
void SafePilot::__mauve_Zone1_entry() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone1", "entry", (char*)"begin");
#endif

  {
__mauve_write< ::geometry_msgs::TwistStamped >(__mauve_port_command, this->__mauve_var_cmd);
}
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone1", "entry", (char*)"end");
#endif

}
void SafePilot::__mauve_Zone1_exit() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone1", "exit", (char*)"begin");
#endif

  
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone1", "exit", (char*)"end");
#endif

}
void SafePilot::__mauve_Zone1_run() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone1", "run", (char*)"begin");
#endif

  {
{
__mauve_read< ::geometry_msgs::TwistStamped >(__mauve_port_desired_command,this->__mauve_var_cmd);
__mauve_read< ::std_msgs::Float32 >(__mauve_port_obstacle_distance,__mauve_state_machine.__mauve_var_d);
};
}
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone1", "run", (char*)"end");
#endif

}
void SafePilot::__mauve_Zone1_handle() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone1", "handle", (char*)"begin");
#endif

  {
__mauve_write< ::geometry_msgs::TwistStamped >(__mauve_port_command, this->__mauve_var_cmd);
}
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "Zone1", "handle", (char*)"end");
#endif

}
void SafePilot::__mauve_Zone1_t3_effect() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t3", "effect", (char*)"begin");
#endif

  
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t3", "effect", (char*)"end");
#endif

}
bool SafePilot::__mauve_Zone1_t3_guard() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t3", "guard", (char*)"begin");
#endif

  bool r = (::sterela::lttng::toDouble(__mauve_state_machine.__mauve_var_d) > __mauve_property_dist_zone2);
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t3", "guard", (char*)"end");
#endif

  return r;
}
void SafePilot::__mauve_Zone1_t2_effect() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t2", "effect", (char*)"begin");
#endif

  
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t2", "effect", (char*)"end");
#endif

}
bool SafePilot::__mauve_Zone1_t2_guard() {
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t2", "guard", (char*)"begin");
#endif

  bool r = (::sterela::lttng::toDouble(__mauve_state_machine.__mauve_var_d) > __mauve_property_dist_zone1);
#ifdef USE_LTTNG
  tracepoint(mauve, statemachine, syscall(SYS_gettid), (char*)this->getName().c_str(), "t2", "guard", (char*)"end");
#endif

  return r;
}

bool SafePilot::setPeriod(RTT::Seconds s) {
  bool r = RTT::TaskContext::setPeriod(s);
  if (r) __mauve_period = s * 1000;
  return r;
}
} // namespace sterela
// Orocos Component
ORO_CREATE_COMPONENT(sterela::SafePilot)
