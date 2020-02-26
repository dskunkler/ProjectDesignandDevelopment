/**
 * @file random_passenger_generator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef RANDOM_PASSENGER_GENERATOR_H_
#define RANDOM_PASSENGER_GENERATOR_H_

#include <list>
#include <random>
#include <ctime>

#include "src/passenger_generator.h"
#include "src/stop.h"

class Stop;  // forward declaration

class RandomPassengerGenerator : public PassengerGenerator{
 public:
  RandomPassengerGenerator(std::list<double>, std::list<Stop *>);
  int GeneratePassengers() override;

 private:
  static std:: minstd_rand0 my_rand;
};

#endif  // RANDOM_PASSENGER_GENERATOR_H_
