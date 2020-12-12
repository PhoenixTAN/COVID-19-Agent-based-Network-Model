//
//  Agent.cpp
//  AgentDesign
//
//  Created by Cayden on 2020/12/10.
//

#include "..\hpp\Agent.hpp"
#include "..\hpp\Enum.hpp"
#include "..\..\Event\hpp\Event.h"
#include "..\..\Event\hpp\TransmissionEvent.h"
#include "..\..\Event\hpp\NonTransmissionEvent.h"
#include "..\params.hpp"

#include <cmath>
#include <ctime>

Agent::Agent(int id)
{
    this->id = id;
    this->wellness = SUSCEPTIBLE;
    this->nextState = INIT;
};

int Agent::getId()
{
    return this->id;
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
    srand(time(NULL));
    float probability = rand();
    if(TransmissionEvent* te = dynamic_cast<TransmissionEvent*>(this->event) && this->wellness == SUSCEPTIBLE) {
        float infected_probability = 1.0;
        float temp = 1.0;
        
        pow(1.0 - INFECTION_RATE_MILD, this->event.)
        for(int i = 0; i < this->event.Mild; i++)
            temp *= 1.0 - INFECTION_RATE_A;
        for(int i = 0; i < this->event.Severe; i++)
            temp *= 1.0 - INFECTION_RATE_B;
        for(int i = 0; i < this->event.Presymptomatic; i++)
            temp *= 1.0 - INFECTION_RATE_C;
        for(int i = 0; i < this->event.Asymptomatic; i++)
            temp *= 1.0 - INFECTION_RATE_D;
        infected_probability -= temp;
        if(probability <= infected_probability) {
            probability = rand();
            if (probability <= INFECTIOUS_TO_ASYMPTOMATIC)
                this->setNextState(ASYMPTOMATIC);
            else if(probability <= INFECTIOUS_TO_ASYMPTOMATIC + INFECTIOUS_TO_PRESYMPTOMATIC)
                this->setNextState(PRESYMPTOMATIC);
        }
    }else{
        switch (this->wellness) {
            case PRESYMPTOMATIC:
                if (probability <= PRESYMPTOMATIC_TO_MILD) {
                    this->setNextState(MILD);
                }
                break;
            case ASYMPTOMATIC:
                if(probability <= ASYMPTOMATIC_TO_RECOVERED){
                    this->setNextState(RECOVERED);
                }
                break;
            case MILD:
                if(probability <= MILD_TO_SEVERE){
                    this->setNextState(SEVERE);
                }else if(probability <= MILD_TO_RECOVERED + MILD_TO_SEVERE){
                    this->setNextState(RECOVERED);
                }
                break;
            case SEVERE:
                if(probability <= SEVERE_TO_DEAD){
                    this->setNextState(DEAD);
                }else if(probability <= SEVERE_TO_RECOVERED + SEVERE_TO_DEAD){
                    this->setNextState(RECOVERED);
                }else if(probability <= SEVERE_TO_RECOVERED + SEVERE_TO_DEAD + SEVERE_TO_MILD){
                    this->setNextState(MILD);
                }
                break;
            default:
                break;
        }
    }
};

void Agent::setNextState(int nextState)
{
    this->nextState = nextState;
};

Event Agent::getEvent()
{
    return this->event;
};

void Agent::setEvent(Event event)
{
    this->event = event;
};

void Agent::updateWellness()
{
    if (this->nextState != -1) {
        this->wellness = this->nextState;
        this->nextState = -1;
    }
};

std::vector<Agent> Agent::getNeighbors()
{
    return this->neighbors;
};
