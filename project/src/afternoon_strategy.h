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
#include <string>
#include "src/bus.h"
#include "src/bus_strategy.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief The AfternoonStrategy Class.
  *
  * Calls to \ref AfternoonStrategy create a new AfternoonStrategy instance
  * that is inherited from BusStrategy inherits state from BusStrategy starting
  * at 0.
  * Calls to \ref DeployStrat deploy Busses according to the Afternoon
  * strategy, that is small, regular, large, sequentially.
  */
class AfternoonStrategy : public BusStrategy {
 public:
   /**
    * @brief Generator for AfternoonStrategy
    *
    * @return AfternoonStrategy instance.
    */
  AfternoonStrategy();

  /**
   * @brief Generates a small,then a regular, then a large bus.
   * @param[in] id Bus name.
   * @param[in] out Outbound Route.
   * @param[in] in Inbound Route.

   * @return Bus object with all fields filled
   */
  Bus *DeployStrat(std::string id, Route * out, Route *in);
};
#endif  // SRC_AFTERNOON_STRATEGY_H_
