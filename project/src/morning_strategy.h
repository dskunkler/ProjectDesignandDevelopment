/**
*
* @file morning_strategy.h
*
* @copyright 2020 Daniel Kunkler, All rights reserved
*/
#ifndef SRC_MORNING_STRATEGY_H_
#define SRC_MORNING_STRATEGY_H_
/*******************************************************************************
  * Includes
******************************************************************************/
#include <string>
#include "src/bus.h"
#include "src/bus_strategy.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class MorningStrategy : public BusStrategy {
 public:
  MorningStrategy();
  Bus *DeployStrat(std::string id, Route * out, Route *in);
};
#endif  // SRC_MORNING_STRATEGY_H_
