#pragma once

#include <string>

class Abstract_Sensor
{
public:
    enum class OPERATOR { LT, LE, GT, GE, EQ, NE };

    Abstract_Sensor(const std::string &name);
    virtual ~Abstract_Sensor() = default;

    const std::string &name() const;

    virtual void checkConditions() = 0;
    virtual void printData() const = 0;

private:
    std::string _name;
};
