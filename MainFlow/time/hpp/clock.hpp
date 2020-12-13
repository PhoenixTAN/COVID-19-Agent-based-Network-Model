#include "hour.hpp"
#ifndef CLOCK_HPP
#define CLOCK_HPP


class Clock
{
private:
    static Clock* instance;
    HOUR hour;
    int currentHour;
    int currentDay;
    Clock();

public:     
    static Clock* getInstance();
    void nextHour();
    int getCurrentDay();
    HOUR getCurrentHour();
    int getCurrentHourNum();
};

#endif 