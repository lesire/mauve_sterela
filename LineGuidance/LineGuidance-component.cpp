
#include <rtt/Component.hpp>
#include "LineGuidance-component.hpp"
#ifdef USE_LTTNG
#  define TRACEPOINT_DEFINE
#  define TRACEPOINT_PROBE_DYNAMIC_LINKAGE
#  include <mauve/mauve-tp.h>
#  include <unistd.h>
#  include <sys/syscall.h>
#  include <sys/types.h>
#endif
namespace sterela {std::string LineGuidance::__mauve_shell = "sterela.LineGuidanceShell";
std::string LineGuidance::__mauve_core = "sterela.LineGuidanceCore";
std::string LineGuidance::__mauve_statemachine_json = "{     \"graph\": {         \"directed\": true,         \"type\": \"statemachine\",         \"label\": \"LineGuidance\",         \"nodes\": [{                 \"id\": \"0\",                 \"type\": \"state\",                 \"label\": \"RUNNING\"             }],         \"edges\": [{                 \"source\": \"0\",                 \"target\": \"0\",                 \"directed\": true,                 \"label\": \"update\"             }]}     }";
std::string LineGuidance::__mauve_monitors_json = "{}";

LineGuidance::LineGuidance ( const std::string& name )
  : RTT::TaskContext(name, PreOperational)
  , __mauve_period(0), __mauve_priority(0), __mauve_affinity(0), __mauve_deadline(0)
{
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
bool LineGuidance::configureHook() {
return true;
}
bool LineGuidance::__mauve_startHook() {
return true;
}
bool LineGuidance::startHook() {
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
void LineGuidance::cleanupHook() {
}
void LineGuidance::stopHook() {
}
void LineGuidance::__mauve_updateHook() {
{
__mauve_write< ::geometry_msgs::Twist >(__mauve_port_command, ::sterela::lttng::staightSpeed(1));
}}
void LineGuidance::updateHook() {
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

bool LineGuidance::setPeriod(RTT::Seconds s) {
  bool r = RTT::TaskContext::setPeriod(s);
  if (r) __mauve_period = s * 1000;
  return r;
}
} // namespace sterela
// Orocos Component
ORO_CREATE_COMPONENT(sterela::LineGuidance)
