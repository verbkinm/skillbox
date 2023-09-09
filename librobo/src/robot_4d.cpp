#include "robot_4d.h"

Robot_4D::Robot_4D() : Robot_XD{Position{0, 0, 0, 0}}
{
}

Robot_4D::Robot_4D(const std::string &name) : Robot_XD{Position{0, 0, 0, 0}}
{
    _name = name;
}
