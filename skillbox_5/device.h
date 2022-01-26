#pragma once

#include <string>
#include <iostream>
#include <list>
#include <memory>

#include "Emulated_system.h"

class Device
{
public:
    Device(const std::string &name);
    virtual ~Device() = default;

    const std::string &name() const;
    bool state() const;
    void enable();
    void disable();

    void setWorkTime(const Time_of_day &from, const Time_of_day &to);
    bool isWorked() const;

    virtual void setState(bool newState);

protected:
    bool _state;
    std::string _name;
    Time_of_day _time_from, _time_to;

};
