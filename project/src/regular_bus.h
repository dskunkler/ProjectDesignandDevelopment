/**
* @file regular_bus.h
*
* @copyright2020 Daniel Kunkler, All rights reserved.
*/
#ifndef SRC_REGULAR_BUS_H_
#define SRC_REGULAR_BUS_H_
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
 * @brief Main class for regular sized busses.
 *
 * Calls to \ref RegularBus Create a new instance of a regular bus.
 */
class RegularBus: public Bus {
 public:
   /**
    * @brief Generator for a regular bus. Default capacity is 60 and speed is 1.
    * @param[in] name_ Bus name.
    * @param[in] outgoing_route_ Outbound Route.
    * @param[in] incoming_route_ Inbound Route.
    * @param[in] passenger_max_capacity_ size of the bus.
    * @param[in] speed_ the speed of the bus.
    * Sets distance_remaining_ to 0, next_stop_ to the first stop in outbound
    * route
    *
    * @return RegularBus object with all fields filled
    */
  RegularBus(std::string name, Route * out, Route * in, int capacity = 60,
                       double speed = 1):Bus {name, out, in, capacity, speed} {}

  void Report(std::ostream&) override;
};
#endif  // SRC_REGULAR_BUS_H_
