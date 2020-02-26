/**
 * @file passenger_factory.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef PASSENGER_FACTORY_H_
#define PASSENGER_FACTORY_H_

#include <string>

#include "src/passenger.h"

class PassengerFactory {
 public:
  static Passenger * Generate(int, int);
 private:
  static std::string NameGeneration();
};
#endif  // PASSENGER_FACTORY_H_
