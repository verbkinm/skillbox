#pragma once

#include "time_of_day.h"

class Emulated_system
{
public:
    static Time_of_day _system_time();
    static void set_system_time(Time_of_day time);
};
