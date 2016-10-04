
#include "sterela/sterela.hpp"
namespace sterela {
// staightSpeed(in vx: double): Twist
::geometry_msgs::Twist
staightSpeed
(const double& vx) {
	::geometry_msgs::Twist vel;
	vel.linear.x = vx;
	return vel;
}
} // namespace
