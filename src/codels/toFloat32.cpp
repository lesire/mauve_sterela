
#include "sterela/sterela.hpp"
namespace sterela {
// toFloat32(in d: double): Float32
::std_msgs::Float32
toFloat32
(const double& d) {
  ::std_msgs::Float32 f;
  f.data = d;
  return f;
}
} // namespace
