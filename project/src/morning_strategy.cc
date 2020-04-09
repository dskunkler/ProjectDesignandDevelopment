/**
*
* @file morning_strategy.cc
*
* @copyright 2020 Daniel Kunkler, All rights reserved
*/

#include <iostream>
#include "src/bus.h"
#include "src/small_bus.h"
#include "src/regular_bus.h"
#include "src/bus_strategy.h"
#include "src/morning_strategy.h"

// You can't initialize static variables in header files so I must do it here.
MorningStrategy::MorningStrategy() {}

Bus *MorningStrategy::DeployStrat(std::string id, Route * out, Route *in) {
  std::cout << "Bus size = ";


  // We want to switch between regular and small busses. state_ will iterate
  // at 0 but will be reset at 1;
  // std::cout <<"MAKING A BUS! FROM MORNING STRAT\n";
  if(state_ == 0) {
    std::cout << "30.\n";
    state_++;
    return new SmallBus(id, out, in);
  }
  else if(state_ == 1) {
    state_ = 0;
    std::cout << "60.\n";
    return new RegularBus(id, out, in);
  }
  else {
    std::cout << "***ERROR INCORRECT state_ IN MORNING STRAT***\n";
    return NULL;
  }

}
