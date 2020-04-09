/**
*
* @file bus_strategy.h
*
* @copyright 2020 Daniel Kunkler, All rights reserved
*/

#ifndef SRC_BUS_STRATEGY_H_
#define SRC_BUS_STRATEGY_H_
/*******************************************************************************
  * Includes
******************************************************************************/
#include <string>
#include "src/bus.h"

class BusStrategy {
 public:
  BusStrategy() {}
  static int state_;
  virtual Bus *DeployStrat(std::string id, Route * out, Route *in) = 0;
};
#endif  // SRC_BUS_STRATEGY_H_
