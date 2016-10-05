
#include "sterela/sterela.hpp"
namespace sterela {
// rightObstacleDistance(in s: LaserScan, in lateral_distance: double): double
double
rightObstacleDistance
(const ::sensor_msgs::LaserScan& s, const double& lateral_distance) {
	double d = s.range_max;

		for (int i = 0; i < s.ranges.size(); i++) {
			double r = s.ranges[i];

			if (r < s.range_min or r > s.range_max) continue;

			double angle = s.angle_min + (s.angle_max - s.angle_min) * i / s.ranges.size();
			double y = r * sin(angle);

			if (y > 0) continue;

			if (abs(y) > lateral_distance) continue;

			// else, really an obstacle
			d = min(d, r);
		}
		//std::cout << "obstacle at " << d << std::endl;
		return d;
}
} // namespace
