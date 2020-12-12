//
//  Create by Xueyan
//
#include "../hpp/hour.hpp"
#include "../hpp/clock.hpp"
#include "../../params.hpp"

#include <iostream>

const static int HOURS_NUM_OF_A_DAY = 24;
const static int WORKING_TIME_START = 8;
const static int WORKING_TIME_STOP = 22;

Clock* Clock::instance = NULL;

Clock::Clock()
{
    this->currentDay = 0;
};

Clock* Clock::getInstance(){
    if(instance == NULL){
        instance = new Clock();
    }
    return instance;
};

void Clock::nextHour()
{
    if(this->currentHour + 1 == HOURS_NUM_OF_A_DAY){
        this->currentHour = 0;
        this->currentDay++;

        if(this->currentDay == SIMULATION_DAYS){
            this->currentDay = -1;
        }
        
    }else{
        this->currentHour++;
    }

    if(this->currentHour >= WORKING_TIME_START && this->currentHour < WORKING_TIME_STOP){
        this->hour = WORKING;
    }else{
        this->hour = SLEEPING;
    }
};

int Clock::getCurrentDay()
{
    return this->currentDay;
};

HOUR Clock::getCurrentHour()
{
    return this->hour;
};