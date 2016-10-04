
#ifndef STERELA_CODELS_H_
#define STERELA_CODELS_H_
namespace sterela {
// toDouble(in d: Float32): double
double toDouble (const ::std_msgs::Float32& d); 
// toFloat32(in d: double): Float32
::std_msgs::Float32 toFloat32 (const double& d); 
// min(in a: double, in b: double): double
double min (const double& a, const double& b); 
// obstacleDistance(in s: LaserScan, in lateral_distance: double): double
double obstacleDistance (const ::sensor_msgs::LaserScan& s, const double& lateral_distance); 
// leftObstacleDistance(in s: LaserScan, in lateral_distance: double): double
double leftObstacleDistance (const ::sensor_msgs::LaserScan& s, const double& lateral_distance); 
// rightObstacleDistance(in s: LaserScan, in lateral_distance: double): double
double rightObstacleDistance (const ::sensor_msgs::LaserScan& s, const double& lateral_distance); 
// limitSpeedZone2(in cmd: Twist): Twist
::geometry_msgs::Twist limitSpeedZone2 (const ::geometry_msgs::Twist& cmd); 
// limitSpeedZone1(in cmd: Twist): Twist
::geometry_msgs::Twist limitSpeedZone1 (const ::geometry_msgs::Twist& cmd); 
// staightSpeed(in vx: double): Twist
::geometry_msgs::Twist staightSpeed (const double& vx); 
} // namespace
#endif // STERELA_CODELS_H_