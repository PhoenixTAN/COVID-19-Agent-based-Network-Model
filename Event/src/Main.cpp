#include <iostream>
#include "../header/Event.h" //when you want to import an class, you shoud import the .h file of that class
#include "../header/TransmissionEvent.h"
#include "../header/NonTransmissionEvent.h"
#include "../header/Meeting.h"
#include "../header/SocialActivity.h"
#include "../header/StayAlone.h"

int main() {
  Event event1 = Event("CS591", 40);
  Event event2 = TransmissionEvent("CS592", 39);
  Event event3 = NonTransmissionEvent("CS593", 38);
  Event event4 = Meeting("CS594", 37);
  TransmissionEvent event5 = SocialActivity("CS595", 36);
  StayAlone event6 = StayAlone("CS596", 35);
  std::cout << event1.getName() << "    " <<event1.getSize() << std::endl;
  std::cout << event2.getName() << "    " <<event2.getSize() << std::endl;
  std::cout << event3.getName() << "    " <<event3.getSize() << std::endl;
  std::cout << event4.getName() << "    " <<event4.getSize() << std::endl;
  std::cout << event5.getName() << "    " <<event5.getSize() << std::endl;
  std::cout << event6.getName() << "    " <<event6.getSize() << std::endl;
  return 0;
}
