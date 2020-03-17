/**
* @file large_bus.h
*
* @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
*/
#ifndef SRC_LARGE_BUS_H_
#define SRC_LARGE_BUS_H_

#include "bus.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;

class LargeBus: public Bus {
  public:
   LargeBus(std::string name, Route * out, Route * in, int capacity = 90,
                        double speed = 1):Bus{name, out, in, capacity, speed}{}
};
#endif  // SRC_LARGE_BUS_H
