//
// Created by Jason Tran on 2019-03-29.
//
#include <optional>

#include "Event.h"



Event::Event(int timeOfEvent, EventType eventType, int duration) {
  this->timeOfEvent = timeOfEvent; // in seconds
  this->eventType = eventType;
  this->duration = duration; // in seconds
}
