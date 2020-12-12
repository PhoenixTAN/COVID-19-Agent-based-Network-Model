#include "../hpp/event.h"

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

void poly () {}
