#include <cheerp/clientlib.h>
#include "ArrayTyped.h"

using namespace client;

bool isPrime(double p)
{
    auto upper{ (Math)->sqrt(p) };
    for (auto i{ (2 * 1.0) }; (i) <= (upper); i++)
    {
        if (((int)(p) % (int)(i)) == ((0 * 1.0)))
        {
            return false;
        }
    }
    return true;
}

[[cheerp::jsexport]] double prime(double n)
{
    if ((n) < ((1 * 1.0)))
    {
        // This was a throw...
    }
    auto count{ (0 * 1.0) };
    auto result{ (1 * 1.0) };
    while ((count) < (n))
    {
        (result++);
        if (isPrime(result))
        {
            (count++);
        }
    }
    return result;
}
