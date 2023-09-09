#include "robot_3d.h"

Robot_3D::Robot_3D() : Robot_XD{Position{0, 0, 0}}
{
}

Robot_3D::Robot_3D(const std::string &name) : Robot_XD{Position{0, 0, 0}}
{
    _name = name;
}
