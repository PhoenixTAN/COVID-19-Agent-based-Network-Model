#include <iostream>
#include "../hpp/meeting.hpp"


Meeting::Meeting() : TransmissionEvent()
{}

std::string Meeting::name() {
  return "meeting";
}
