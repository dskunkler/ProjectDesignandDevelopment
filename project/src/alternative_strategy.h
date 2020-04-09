/**
*
* @file morning_strategy.h
*
* @copyright 2020 Daniel Kunkler, All rights reserved
*/
#ifndef SRC_ALTERNATIVE_STRATEGY_H_
#define SRC_ALTERNATIVE_STRATEGY_H_
/*******************************************************************************
  * Includes
******************************************************************************/
#include <string>
#include "src/bus.h"
#include "src/bus_strategy.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class AlternativeStrategy : public BusStrategy {
 public:
  // the alternative strategy only puts out small busses so state is irrelevant
  AlternativeStrategy();
  Bus *DeployStrat(std::string id, Route * out, Route *in) override;
};
#endif  // SRC_ALTERNATIVE_STRATEGY_H_
