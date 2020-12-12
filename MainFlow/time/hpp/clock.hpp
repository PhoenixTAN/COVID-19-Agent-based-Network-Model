#include "hour.hpp"
#ifndef CLOCK_HPP
#define CLOCK_HPP

class Clock
{
private:
    static Clock* instance;
private:
    HOUR hour;
    int currentHour;
    int currentDay;
    Clock();
public:     
    static Clock* getInstance();
public:
    void nextHour();
    int getCurrentDay();
    HOUR getCurrentHour();
};

#endif 