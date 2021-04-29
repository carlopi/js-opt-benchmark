#include <cheerp/clientlib.h>
#include "ArrayTyped.h"
using namespace client;
[[cheerp::jsexport]] double calculatePI(double cycles)
{
auto inside{(0*1.0)};
for (auto i{(0*1.0)}; (i)<(cycles); i++)
{
auto x{(((Math)->random())*((2*1.0)))-((1*1.0))};
auto y{(((Math)->random())*((2*1.0)))-((1*1.0))};
if (((doSum((x)*(x), (y)*(y))))<((1*1.0)))
{
(inside++);
}
}
return (((4*1.0))*(inside))/(cycles);
}

