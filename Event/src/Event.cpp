#include <iostream>
#include <string>
#include "../header/Event.h"

Event::Event(std::string Name, uint32_t Size) :
Name(Name),
Size(Size)
{}

std::string Event::getName() {
  return Name;
}

uint32_t Event::getSize() {
  return Size;
}
