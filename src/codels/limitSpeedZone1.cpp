
#include "sterela/sterela.hpp"
namespace sterela {
// limitSpeedZone1(in cmd: Twist): Twist
::geometry_msgs::Twist
limitSpeedZone1
(const ::geometry_msgs::Twist& cmd) {
	::geometry_msgs::Twist vel = cmd;
	vel.linear.x = std::min(0.0, vel.linear.x);
	return vel;
}
} // namespace
