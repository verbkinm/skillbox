#include "robot_2d.h"

Robot_2D::Robot_2D() : Robot_XD{Position{0, 0}}
{
}

Robot_2D::Robot_2D(const std::string &name) : Robot_XD{Position{0, 0}}
{
    _name = name;
}
