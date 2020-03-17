/**
* @file regular_bus.h
*
* @copyright2020 Daniel Kunkler, All rights reserved.
*/
#ifndef SRC_REGULAR_BUS_H_
#define SRC_REGULAR_BUS_H_
#include "bus.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;

class RegularBus: public Bus {
  public:
   RegularBus(std::string name, Route * out, Route * in, int capacity = 60,
                        double speed = 1):Bus{name, out, in, capacity, speed}{}
};
#endif  // SRC_REGULAR_BUS_H_
