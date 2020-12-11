#include "../header/Event.h"

//getters
uint32_t Event::getSusceptible() {
  return num_of_susceptible;
}
uint32_t Event::getPresymptomatic() {
  return num_of_presymptomatic;
}
uint32_t Event::getAsymptomatic() {
  return num_of_asymptomatic;
}
uint32_t Event::getMild() {
  return num_of_mild;
}
uint32_t Event::getRecovered() {
  return num_of_recovered;
}
uint32_t Event::getSevere() {
  return num_of_severe;
}
uint32_t Event::getDead() {
  return num_of_dead;
}

//setters
void Event::setSusceptible(uint32_t num_of_susceptible) {
  this->num_of_susceptible = num_of_susceptible;
}
void Event::setPresymptomatic(uint32_t num_of_presymptomatic) {
  this->num_of_presymptomatic = num_of_presymptomatic;
}
void Event::setAsymptomatic(uint32_t num_of_asymptomatic) {
  this->num_of_asymptomatic = num_of_asymptomatic;
}
void Event::setMild(uint32_t num_of_mild) {
  this->num_of_mild = num_of_mild;
}
void Event::setRecovered(uint32_t num_of_recovered) {
  this->num_of_recovered = num_of_recovered;
}
void Event::setSevere(uint32_t num_of_severe) {
  this->num_of_severe = num_of_severe;
}
void Event::setDead(uint32_t num_of_dead) {
  this->num_of_dead = num_of_dead;
}
