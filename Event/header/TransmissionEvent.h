#include <string>
#include "Event.h"
#ifndef TRANSMISSIONEVENT_H
#define TRANSMISSIONEVENT_H

class TransmissionEvent : public Event{
public:
  TransmissionEvent(std::string Name, uint32_t size);
};
#endif
