#include <string>
#include "TransmissionEvent.h"
#ifndef SOCIALACTIVITY_H
#define SOCIALACTIVITY_H

class SocialActivity : public TransmissionEvent{
public:
  SocialActivity(std::string Name, uint32_t Size);
};
#endif
