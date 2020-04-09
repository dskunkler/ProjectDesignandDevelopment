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
#include <string>
#include "src/bus.h"
#include "src/bus_strategy.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief The NoonStrategy Class.
  *
  * Calls to \ref NoonStrategy create a new NoonStrategy instance that is
  * inherited from NoonStrategy inherits state from NoonStrategy starting
  * at 0.
  * Calls to \ref DeployStrat deploy Busses according to the Afternoon
  * strategy, that is small, regular, large, sequentially.
  */
class NoonStrategy : public BusStrategy {
 public:
   /**
    * @brief Generator for NoonStrategy
    *
    * @return NoonStrategy instance.
    */
  NoonStrategy();

  /**
   * @brief Generates a regular then a large sized bus.
   * @param[in] id Bus name.
   * @param[in] out Outbound Route.
   * @param[in] in Inbound Route.

   * @return Bus object with all fields filled
   */
  Bus *DeployStrat(std::string id, Route * out, Route *in);
};
#endif  // SRC_NOON_STRATEGY_H_
