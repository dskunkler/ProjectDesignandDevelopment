/**
* @file large_bus.h
*
* @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
*/
#ifndef SRC_LARGE_BUS_H_
#define SRC_LARGE_BUS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/bus.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Main class for large sized busses.
 *
 * Calls to \ref LargeBus Create a new instance of a large bus.
 */
class LargeBus: public Bus {
 public:
/**
 * @brief Generator for a large bus. Default capacity is 90 and speed is 1.
 * @param[in] name_ Bus name.
 * @param[in] outgoing_route_ Outbound Route.
 * @param[in] incoming_route_ Inbound Route.
 * @param[in] passenger_max_capacity_ size of the bus.
 * @param[in] speed_ the speed of the bus.
 * Sets distance_remaining_ to 0, next_stop_ to the first stop in outbound
 * route
 *
 * @return LargeBus object with all fields filled
 */
  LargeBus(std::string name, Route * out, Route * in, int capacity = 90,
                       double speed = 1):Bus {name, out, in, capacity, speed} {}
  /**
  * @brief Report displays all the information of the Bus.
  * @param[in] out an ostream object to display to.
  */
  void Report(std::ostream&) override;
};
#endif  // SRC_LARGE_BUS_H_
