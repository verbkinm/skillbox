#pragma once

#include "position.h"

class IRobot
{
public:
    virtual ~IRobot() = default;

    virtual void setPosition(const Position &position) = 0;
    virtual void setPosition(std::initializer_list<double> ld) = 0;

    virtual void setMotion(const Position &position) = 0;
    virtual void setMotion(std::initializer_list<double> ld) = 0;

    virtual const Position &getPosition() const = 0;
};
