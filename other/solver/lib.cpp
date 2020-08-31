#include "lib.h"
#include <chrono>
#include <iostream>

namespace slvr
{

namespace lib
{

unsigned long long fixed_time_in_usec()
{
    unsigned long long res;
    auto t0 = std::chrono::steady_clock::now().time_since_epoch();
    std::chrono::microseconds t_sec = std::chrono::duration_cast<std::chrono::microseconds>(t0);
    res = t_sec.count();
    return res;
}

} // namespace lib

} // namespace slvr

