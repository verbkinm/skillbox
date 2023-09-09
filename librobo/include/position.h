#pragma once

#include <iostream>
#include <vector>

class Position
{
public:
    enum DIMENSION_NAME
    {
        DIMENSION_X = 0,
        DIMENSION_Y = 1,
        DIMENSION_Z = 2,
        DIMENSION_W = 4
        // и так далее, если необходимо...
    };

    Position(const std::initializer_list<double> &ld);
    Position(const Position &position);
    ~Position() = default;

    size_t size() const;
    double dimensionValue(size_t dimension) const;
    bool setDimensionValue(size_t dimension, double value);

    // Для часто используемых наименований измерений
    double x() const;
    double y() const;
    double z() const;
    double w() const;

    bool setX(double x);
    bool setY(double y);
    bool setZ(double z);
    bool setW(double w);

    Position operator=(const Position &position);
    friend Position operator+(const Position &lhs, const Position &rhs);
    friend std::ostream &operator<<(std::ostream &out, const Position &pos);

private:
    std::vector<double> _points;
};

