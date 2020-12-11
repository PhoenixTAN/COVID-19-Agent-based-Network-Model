#include <iostream>
#ifndef EVENT_H
#define EVENT_H

class Event {
public:
  //getters
  uint32_t getSusceptible();
  uint32_t getPresymptomatic();
  uint32_t getAsymptomatic();
  uint32_t getMild();
  uint32_t getRecovered();
  uint32_t getSevere();
  uint32_t getDead();

  //setters
  void setSusceptible(uint32_t Susceptible);
  void setPresymptomatic(uint32_t Presymptomatic);
  void setAsymptomatic(uint32_t Asymptomatic);
  void setMild(uint32_t Mild);
  void setRecovered(uint32_t Recovered);
  void setSevere(uint32_t Severe);
  void setDead(uint32_t Dead);


private:
  //parameters
  uint32_t Susceptible;
  uint32_t Presymptomatic;
  uint32_t Asymptomatic;
  uint32_t Mild;
  uint32_t Recovered;
  uint32_t Severe;
  uint32_t Dead;
};
#endif
