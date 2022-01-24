#include "device.h"

Device::Device(const std::string &name) : _state(false), _name(name)
{
    setWorkTime({0, 0}, {23, 59});
}

const std::string &Device::name() const
{
    return _name;
}

bool Device::state() const
{
    return _state;
}

void Device::enable()
{
    setState(true);
}

void Device::disable()
{
    setState(false);
}

void Device::setWorkTime(Time_of_day from, Time_of_day to)
{
    _time_from = from;
    _time_to = to;
}

bool Device::isWorked() const
{
    if(Time_of_day::inInterval(_time_from, _time_to, Emulated_system::_system_time()))
        return true;
    return false;
}

void Device::setState(bool newState)
{
    if(isWorked() && newState != _state)
    {
        _state = newState;
        std::cout << "Device: \"" << _name << "\" is " << (_state ? "on" : "off") << std::endl;
    }
}
