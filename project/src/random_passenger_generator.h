/**
 * @file random_passenger_generator.h
 *
 * @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
 */

#ifndef SRC_RANDOM_PASSENGER_GENERATOR_H_
#define SRC_RANDOM_PASSENGER_GENERATOR_H_
/*******************************************************************************
  * Includes
******************************************************************************/

#include <list>
#include <random>
#include <ctime>

#include "src/passenger_generator.h"
#include "src/stop.h"

class Stop;  // forward declaration
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief RandomPassengerGenerator is a PassengerGenerator
 *
 * Calls to /ref RandomPassengerGenerator generates a new
 * RandomPassengerGenerator instance
 * Calls to /ref GeneratePassengers generates a new random passenger.
 */
class RandomPassengerGenerator : public PassengerGenerator{
 public:
/**
 * @brief Creates a new RandomPassengerGenerator object.
 *
 * @param[in] probs a list of doubles that represent the probability a passenger
 * will generate at the stop.
 * @param[in] stops A list of stops to generate passengers at.
 * @return a new RandomPassengerGenerator object with all fields filled.
 */
  RandomPassengerGenerator(std::list<double>, std::list<Stop *>);
/**
 * @brief Generates passengers and adds them to stops.
 *
 * @return passengers_added int number of passengers added
 */
  int GeneratePassengers() override;

 private:
  static std:: minstd_rand0 my_rand;
};

#endif  // SRC_RANDOM_PASSENGER_GENERATOR_H_
