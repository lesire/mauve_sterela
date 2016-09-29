
#include <orocos/rtt_dynamic_reconfigure/server.h>
#include <sterela/ObstacleDetectorConfig.h>
using namespace sterela;
namespace rtt_dynamic_reconfigure {

template <>
struct Updater< ObstacleDetectorConfig > {
  static bool propertiesFromConfig(ObstacleDetectorConfig &config, 
    uint32_t level, RTT::PropertyBag &bag) 
  {

    setProperty< double >("base_width", bag, config.base_width);

    setProperty< double >("max_range", bag, config.max_range);

    return true;
  }
  static bool configFromProperties(ObstacleDetectorConfig &config, RTT::PropertyBag &bag) 
  {

    getProperty< double >("base_width", bag, config.base_width);

    getProperty< double >("max_range", bag, config.max_range);

    return true;
  }
};
} // namespace
RTT_DYNAMIC_RECONFIGURE_SERVICE_PLUGIN(ObstacleDetectorConfig, "ObstacleDetector_reconfigure")
