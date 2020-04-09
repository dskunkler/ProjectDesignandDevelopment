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
 /**
  * @brief The MorningStrategy Class.
  *
  * Calls to \ref MorningStrategy create a new MorningStrategy instance that is
  * inherited from MorningStrategy inherits state from MorningStrategy starting
  * at 0.
  * Calls to \ref DeployStrat deploy Busses according to the Afternoon
  * strategy, that is small, regular, large, sequentially.
  */
class MorningStrategy : public BusStrategy {
 public:
   /**
    * @brief Generator for MorningStrategy
    *
    * @return MorningStrategy instance.
    */
  MorningStrategy();
  /**
   * @brief Generates a Small then a regular sized bus.
   * @param[in] id Bus name.
   * @param[in] out Outbound Route.
   * @param[in] in Inbound Route.

   * @return Bus object with all fields filled
   */
  Bus *DeployStrat(std::string id, Route * out, Route *in);
};
#endif  // SRC_MORNING_STRATEGY_H_
