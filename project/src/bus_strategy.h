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
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief The BusStrategy Class.
  *
  * Calls to \ref BusStrategy create a new BusStrategy instance
  * that is inherited from BusStrategy inherits state from BusStrategy starting
  * at 0.
  * Calls to \ref DeployStrat deploy Busses according to the Afternoon
  * strategy, that is small, regular, large, sequentially.
  */
class BusStrategy {
 public:
   /**
    * @brief Generator for BusStrategy
    *
    * @return BusStrategy instance.
    */
  BusStrategy() {}
  static int state_;  // Static state_ that will determine which bus is deployed

    /**
     * @brief Pure virtual function.
     * @param[in] id Bus name.
     * @param[in] out Outbound Route.
     * @param[in] in Inbound Route.

     * @return Bus object with all fields filled
     */
  virtual Bus *DeployStrat(std::string id, Route * out, Route *in) = 0;
};
#endif  // SRC_BUS_STRATEGY_H_
