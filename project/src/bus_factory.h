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

class BusFactory {
 public:
  static Bus *Generate(std::string name, Route*, Route*);
};
#endif  // SRC_BUS_FACTORY_H_
