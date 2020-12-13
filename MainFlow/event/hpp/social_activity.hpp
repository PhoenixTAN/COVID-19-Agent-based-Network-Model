#ifndef SOCIALACTIVITY_H
#define SOCIALACTIVITY_H
#include "transmission_event.hpp"

class SocialActivity : public TransmissionEvent{
public:
  SocialActivity();
  virtual std::string name();
};
#endif
