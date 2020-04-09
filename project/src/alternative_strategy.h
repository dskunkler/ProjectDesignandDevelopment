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

 /**
  * @brief The AlternativeStrategy Class.
  *
  * Calls to \ref AlternativeStrategy create a new AlternativeStrategy instance
  * that is inherited from BusStrategy inherits state from BusStrategy starting
  * at 0.
  * Calls to \ref DeployStrat deploy Busses according to the Alternative
  * strategy, that is small busses only.
  */
class AlternativeStrategy : public BusStrategy {
 public:
   /**
    * @brief Generator for AlternatStrategy
    *
    * @return AlternatStrategy instance.
    */
  AlternativeStrategy();

  /**
   * @brief Generates a small bus only.
   * @param[in] id Bus name.
   * @param[in] out Outbound Route.
   * @param[in] in Inbound Route.

   * @return Bus object with all fields filled
   */
  Bus *DeployStrat(std::string id, Route * out, Route *in) override;
};
#endif  // SRC_ALTERNATIVE_STRATEGY_H_
