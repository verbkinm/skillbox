#include "Emulated_system.h"

static int _h, _m;

Time_of_day Emulated_system::_system_time()
{
    return {_h, _m};
}

void Emulated_system::set_system_time(Time_of_day time)
{
    _h = time.hours();
    _m = time.minutes();
}
