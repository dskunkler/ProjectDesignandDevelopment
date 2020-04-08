/**
*
* @file afternoon_strategy.cc
*
* @copyright 2020 Daniel Kunkler, All rights reserved
*/
#ifndef SRC_AFTERNOON_STRATEGY_H_
#define SRC_AFTERNOON_STRATEGY_H_
/*******************************************************************************
  * Includes
******************************************************************************/
#include "src/bus.h"
#include "src/bus_strategy.h"
class AfternoonStrategy : public BusStrategy {
 public:
   AfternoonStrategy();
   Bus *DeployStrat(std::string id, Route * out, Route *in);
};
#endif  // SRC_AFTERNOON_STRATEGY_H_
