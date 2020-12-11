#include <string>
#include "Event.h"
#ifndef NONTRANSMISSIONEVENT_H
#define NONTRANSMISSIONEVENT_H

class NonTransmissionEvent : public Event{
public:
  NonTransmissionEvent(std::string Name, uint32_t size);
};
#endif
