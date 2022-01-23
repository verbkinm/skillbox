#pragma once

#include <list>

#include "device.h"

class Smart_Light : public Device
{
public:
    Smart_Light(const std::string &name, uint color_temperature = 5000);

    struct INTERVAL_COLOR
    {
        Time_of_day time_from, time_to;
        uint color_from, color_to;
    };

    void addIntervalColor(const INTERVAL_COLOR &interval);
    void clearIntervalColor();
    int currentColorTemp() const;

private:
    uint _color_temperature_default;
    std::list<INTERVAL_COLOR> _intervals_color;
};