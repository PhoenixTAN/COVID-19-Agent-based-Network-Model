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
#include <iostream>
#include <random>

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
        temp *= pow(1.0 - INFECTION_RATE_SEVERE, this->event->getNumOfSevere());
        temp *= pow(1.0 - INFECTION_RATE_PRESYMPTOMATIC, this->event->getNumOfPresymptomatic());
        temp *= pow(1.0 - INFECTION_RATE_ASYMPTOMATIC, this->event->getNumOfAsymptomatic());

        infectedProbability -= temp;

        if (probability <= infectedProbability) {
            probability = rand() / (double) RAND_MAX;
            if (probability <= INFECTIOUS_TO_ASYMPTOMATIC) {
                this->setNextState(ASYMPTOMATIC);
                this->setAsymptomaticPeriod();
            } else {
                this->setNextState(PRESYMPTOMATIC);
                this->setIncubationPeriod(false);
            }
        }

    }else{
        // non transmission event
        switch (this->wellness) {
            case PRESYMPTOMATIC:
                if ( this->stateDurationHours / 24 >= this->incubationPeriod) {
                    this->setNextState(MILD);
                    this->setMildPeriod();
                }
                break;
            case ASYMPTOMATIC:
                if ( this->stateDurationHours / 24 >= this->asymptomaticPeroid ) {
                    this->setNextState(RECOVERED);
                }
                break;
            case MILD:
                if ( this->stateDurationHours / 24 >= this->mildPeriod ) {
                    if (probability <= MILD_TO_SEVERE){
                        this->setNextState(SEVERE);
                        this->setSeverePeriod();
                    } else {
                        this->setNextState(RECOVERED);
                    }
                }
                break;
            case SEVERE:
                if ( this->stateDurationHours / 24 >= this->severePeriod ) {
                    if ( probability <= SEVERE_TO_DEAD ){
                        this->setNextState(DEAD);
                    }else {
                        this->setNextState(RECOVERED);
                    }
                }
                
                break;
            default:
                break;
        }
    }

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
    if (this->nextState != INIT && this->wellness != this->nextState) {
        this->wellness = this->nextState;
        this->nextState = INIT;
        this->stateDurationHours = 1;
    }
    else {
        this->stateDurationHours++;
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

/**
 * @Author Ziqi Tan
 * @param bool default: if true, use the INCUBATION_EXPECTATION as the incubation period.
 *                      if false, use normal distribution.
*/
void Agent::setIncubationPeriod(bool defaultPeriod) {

    if (defaultPeriod) {
        this->incubationPeriod = INCUBATION_EXPECTATION;
        return ;
    }
    
    std::normal_distribution<float> N(INCUBATION_EXPECTATION, INCUBATION_VARIANCE);

    int incubationDays = std::lround(N(DEFAULT_RANDOM_ENGINE));
    while ( incubationDays < MIN_INCUBATION_PERIOD && incubationDays > MAX_INCUBATION_PEROID ) {
        incubationDays = std::lround(N(DEFAULT_RANDOM_ENGINE));
    }
    
    this->incubationPeriod = incubationDays;
}

void Agent::setMildPeriod() {
    int mildDays = rand() % (MAX_MILD_PERIOD - MIN_MILD_PERIOD) + MIN_MILD_PERIOD;
    this->mildPeriod = mildDays;
}

void Agent::setSeverePeriod() {
    int severeDays = rand() % (MAX_SEVERE_PERIOD - MIN_MILD_PERIOD ) + MIN_SEVERE_PERIOD;
    this->severePeriod = severeDays;
}

void Agent::setAsymptomaticPeriod() {
    int asymptomaticDays = rand() % (MAX_ASYMPTOMATIC_PERIOD - MIN_ASYMPTOMATIC_PEROID) + MIN_ASYMPTOMATIC_PEROID;
    this->asymptomaticPeroid = asymptomaticDays;
}
