#include "time_of_day.h"

Time_of_day::Time_of_day() : _hours(0), _minutes(0)
{

}

Time_of_day Time_of_day::fromLocal_time()
{
    time_t rawtime;
    tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    return { timeinfo->tm_hour, timeinfo->tm_min };
}

bool Time_of_day::inInterval(const Time_of_day &from, const Time_of_day &to, const Time_of_day &compareTime)
{
    if(from < to)
    {
        if(compareTime >= from && compareTime < to)
            return true;
    }
    else if(from > to)
    {
        Time_of_day zeroTime;
        if( (compareTime >= from) || ((compareTime >= zeroTime) && compareTime < to))
            return true;
    }
    return false;
}

int Time_of_day::minutesInInterval(const Time_of_day &from, const Time_of_day &to)
{
    if(from < to)
    {
        return (to - from).total_minutes();
    }
    else if(from > to)
    {
        return (24 * 60) - from.total_minutes() - to.total_minutes();
    }

    return 0;
}

Time_of_day::Time_of_day(int h, int m)
{
    _hours = h % 24;
    if(_hours < 0)
        _hours += 24;
    _hours += m / 60;

    _minutes = m % 60;
    if(_minutes < 0)
        _minutes += 60;
}


int Time_of_day::hours() const
{
    return _hours;
}

int Time_of_day::minutes() const
{
    return _minutes;
}

void Time_of_day::setHours(int h)
{
    _hours = h % 24;
    if(_hours < 0)
        _hours += 24;
}

void Time_of_day::setMinutes(int m)
{
    _minutes = m % 60;
    if(_minutes < 0)
        _minutes += 60;
}

void Time_of_day::setFrom_string(std::string str)
{
    int h, m;
    char d;
    std::stringstream ss(str);

    ss >> h;
    ss >> d;
    ss >> m;

    Time_of_day t(h,m);

    this->setHours(t.hours());
    this->setMinutes(t.minutes());
}

std::string Time_of_day::toString() const
{
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << hours() << ":";
    ss << std::setfill('0') << std::setw(2) << minutes();
    return ss.str();
}

bool operator>=(const Time_of_day&lhs, const Time_of_day&rhs)
{
    return lhs.total_minutes() >= rhs.total_minutes();
}

bool operator<=(const Time_of_day&lhs, const Time_of_day&rhs)
{
    return lhs.total_minutes() <= rhs.total_minutes();
}

bool operator==(const Time_of_day&lhs, const Time_of_day&rhs)
{
    return lhs.total_minutes() == rhs.total_minutes();
}

bool operator!=(const Time_of_day&lhs, const Time_of_day&rhs)
{
    return lhs.total_minutes() != rhs.total_minutes();
}

int Time_of_day::total_minutes() const
{
    return _hours * 60 + _minutes;
}

bool operator<(const Time_of_day&lhs, const Time_of_day&rhs)
{
    return lhs.total_minutes() < rhs.total_minutes();
}
bool operator>(const Time_of_day&lhs, const Time_of_day&rhs)
{
    return lhs.total_minutes() > rhs.total_minutes();
}

Time_of_day operator-(const Time_of_day&lhs, const Time_of_day&rhs)
{
    Time_of_day time(0,0);

    int hours = abs(lhs.hours() - rhs.hours()) % 24;
    int minutes = lhs.minutes() - rhs.minutes();

    if(minutes < 0)
    {
        --hours;
        minutes += 60;
    }

    time.setHours(hours);
    time.setMinutes(minutes);

    return time;
}

Time_of_day operator+(const Time_of_day&lhs, const Time_of_day&rhs)
{
    Time_of_day time(0,0);

    time.setHours( (lhs.hours() + rhs.hours()) % 24);
    time.setHours( time.hours() + (lhs.minutes() + rhs.minutes()) / 60 );
    time.setMinutes( (lhs.minutes() + rhs.minutes()) % 60);

    return time;
}
