#include <iostream>
#ifndef EVENT_H
#define EVENT_H

// P{ i get infect when agent j state is mild} = a
const static float INFECTION_RATE_A = 0.3;
// P{ i get infect when agent j state is severe} = b
const static float INFECTION_RATE_B = 0.3;
// P{ i get infect when agent j state is presymptomatic} = c
const static float INFECTION_RATE_C = 0.4;
// P{ i get infect when agent j state is asymptomatic} = d
const static float INFECTION_RATE_D = 0.4;

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
  void setSusceptible(uint32_t num_of_susceptible);
  void setPresymptomatic(uint32_t num_of_presymptomatic);
  void setAsymptomatic(uint32_t num_of_asymptomatic);
  void setMild(uint32_t num_of_mild);
  void setRecovered(uint32_t num_of_recovered);
  void setSevere(uint32_t num_of_severe);
  void setDead(uint32_t num_of_dead);


private:
  //parameters
  uint32_t num_of_susceptible;
  uint32_t num_of_presymptomatic;
  uint32_t num_of_asymptomatic;
  uint32_t num_of_mild;
  uint32_t num_of_recovered;
  uint32_t num_of_severe;
  uint32_t num_of_dead;
};
#endif
