#include <cheerp/clientlib.h>
#include "ArrayTyped.h"
using namespace client;
[[cheerp::jsexport]] void sort(ArrayTyped<double>*  arr)
{
auto len{(arr)->get_length()};
for (auto i{(len)-((1*1.0))}; (i)>=((0*1.0)); i--)
{
for (auto j{(1*1.0)}; (j)<=(i); j++)
{
if ((arr->operator[]((j)-((1*1.0))))>(arr->operator[](j)))
{
auto temp{arr->operator[]((j)-((1*1.0)))};
((arr->operator[]((j)-((1*1.0))))=(arr->operator[](j)));
((arr->operator[](j))=(temp));
}
}
}
}

