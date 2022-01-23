#pragma once

#include <string>
#include "Emulated_system.h"

class Device
{
public:
    enum class OPERATOR { LT, LE, GT, GE, EQ, NE};

    Device(const std::string &name);
    virtual ~Device() = default;

    const std::string &name() const;
    bool state() const;
    void enable();
    void disable();

    void setWorkTime(Time_of_day from, Time_of_day to);
    bool isWorked() const;

private:
    void setState(bool newState);

    bool _state;
    std::string _name;
    Time_of_day _time_from, _time_to;
};
