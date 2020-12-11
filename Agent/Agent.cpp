//
//  Agent.cpp
//  AgentDesign
//
//  Created by Cayden on 2020/12/10.
//

#include "Agent.hpp"
#include "Enum.hpp"

Agent::Agent(int id)
{
    this->id = id;
    this->wellness = SUSCEPTIBLE;
    this->nextState = -1;
};

int Agent::getId()
{
    return this->id;
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
