#include <cheerp/clientlib.h>
#include "ArrayTyped.h"
using namespace client;
[[cheerp::jsexport]] double fibonacci(double num)
{
if ((num)<=((1*1.0)))
return (1*1.0);
return doSum(fibonacci((num)-((1*1.0))), fibonacci((num)-((2*1.0))));
}

