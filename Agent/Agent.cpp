//
//  Agent.cpp
//  AgentDesign
//
//  Created by Cayden on 2020/12/10.
//

#include "Agent.hpp"
#include "Enum.hpp"

Agent::Agent(int number)
{
    this->number = number;
    this->wellness = SUSCEPTIBLE;
    this->nextState = -1;
};

int Agent::getNumber()
{
    return this->number;
};

int Agent::getWellness()
{
    return this->wellness;
};

int Agent::getNextState()
{
    return this->nextState;
};

void Agent::executeEvent()
{
    
}

void Agent::updateWellness()
{
    if (this->nextState != -1) {
        this->wellness = this->nextState;
        this->nextState = -1;
    }
};

std::vector<Agent> Agent::getNeigbhours()
{
    return this->neigbhours;
};
