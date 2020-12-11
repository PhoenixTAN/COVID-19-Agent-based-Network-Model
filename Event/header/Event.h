#include <string>
#ifndef EVENT_H
#define EVENT_H

class Event {
public:
  Event(std::string Name, uint32_t Size);
  std::string getName();
  uint32_t getSize();

private:
  const std::string Name;
  const uint32_t Size;
};
#endif
