
#include "sterela/sterela.hpp"
#ifdef USE_LTTNG
#  define TRACEPOINT_DEFINE
#  define TRACEPOINT_PROBE_DYNAMIC_LINKAGE
#  include <mauve/mauve-tp.h>
#  include <unistd.h>
#  include <sys/syscall.h>
#  include <sys/types.h>
#endif
namespace sterela {
  namespace lttng {
// toDouble(in d: Float32): double
double toDouble (
  const ::std_msgs::Float32& d) {
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "toDouble", (char*)"begin");
#endif

double r = ::sterela::toDouble(d);
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "toDouble", (char*)"end");
#endif

return r;
}
// toFloat32(in d: double): Float32
::std_msgs::Float32 toFloat32 (
  const double& d) {
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "toFloat32", (char*)"begin");
#endif

::std_msgs::Float32 r = ::sterela::toFloat32(d);
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "toFloat32", (char*)"end");
#endif

return r;
}
// obstacleDistance(in s: LaserScan, in lateral_distance: double): double
double obstacleDistance (
  const ::sensor_msgs::LaserScan& s, const double& lateral_distance) {
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "obstacleDistance", (char*)"begin");
#endif

double r = ::sterela::obstacleDistance(s, lateral_distance);
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "obstacleDistance", (char*)"end");
#endif

return r;
}
// min(in a: double, in b: double): double
double min (
  const double& a, const double& b) {
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "min", (char*)"begin");
#endif

double r = ::sterela::min(a, b);
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "min", (char*)"end");
#endif

return r;
}
}} // namespaces