#include <iostream>
#include "../hpp/social_activity.hpp"

SocialActivity::SocialActivity() : TransmissionEvent(){}

std::string SocialActivity::name() {
  return "social activity";
}
