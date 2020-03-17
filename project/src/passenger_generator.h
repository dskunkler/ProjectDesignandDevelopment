/**
 * @file passenger_generator.h
 *
 * @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
 */

#ifndef SRC_PASSENGER_GENERATOR_H_
#define SRC_PASSENGER_GENERATOR_H_
/*******************************************************************************
* Includes
******************************************************************************/

#include <list>
#include "src/passenger_factory.h"
#include "src/stop.h"

class Stop;  // forward declaration
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Abstract class to generate passengers at stops
 *
 * Calls to \ref PassengerGenerator will create a new instance of
 * PassengerGenerator in inherited functions.
 * Calls to \ref GeneratePassengers will be implemented in inherited classes
 * since this class is abstract.
 */
class PassengerGenerator {
 public:
/**
 * @brief Generator for PassengerGenerator.
 *
 * @param[in] generation_probabilities_ double list.
 * @param[in] stops_ Stop list.
 * @return new PassengerGenerator object.
 */
  PassengerGenerator(std::list<double>, std::list<Stop *>);
  // Makes the class abstract, cannot instantiate and forces subclass override
/**
 * @brief This function is purely virtual and will be defined in inherited
 * classes.
 * @return int of number of passengers generated perhaps.
 */
  virtual int GeneratePassengers() = 0;  // pure virtual
 protected:
  std::list<double> generation_probabilities_;
  std::list<Stop *> stops_;

  // should we be using a singleton here somehow?
  // PassengerFactory * pass_factory;
};
#endif  // SRC_PASSENGER_GENERATOR_H_
