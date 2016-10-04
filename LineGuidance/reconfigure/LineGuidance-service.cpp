
#include <orocos/rtt_dynamic_reconfigure/server.h>
#include <sterela/LineGuidanceConfig.h>
using namespace sterela;
namespace rtt_dynamic_reconfigure {

template <>
struct Updater< LineGuidanceConfig > {
  static bool propertiesFromConfig(LineGuidanceConfig &config, 
    uint32_t level, RTT::PropertyBag &bag) 
  {

    return true;
  }
  static bool configFromProperties(LineGuidanceConfig &config, RTT::PropertyBag &bag) 
  {

    return true;
  }
};
} // namespace
RTT_DYNAMIC_RECONFIGURE_SERVICE_PLUGIN(LineGuidanceConfig, "LineGuidance_reconfigure")
