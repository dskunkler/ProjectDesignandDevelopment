/**
 * @file bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <string>
#include <iostream>
#include "src/bus.h"
#include "src/small_bus.h"
#include "src/regular_bus.h"
#include "src/large_bus.h"
#include "src/bus_strategy.h"
#include "src/afternoon_strategy.h"



// You can't initialize static variables in header files so I must do it here.
AfternoonStrategy::AfternoonStrategy() {
}

Bus *AfternoonStrategy::DeployStrat(std::string id, Route * out, Route *in) {
  std::cout << "Bus size = ";

  // We want to switch between small, regular, and large busses. state__ will
  // iterate at 0 but will be reset at 1;
  if (state_ == 0) {
    std::cout << "30.\n";
    // std::cout << "state was " << state_ << std::endl;
    state_++;
    // std::cout << "state is now " << state_ << std::endl;
    return new SmallBus(id, out, in);
  } else if (state_ == 1) {
    // std::cout << "state was " << state_ << std::endl;
    state_++;
    std::cout << "60.\n";
    // std::cout << "state is now " << state_ << std::endl;
    return new RegularBus(id, out, in);
  } else if (state_ == 2) {
    state_ = 0;
    std::cout << "90.\n";
    return new LargeBus(id, out, in);
  } else {
    std::cout << "***ERROR INCORRECT state_ IN AFTERNOON STRAT***\n";
    return NULL;
  }
}
