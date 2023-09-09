#include "abstract_sensor.h"

Abstract_Sensor::Abstract_Sensor(const std::string &name) : _name(name)
{

}

const std::string &Abstract_Sensor::name() const
{
    return _name;
}
