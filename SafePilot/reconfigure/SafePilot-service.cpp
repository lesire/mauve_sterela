
#include <orocos/rtt_dynamic_reconfigure/server.h>
#include <sterela/SafePilotConfig.h>
using namespace sterela;
namespace rtt_dynamic_reconfigure {

template <>
struct Updater< SafePilotConfig > {
  static bool propertiesFromConfig(SafePilotConfig &config, 
    uint32_t level, RTT::PropertyBag &bag) 
  {

    setProperty< double >("dist_zone2", bag, config.dist_zone2);

    setProperty< double >("dist_zone1", bag, config.dist_zone1);

    return true;
  }
  static bool configFromProperties(SafePilotConfig &config, RTT::PropertyBag &bag) 
  {

    getProperty< double >("dist_zone2", bag, config.dist_zone2);

    getProperty< double >("dist_zone1", bag, config.dist_zone1);

    return true;
  }
};
} // namespace
RTT_DYNAMIC_RECONFIGURE_SERVICE_PLUGIN(SafePilotConfig, "SafePilot_reconfigure")
