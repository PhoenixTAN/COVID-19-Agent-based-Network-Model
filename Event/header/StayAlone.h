#include <string>
#include "NonTransmissionEvent.h"
#ifndef STAYALONE_H
#define STAYALONE_H

class StayAlone : public NonTransmissionEvent{
public:
  StayAlone(std::string Name, uint32_t Size);
};
#endif
