/**
 * @file passenger_factory.h
 *
 * @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
 */
#ifndef SRC_PASSENGER_FACTORY_H_
#define SRC_PASSENGER_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "src/passenger.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for PassengerFactory
 *
 * Calls to \ref Generate create a new passenger with random name and stop.
 * Calls to \ref NameGeneration generate the name for the Generate function.
 */
class PassengerFactory {
 public:
/**
 * @brief Generates a passenger.
 *
 * @param[in] curr_stop int.
 * @param[in] last_stop int.
 * @param[out] destination int.
 * @param[out] new_name string.
 * @return a new passenger with destination and new_name.
 */
  static Passenger * Generate(int, int);
 private:
/**
 * @brief Generates a random name
 *
 * @param[out] name string
 * @return name
 */
  static std::string NameGeneration();
};
#endif  // SRC_PASSENGER_FACTORY_H_
