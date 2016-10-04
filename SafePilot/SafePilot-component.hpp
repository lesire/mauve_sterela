
#ifndef STERELA_SAFEPILOT_COMPONENT_H_
#define STERELA_SAFEPILOT_COMPONENT_H_
#include <rtt/RTT.hpp>
#include "sterela/sterela.hpp"    
namespace sterela {
class SafePilot : public RTT::TaskContext {
public: SafePilot(const std::string& name);
private: int __mauve_period;
private: int __mauve_priority;
private: int __mauve_deadline;
private: int __mauve_affinity;
private: static std::string __mauve_shell;
private: static std::string __mauve_core;
private: static std::string __mauve_statemachine_json;
private: static std::string __mauve_monitors_json;
protected: virtual bool setPeriod(RTT::Seconds);
private: RTT::OutputPort<std_msgs::String> __mauve_state_port;
private: RTT::OutputPort<std_msgs::Time> __mauve_tick_port;
protected: double __mauve_property_base_width;
protected: double __mauve_property_arm_width;
protected: double __mauve_property_dist_zone2;
protected: double __mauve_property_dist_zone1;
private: 
  std::map<std::string, bool> __mauve_hasNewData;
  std::map<std::string, bool> __mauve_hasBeenRead;
  std::map<std::string, bool> __mauve_hasBeenWritten;
  void __mauve_new_data_callback(RTT::base::PortInterface* p) {
    __mauve_hasNewData[p->getName()] = true;
  };
  void __mauve_resetPorts() {
    std::map<std::string, bool>::iterator it;
    for (it = __mauve_hasNewData.begin(); it != __mauve_hasNewData.end(); ++it)
      it->second = false;
    for (it = __mauve_hasBeenRead.begin(); it != __mauve_hasBeenRead.end(); ++it)
      it->second = false;
    for (it = __mauve_hasBeenWritten.begin(); it != __mauve_hasBeenWritten.end(); ++it)
      it->second = false;
  };
  template <typename T> RTT::FlowStatus __mauve_read(RTT::InputPort<T> &p, T &d) {
    __mauve_hasBeenRead[p.getName()] = true;
    return p.read(d);
  };
  template <typename T> void __mauve_write(RTT::OutputPort<T> &p, T d) {
    __mauve_hasBeenWritten[p.getName()] = true;
    p.write(d);
  };
protected: RTT::InputPort< ::geometry_msgs::Twist > __mauve_port_desired_command;
protected: RTT::InputPort< ::std_msgs::Float32 > __mauve_port_obstacle_distance;
protected: RTT::OutputPort< ::geometry_msgs::Twist > __mauve_port_command;
private: ::geometry_msgs::Twist __mauve_var_cmd;
protected: virtual bool configureHook();
protected: virtual void stopHook();
protected: virtual void cleanupHook();
protected: virtual bool startHook();
protected: virtual bool __mauve_startHook();
protected: virtual void updateHook();
protected: virtual void __mauve_updateHook();
class StateMachine {
::std_msgs::Float32 __mauve_var_d;
StateMachine() {
};
enum State {
__mauve_state_Zone3,
__mauve_state_Zone2,
__mauve_state_Zone1};
State __mauve_state;
friend class SafePilot;
};
inline void __mauve_Zone3_entry();
inline void __mauve_Zone3_exit();
inline void __mauve_Zone3_run();
inline void __mauve_Zone3_handle();
inline void __mauve_Zone3_t1_effect();
inline bool __mauve_Zone3_t1_guard();
inline void __mauve_Zone3_t2_effect();
inline bool __mauve_Zone3_t2_guard();
inline void __mauve_Zone2_entry();
inline void __mauve_Zone2_exit();
inline void __mauve_Zone2_run();
inline void __mauve_Zone2_handle();
inline void __mauve_Zone2_t1_effect();
inline bool __mauve_Zone2_t1_guard();
inline void __mauve_Zone2_t3_effect();
inline bool __mauve_Zone2_t3_guard();
inline void __mauve_Zone1_entry();
inline void __mauve_Zone1_exit();
inline void __mauve_Zone1_run();
inline void __mauve_Zone1_handle();
inline void __mauve_Zone1_t3_effect();
inline bool __mauve_Zone1_t3_guard();
inline void __mauve_Zone1_t2_effect();
inline bool __mauve_Zone1_t2_guard();
StateMachine __mauve_state_machine;
}; // component SafePilot
} // namespace sterela
#endif // STERELA_SAFEPILOT_COMPONENT_H_