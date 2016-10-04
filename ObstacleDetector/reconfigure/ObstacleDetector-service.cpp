
#include <orocos/rtt_dynamic_reconfigure/server.h>
#include <sterela/ObstacleDetectorConfig.h>
using namespace sterela;
namespace rtt_dynamic_reconfigure {

template <>
struct Updater< ObstacleDetectorConfig > {
  static bool propertiesFromConfig(ObstacleDetectorConfig &config, 
    uint32_t level, RTT::PropertyBag &bag) 
  {

    setProperty< double >("right_dist", bag, config.right_dist);

    setProperty< double >("arm_width", bag, config.arm_width);

    setProperty< double >("left_dist", bag, config.left_dist);

    setProperty< double >("max_range", bag, config.max_range);

    return true;
  }
  static bool configFromProperties(ObstacleDetectorConfig &config, RTT::PropertyBag &bag) 
  {

    getProperty< double >("right_dist", bag, config.right_dist);

    getProperty< double >("arm_width", bag, config.arm_width);

    getProperty< double >("left_dist", bag, config.left_dist);

    getProperty< double >("max_range", bag, config.max_range);

    return true;
  }
};
} // namespace
RTT_DYNAMIC_RECONFIGURE_SERVICE_PLUGIN(ObstacleDetectorConfig, "ObstacleDetector_reconfigure")
