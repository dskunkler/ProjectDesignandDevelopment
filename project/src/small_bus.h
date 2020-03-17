/**
* @file small_bus.h
*
* @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
*/
#ifndef SRC_SMALL_BUS_H_
#define SRC_SMALL_BUS_H_

#include "bus.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;

class SmallBus: public Bus {
  public:
   SmallBus(std::string name, Route * out, Route * in, int capacity = 30,
                        double speed = 1):Bus{name, out, in, capacity, speed}{}
};
#endif  // SRC_SMALL_BUS_H_
