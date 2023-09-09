#include "robot_xd.h"

static const char *DEFAULT_NAME = "Robot";

Robot_XD::Robot_XD(const Position &position) :
    _name{DEFAULT_NAME},
    _position{position}
{
}

void Robot_XD::setPosition(const Position &position)
{
    _position = position;

    if (_position.size() != position.size())
        std::cout << "Set position warning! " << _name << " using different dimensions!\n";
}

void Robot_XD::setPosition(std::initializer_list<double> ld)
{
    setPosition(Position{ld});
}

void Robot_XD::setMotion(const Position &position)
{
    _position = _position + position;

    if (_position.size() != position.size())
        std::cout << "Move position warning! " << _name << " using different dimensions!\n";
}

void Robot_XD::setMotion(std::initializer_list<double> ld)
{
    setMotion(Position{ld});
}

const Position &Robot_XD::getPosition() const
{
    return _position;
}

const std::string &Robot_XD::name() const
{
    return _name;
}

std::ostream &operator<<(std::ostream& out, const Robot_XD &robot)
{
    out << robot.name()
        << ":\tdimension size: "
        << robot.getPosition().size() << ' '
        << robot.getPosition();
    return out;
}
