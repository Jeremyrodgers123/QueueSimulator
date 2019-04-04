//
// Created by Jason Tran on 2019-03-29.
//

#ifndef ASSIGNMENT16_EVENT_H
#define ASSIGNMENT16_EVENT_H

#include <optional>

class Event {
 public:
  Event(int timeOfEvent, int eventType, int duration);
  friend bool operator<(const Event& lhs, const Event& rhs) { return lhs.timeOfEvent > rhs.timeOfEvent; }
  int timeOfEvent; // in seconds
  int eventType; //0 for arrival, 1 for
  int duration; // in seconds
  int line;

 private:


};


#endif //ASSIGNMENT16_EVENT_H
