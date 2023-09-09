#pragma once

#include <irobot.h>

class Robot_XD : public IRobot
{
public:
    explicit Robot_XD(const Position &position);
    virtual ~Robot_XD() = default;

    virtual void setPosition(const Position &position) override;
    virtual void setPosition(std::initializer_list<double> ld) override;

    virtual void setMotion(const Position &position) override;
    virtual void setMotion(std::initializer_list<double> ld) override;

    virtual const Position &getPosition() const override;

    const std::string &name() const;

    friend std::ostream &operator<<(std::ostream &out, const Robot_XD &robot);

protected:
    std::string _name;
    Position _position;
};
