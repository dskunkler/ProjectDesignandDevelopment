/**
*
* @file noon_strategy.cc
*
* @copyright 2020 Daniel Kunkler, All rights reserved
*/
#ifndef SRC_NOON_STRATEGY_H_
#define SRC_NOON_STRATEGY_H_
/*******************************************************************************
  * Includes
******************************************************************************/
#include "src/bus.h"
#include "src/bus_strategy.h"
class NoonStrategy : public BusStrategy {
 public:
   NoonStrategy();
   Bus *DeployStrat(std::string id, Route * out, Route *in);
};
#endif  // SRC_NOON_STRATEGY_H
