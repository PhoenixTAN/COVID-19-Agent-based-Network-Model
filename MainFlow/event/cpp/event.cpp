#include <string>
#include "../hpp/event.hpp"
#include "../../agent/hpp/wellness.hpp"

// getters
int Event::getNumOfSusceptible() {
    return numOfSusceptible;
}
int Event::getNumOfPresymptomatic() {
    return numOfPresymptomatic;
}
int Event::getNumOfAsymptomatic() {
    return numOfAsymptomatic;
}
int Event::getNumOfMild() {
    return numOfMild;
}
int Event::getNumOfRecovered() {
    return numOfRecovered;
}
int Event::getNumOfSevere() {
    return numOfSevere;
}
int Event::getNumOfDead() {
    return numOfDead;
}

// setNumOfters
void Event::setNumOfSusceptible(int numOfSusceptible) {
    this->numOfSusceptible = numOfSusceptible;
}

void Event::setNumOfPresymptomatic(int numOfPresymptomatic) {
    this->numOfPresymptomatic = numOfPresymptomatic;
}

void Event::setNumOfAsymptomatic(int numOfAsymptomatic) {
    this->numOfAsymptomatic = numOfAsymptomatic;
}

void Event::setNumOfMild(int numOfMild) {
    this->numOfMild = numOfMild;
}

void Event::setNumOfRecovered(int numOfRecovered) {
    this->numOfRecovered = numOfRecovered;
}

void Event::setNumOfSevere(int numOfSevere) {
    this->numOfSevere = numOfSevere;
}

void Event::setNumOfDead(int numOfDead) {
    this->numOfDead = numOfDead;
}

void Event::increment(WELLNESS wellness){
    switch (wellness)
    {
        case ASYMPTOMATIC:
            this->numOfAsymptomatic++;
            break;
        case PRESYMPTOMATIC:
            this->numOfPresymptomatic++;
            break;
        case MILD:
            this->numOfMild++;
            break;
        case SEVERE:
            this->numOfSevere++;
            break;
        default:
            break;
    }
}


