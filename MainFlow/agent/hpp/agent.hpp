//
//  Agent.hpp
//  AgentDesign
//
//  Created by Cayden on 2020/12/10.
//

#ifndef AGENT_HPP
#define AGENT_HPP
#include "../../event/hpp/event.hpp"
#include "wellness.hpp"
#include <vector>



class Agent
{
private:
    int id;
    WELLNESS wellness;
    WELLNESS nextState;
    Event* event;
    std::vector<Agent*> neighbors;
    int stateDurationHours;      // hours, the duration of the current state
    int incubationPeriod;   // days
    void setIncubationPeriod();
    int mildPeriod;     // days
    void setMildPeriod();
public:
    Agent(int number); // constructor
    Agent();    // default constructor
    int getId();
    void setId(int id);
    WELLNESS getWellness();
    WELLNESS getNextState();
    void setNextState(WELLNESS nextState);
    Event* getEvent();
    void setEvent(Event* event);
    void executeEvent();
    void setWellness(WELLNESS state);
    void updateWellness();
    std::vector<Agent*> getNeighbors();
    void addNeighbor(Agent* agent);
    bool hasNeighbor(int neighborId);
};

#endif /* Agent_hpp */
