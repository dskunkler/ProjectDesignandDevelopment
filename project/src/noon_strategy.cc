/**
 *
 * @filename noon_strategy.cc
 * @copyright Daniel Kunkler 2020
 */
/*******************************************************************************
   * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include "src/bus.h"
#include "src/regular_bus.h"
#include "src/large_bus.h"
#include "src/bus_strategy.h"
#include "src/noon_strategy.h"
#include "src/i_observer.h"

// You can't initialize static variables in header files so I must do it here.
NoonStrategy::NoonStrategy() {}

Bus *NoonStrategy::DeployStrat(std::string id, Route * out, Route *in) {
  std::cout << "Bus size = ";
  // We want to switch between regular and large busses. state_ will iterate
  // at 0 but will be reset at 1;
  // std::cout << "MAKING A BUS! FROM NOON STRAT\n";
  if (state_ == 0) {
    state_++;
    std::cout << "60.\n";
    return new RegularBus(id, out, in);
  } else if (state_ == 1) {
      state_ = 0;
      std::cout << "90.\n";
      return new LargeBus(id, out, in);
  } else {
      std::cout << "***ERROR INCORRECT state_ IN NOON STRAT***\n";
      return NULL;
  }
}
