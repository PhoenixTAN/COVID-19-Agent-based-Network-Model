#ifndef EVENT_H
#define EVENT_H
#include <string>
#include "../../params.hpp"
#include "../../agent/hpp/wellness.hpp"

class Event {
public:
    // getters
    int getNumOfSusceptible();
    int getNumOfPresymptomatic();
    int getNumOfAsymptomatic();
    int getNumOfMild();
    int getNumOfRecovered();
    int getNumOfSevere();
    int getNumOfDead();

    // setNumOfters
    void setNumOfSusceptible(int numOfSusceptible);
    void setNumOfPresymptomatic(int numOfPresymptomatic);
    void setNumOfAsymptomatic(int numOfAsymptomatic);
    void setNumOfMild(int numOfMild);
    void setNumOfRecovered(int numOfRecovered);
    void setNumOfSevere(int numOfSevere);
    void setNumOfDead(int numOfDead);
    void increment(WELLNESS wellness);

    virtual std::string name();


private:
    // parameters
    int numOfSusceptible;
    int numOfPresymptomatic;
    int numOfAsymptomatic;
    int numOfMild;
    int numOfRecovered;
    int numOfSevere;
    int numOfDead;

    /* virtual function to support dynamic_cast */
    virtual void poly();

};
#endif
