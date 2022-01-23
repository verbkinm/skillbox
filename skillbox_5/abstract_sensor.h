#ifndef ABSTRACT_SENSOR_H
#define ABSTRACT_SENSOR_H

#include <string>

class Abstract_Sensor
{
public:
    Abstract_Sensor(const std::string &name);
    virtual ~Abstract_Sensor();

    const std::string &name() const;

    virtual void printData() const = 0;

private:
    std::string _name;
};

#endif // ABSTRACT_SENSOR_H
