//
//  Agent.hpp
//  AgentDesign
//
//  Created by Cayden on 2020/12/10.
//

#ifndef Agent_hpp
#define Agent_hpp
#include "..\Event\header\Event.h"
#include <stdio.h>
#include <vector>

/* the probability of transfering from susceptible to presymptomatic
if get infected */
const static float INFECTIOUS_TO_PRESYMPTOMATIC = 0.8;
const static float INFECTIOUS_TO_ASYMPTOMATIC = 0.2;

/* It may take 1 ~ 14 days to show symtoms */
const static float PRESYMPTOMATIC_TO_MILD = 0.25;
const static float ASYMPTOMATIC_TO_RECOVERED = 0.3;

const static float MILD_TO_SEVERE = 0.3;
const static float MILD_TO_RECOVERED = 0.3;

const static float SEVERE_TO_RECOVERED = 0.3;
const static float SEVERE_TO_DEAD = 0.03;
const static float SEVERE_TO_MILD = 0.05;

class Agent
{
private:
    int id;
    int wellness;
    int nextState;
    Event event;
    std::vector<Agent> neighbors;
public:
    Agent(int number); // construction function
    int getId();
    int getWellness();
    int getNextState();
    void setNextState(int nextState);
    Event getEvent();
    void setEvent(Event event);
    void executeEvent();
    void updateWellness();
    std::vector<Agent> getNeighbors();
};

#endif /* Agent_hpp */
