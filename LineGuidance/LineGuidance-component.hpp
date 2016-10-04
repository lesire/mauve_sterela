
#ifndef STERELA_LINEGUIDANCE_COMPONENT_H_
#define STERELA_LINEGUIDANCE_COMPONENT_H_
#include <rtt/RTT.hpp>
#include "sterela/sterela.hpp"    
namespace sterela {
class LineGuidance : public RTT::TaskContext {
public: LineGuidance(const std::string& name);
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
protected: RTT::OutputPort< ::geometry_msgs::Twist > __mauve_port_command;
protected: virtual bool configureHook();
protected: virtual void stopHook();
protected: virtual void cleanupHook();
protected: virtual bool startHook();
protected: virtual bool __mauve_startHook();
protected: virtual void updateHook();
protected: virtual void __mauve_updateHook();
}; // component LineGuidance
} // namespace sterela
#endif // STERELA_LINEGUIDANCE_COMPONENT_H_