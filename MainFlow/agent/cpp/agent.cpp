//
//  Agent.cpp
//  AgentDesign
//
//  Created by Cayden on 2020/12/10.
//

#include "../hpp/agent.hpp"
#include "../hpp/wellness.hpp"
#include "../../event/hpp/event.hpp"
#include "../../event/hpp/transmission_event.hpp"
#include "../../event/hpp/non_transmission_event.hpp"
#include "../../params.hpp"

#include <cmath>


Agent::Agent(int id)
{
    this->id = id;
    this->wellness = SUSCEPTIBLE;
    this->nextState = INIT;
    this->event = NULL;
    this->stateDurationHours = 0;
};

Agent::Agent() {
    this->id = 0;
    this->wellness = SUSCEPTIBLE;
    this->nextState = INIT;
    this->event = NULL;
    this->stateDurationHours = 0;
}

int Agent::getId()
{
    return this->id;
};

void Agent::setId(int id) {
    this->id = id;
};

WELLNESS Agent::getWellness()
{
    return this->wellness;
};

WELLNESS Agent::getNextState()
{
    return this->nextState;
};

void Agent::executeEvent()
{
    double probability = rand() / double(RAND_MAX);
    // transmission event, if you would be infected
    if(dynamic_cast<TransmissionEvent*>(this->event) && this->wellness == SUSCEPTIBLE) {
        double infectedProbability = 1.0;
        double temp = 1.0;

        temp *= pow(1.0 - INFECTION_RATE_MILD, this->event->getNumOfMild());
        temp *= pow(1.0 - INFECTION_RATE_MILD, this->event->getNumOfSevere());
        temp *= pow(1.0 - INFECTION_RATE_MILD, this->event->getNumOfPresymptomatic());
        temp *= pow(1.0 - INFECTION_RATE_MILD, this->event->getNumOfAsymptomatic());

        infectedProbability -= temp;

        if (probability <= infectedProbability) {
            probability = rand() / (double) RAND_MAX;
            if (probability <= INFECTIOUS_TO_ASYMPTOMATIC) {
                this->setNextState(ASYMPTOMATIC);
            } else {
                this->setNextState(PRESYMPTOMATIC);
                // set incubation period
                
            }
        }

    }else{
        // non transmission event
        switch (this->wellness) {
            case PRESYMPTOMATIC:
                if (probability <= PRESYMPTOMATIC_TO_MILD) {
                    this->setNextState(MILD);
                }
                break;
            case ASYMPTOMATIC:
                if (probability <= ASYMPTOMATIC_TO_RECOVERED){
                    this->setNextState(RECOVERED);
                }
                break;
            case MILD:
                if (probability <= MILD_TO_SEVERE){
                    this->setNextState(SEVERE);
                }else if (probability <= MILD_TO_RECOVERED + MILD_TO_SEVERE){
                    this->setNextState(RECOVERED);
                }
                break;
            case SEVERE:
                if (probability <= SEVERE_TO_DEAD){
                    this->setNextState(DEAD);
                }else if (probability <= SEVERE_TO_RECOVERED + SEVERE_TO_DEAD){
                    this->setNextState(RECOVERED);
                }
                break;
            default:
                break;
        }
    }

    // TODO
    this->event = NULL;
};

void Agent::setNextState(WELLNESS nextState)
{
    this->nextState = nextState;
};

Event* Agent::getEvent()
{
    return this->event;
};

void Agent::setEvent(Event* event)
{
    this->event = event;
};

void Agent::updateWellness()
{
    if (this->nextState != INIT) {
        this->wellness = this->nextState;
        this->nextState = INIT;
        this->stateDurationHours = 1;
    }
};

std::vector<Agent*> Agent::getNeighbors()
{
    return this->neighbors;
};

void Agent::addNeighbor(Agent* agent) {
    this->neighbors.push_back(agent);
}

bool Agent::hasNeighbor(int neighborId) {
    for ( int i = 0; i < this->neighbors.size(); i++ ) {
        if ( neighbors[i]->getId() == neighborId ) {
            return true;
        }
    }
    return false;
}


void Agent::setWellness(WELLNESS state) {
    this->wellness = state;
}
