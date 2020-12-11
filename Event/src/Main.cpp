#include <iostream>
#include "../header/Event.h" //when you want to import an class, you shoud import the .h file of that class
#include "../header/TransmissionEvent.h"
#include "../header/NonTransmissionEvent.h"
#include "../header/Meeting.h"
#include "../header/SocialActivity.h"
#include "../header/StayAlone.h"

int main() {
  Event event1 = Event();
  Event event2 = TransmissionEvent();
  Event event3 = NonTransmissionEvent();
  Event event4 = Meeting();
  TransmissionEvent event5 = SocialActivity();
  StayAlone event6 = StayAlone();

  event3.setDead(10);
  event3.setMild(20);

  std::cout << event3.getDead() << "    " <<event3.getMild() << std::endl;
  return 0;
}
