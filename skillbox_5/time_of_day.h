#pragma once

#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>

class Time_of_day
{
public:
    static Time_of_day fromLocal_time();
    static bool inInterval(const Time_of_day &from, const Time_of_day &to, const Time_of_day &compareTime);
    static int minutesInInterval(const Time_of_day &from, const Time_of_day &to);

    Time_of_day();
    Time_of_day(int h, int m);

    int hours() const;
    int minutes() const;

    int total_minutes() const;

    void setHours(int h);
    void setMinutes(int m);

    void setFrom_string(std::string str);
    std::string toString() const;

    friend Time_of_day operator+(const Time_of_day &lhs, const Time_of_day &rhs);
    friend Time_of_day operator-(const Time_of_day &lhs, const Time_of_day &rhs);
    friend bool operator<(const Time_of_day &lhs, const Time_of_day &rhs);
    friend bool operator>(const Time_of_day &lhs, const Time_of_day &rhs);
    friend bool operator==(const Time_of_day &lhs, const Time_of_day &rhs);
    friend bool operator!=(const Time_of_day &lhs, const Time_of_day &rhs);
    friend bool operator<=(const Time_of_day &lhs, const Time_of_day &rhs);
    friend bool operator>=(const Time_of_day &lhs, const Time_of_day &rhs);

private:
    int _hours;
    int _minutes;
};

