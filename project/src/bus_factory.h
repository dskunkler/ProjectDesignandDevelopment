/**
*
* @file bus_factory.h
*
* @copyright 2020 Daniel Kunkler, All rights reserved
*/

#ifndef SRC_BUS_FACTORY_H_
#define SRC_BUS_FACTORY_H_

/*******************************************************************************
  * Includes
******************************************************************************/
#include <string>

#include "src/bus.h"
/*******************************************************************************
  * Class Definitions
******************************************************************************/
/**
 * @brief The main class for producing busses
 *
 * Calls to \ref Generate function to get a new instance of a bus.
 *  This is a static call, not requiring an instance to invoke the method.
 */

class BusFactory {
 public:
   /**
    * @brief Generation of a bus with a randomized size.
    *
    * This function will be used for simulation purposes.
    *
    * @param[in] id, the id of the bus.
    * @param[in] out Outbound route.
    * @param[in] in Inbound route.
    *
    * @return Bus object with id, out Route, in Route, a random size 30/60/90, and a
    * speed of 1
    */
  static Bus *Generate(std::string name, Route*, Route*, int capacity = 0);
};
#endif  // SRC_BUS_FACTORY_H_
