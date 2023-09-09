#include "robot_1d.h"

Robot_1D::Robot_1D() : Robot_XD{Position{0}}
{
}

Robot_1D::Robot_1D(const std::string &name) : Robot_XD{Position{0}}
{
    _name = name;
}
