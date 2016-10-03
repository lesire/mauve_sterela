
#include "sterela/sterela.hpp"
namespace sterela {
// limitSpeedZone2(in cmd: Twist): Twist
::geometry_msgs::Twist
limitSpeedZone2
(const ::geometry_msgs::Twist& cmd) {
	::geometry_msgs::Twist vel = cmd;
	vel.linear.x /= 2.0;
	return vel;
}
} // namespace
