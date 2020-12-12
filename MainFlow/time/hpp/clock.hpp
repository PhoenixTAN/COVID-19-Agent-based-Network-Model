#include "hour.hpp"
#ifndef CLOCK_HPP
#define CLOCK_HPP

class Clock
{
private:
    Hour* hours;
    WELLNESS wellness;
    WELLNESS nextState;
    Event event;
    std::vector<Agent> neighbors;
public:
    Agent(int number); // construction function
    int getId();
    WELLNESS getWellness();
    WELLNESS getNextState();
    void setNextState(WELLNESS nextState);
    Event getEvent();
    void setEvent(Event event);
    void executeEvent();
    void updateWellness();
    std::vector<Agent> getNeighbors();
};

#endif /* Agent_hpp */