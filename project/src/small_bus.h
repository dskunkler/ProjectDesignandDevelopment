/**
* @file small_bus.h
*
* @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
*/
#ifndef SRC_SMALL_BUS_H_
#define SRC_SMALL_BUS_H_
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
 * @brief Main class for Small sized busses.
 *
 * Calls to \ref SmallBus Create a new instance of a small bus.
 */
class SmallBus: public Bus {
 public:
    /**
     * @brief Generator for a small bus. Default capacity is 30 and speed is 1.
     * @param[in] name_ Bus name.
     * @param[in] outgoing_route_ Outbound Route.
     * @param[in] incoming_route_ Inbound Route.
     * @param[in] passenger_max_capacity_ size of the bus.
     * @param[in] speed_ the speed of the bus.
     * Sets distance_remaining_ to 0, next_stop_ to the first stop in outbound route
     *
     * @return SmallBus object with all fields filled
     */
  SmallBus(std::string name, Route * out, Route * in, int capacity = 30,
                        double speed = 1):Bus{name, out, in, capacity, speed} {}

  void Report(std::ostream&) override;
};
#endif  // SRC_SMALL_BUS_H_
