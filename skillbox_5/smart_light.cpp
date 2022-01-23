#include "smart_light.h"

Smart_Light::Smart_Light(const std::string &name, uint color_temperature) : Device(name),
    _color_temperature_default(color_temperature)
{

}

void Smart_Light::addIntervalColor(const INTERVAL_COLOR &interval)
{
    _intervals_color.push_back(interval);
}

void Smart_Light::clearIntervalColor()
{
    _intervals_color.clear();
}

int Smart_Light::currentColorTemp() const
{
    Time_of_day currentTime = Emulated_system::_system_time();

    for (const auto& interval : _intervals_color)
    {
        if(Time_of_day::inInterval(interval.time_from, interval.time_to, currentTime))
        {
            if(interval.color_from == interval.color_to)
                return interval.color_from;

            int old_min = 0;
            int old_max = Time_of_day::minutesInInterval(interval.time_from, interval.time_to);

            int new_min = interval.color_from;
            int new_max = interval.color_to;

            int old_range = old_max - old_min;
            int new_range = new_max - new_min;

            int old;

            if(interval.time_from < interval.time_to)
            {
                old = std::abs(interval.time_from.total_minutes() - currentTime.total_minutes()/* - interval.time_to.total_minutes()*/);
                int converted = ((old - old_min) * new_range / old_range) + new_min;
                return converted;
            }
            else if(interval.time_from > interval.time_to)
            {
                if(currentTime >= interval.time_from)
                {
                    old = currentTime.total_minutes() - interval.time_from.total_minutes();
                    int converted = ((old - old_min) * new_range / old_range) + new_min;
                    return converted;
                }
                else if(currentTime < interval.time_to)
                {
                    old = std::abs((24 * 60) - interval.time_from.total_minutes() - interval.time_to.total_minutes() - currentTime.total_minutes());
                    int converted = ((old - old_min) * new_range / old_range) + new_min;
                    return converted;
                }
            }
        }
    }

    return _color_temperature_default;
}
