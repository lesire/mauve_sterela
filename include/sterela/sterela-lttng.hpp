
#ifndef STERELA_LTTNG_H_
#define STERELA_LTTNG_H_
#include <sys/time.h>
#include <sys/resource.h>
namespace sterela {
  namespace lttng {
  // toDouble(in d: Float32): double
  double toDouble (const ::std_msgs::Float32& d); 
  // toFloat32(in d: double): Float32
  ::std_msgs::Float32 toFloat32 (const double& d); 
  // obstacleDistance(in s: LaserScan, in lateral_distance: double): double
  double obstacleDistance (const ::sensor_msgs::LaserScan& s, const double& lateral_distance); 
  // min(in a: double, in b: double): double
  double min (const double& a, const double& b); 
}} // namespaces
#endif // STERELA_LTTNG_H_