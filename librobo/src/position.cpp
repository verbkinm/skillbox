#include "position.h"

Position::Position(const std::initializer_list<double> &ld)
{
    // Должно быть минимум одно измерение (точка)
    if (ld.size() == 0)
        _points.push_back(0);
    else
        _points = ld;

    _points.shrink_to_fit();
}

Position::Position(const Position &position)
{
    // Если текущий Position не имеет измерений, то полностью переписываем данные из нового position
    if (_points.size() == 0)
    {
        _points = position._points;
        return;
    }

    // Любому измерению можно присвоить данные из другого измерения, но только входящие в его видимость.
    // К примеру, 1D видит первое (x) измерение из всех вышестоящих измерений. 2D видит x и y и т.д.
    // Так же и в обратную сторону. К примеру, 3D видит x и y из 2D и x из 1D
    // По этому, необходимо определить меньшее измерение перед записью данных в текущий Position
    for (size_t i = 0; i < std::min(size(), position.size()); ++i)
        _points.at(i) = position._points.at(i);
}

Position Position::operator=(const Position &position)
{
    for (size_t i = 0; i < std::min(size(), position.size()); ++i)
        _points.at(i) = position._points.at(i);

    return *this;
}

size_t Position::size() const
{
    return _points.size();
}

double Position::dimensionValue(size_t dimension) const
{
    try
    {
        return _points.at(dimension);
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Using a non-existent dimension number: "
                  << dimension << '\n';

    }

    return NAN;
}

bool Position::setDimensionValue(size_t dimension, double value)
{
    try
    {
        _points.at(dimension) = value;
        return true;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Using a non-existent dimension number: "
                  << dimension << '\n';

    }

    return false;
}

double Position::x() const
{
    return dimensionValue(DIMENSION_X);
}

bool Position::setX(double x)
{
    return setDimensionValue(DIMENSION_X, x);
}

double Position::y() const
{
    return dimensionValue(DIMENSION_Y);
}

bool Position::setY(double y)
{
    return setDimensionValue(DIMENSION_Y, y);
}

double Position::z() const
{
    return dimensionValue(DIMENSION_Z);
}

bool Position::setZ(double z)
{
    return setDimensionValue(DIMENSION_Z, z);
}

double Position::w() const
{
    return dimensionValue(DIMENSION_W);
}

bool Position::setW(double w)
{
    return setDimensionValue(DIMENSION_W, w);
}

Position operator+(const Position &lhs, const Position &rhs)
{
    // Для создания нового Position используется большее измерение
    Position result(lhs.size() > rhs.size() ? lhs : rhs);

    for (size_t i = 0; i < std::min(lhs.size(), rhs.size()); ++i)
        result._points.at(i) = rhs._points.at(i) + lhs._points.at(i);

    return result;
}

std::ostream &operator<<(std::ostream &out, const Position &pos)
{
    out << '(';
    for (size_t i = 0; i < pos.size(); ++i)
        out << ' ' << pos.dimensionValue(i) << "; ";
    out << ')';

    return out;
}
