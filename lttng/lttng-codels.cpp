
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
// leftObstacleDistance(in s: LaserScan, in lateral_distance: double): double
double leftObstacleDistance (
  const ::sensor_msgs::LaserScan& s, const double& lateral_distance) {
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "leftObstacleDistance", (char*)"begin");
#endif

double r = ::sterela::leftObstacleDistance(s, lateral_distance);
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "leftObstacleDistance", (char*)"end");
#endif

return r;
}
// rightObstacleDistance(in s: LaserScan, in lateral_distance: double): double
double rightObstacleDistance (
  const ::sensor_msgs::LaserScan& s, const double& lateral_distance) {
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "rightObstacleDistance", (char*)"begin");
#endif

double r = ::sterela::rightObstacleDistance(s, lateral_distance);
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "rightObstacleDistance", (char*)"end");
#endif

return r;
}
// limitSpeedZone2(in cmd: Twist): Twist
::geometry_msgs::Twist limitSpeedZone2 (
  const ::geometry_msgs::Twist& cmd) {
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "limitSpeedZone2", (char*)"begin");
#endif

::geometry_msgs::Twist r = ::sterela::limitSpeedZone2(cmd);
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "limitSpeedZone2", (char*)"end");
#endif

return r;
}
// limitSpeedZone1(in cmd: Twist): Twist
::geometry_msgs::Twist limitSpeedZone1 (
  const ::geometry_msgs::Twist& cmd) {
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "limitSpeedZone1", (char*)"begin");
#endif

::geometry_msgs::Twist r = ::sterela::limitSpeedZone1(cmd);
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "limitSpeedZone1", (char*)"end");
#endif

return r;
}
// staightSpeed(in vx: double): Twist
::geometry_msgs::Twist staightSpeed (
  const double& vx) {
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "staightSpeed", (char*)"begin");
#endif

::geometry_msgs::Twist r = ::sterela::staightSpeed(vx);
#ifdef USE_LTTNG
  tracepoint(mauve, codel, syscall(SYS_gettid), "sterela", "staightSpeed", (char*)"end");
#endif

return r;
}
}} // namespaces