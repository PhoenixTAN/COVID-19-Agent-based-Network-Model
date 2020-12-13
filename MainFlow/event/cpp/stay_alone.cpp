#include <iostream>
#include "../hpp/stay_alone.hpp"

StayAlone::StayAlone() : NonTransmissionEvent() {}

std::string StayAlone::name() {
  return "stay alone";
}
