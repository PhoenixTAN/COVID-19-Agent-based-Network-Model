#include "../header/Event.h"

//getters
uint32_t Event::getSusceptible() {
  return Susceptible;
}
uint32_t Event::getPresymptomatic() {
  return Presymptomatic;
}
uint32_t Event::getAsymptomatic() {
  return Asymptomatic;
}
uint32_t Event::getMild() {
  return Mild;
}
uint32_t Event::getRecovered() {
  return Recovered;
}
uint32_t Event::getSevere() {
  return Severe;
}
uint32_t Event::getDead() {
  return Dead;
}

//setters
void Event::setSusceptible(uint32_t Susceptible) {
  this->Susceptible = Susceptible;
}
void Event::setPresymptomatic(uint32_t Presymptomatic) {
  this->Presymptomatic = Presymptomatic;
}
void Event::setAsymptomatic(uint32_t Asymptomatic) {
  this->Asymptomatic = Asymptomatic;
}
void Event::setMild(uint32_t Mild) {
  this->Mild = Mild;
}
void Event::setRecovered(uint32_t Recovered) {
  this->Recovered = Recovered;
}
void Event::setSevere(uint32_t Severe) {
  this->Severe = Severe;
}
void Event::setDead(uint32_t Dead) {
  this->Dead = Dead;
}
