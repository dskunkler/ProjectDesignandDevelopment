/**
 * @file passenger_generator.cc
 *
 * @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
 */
 /*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/passenger_generator.h"

#include "src/passenger.h"

/*******************************************************************************
* Member Functions
******************************************************************************/

PassengerGenerator::PassengerGenerator(std::list<double> probs,
   std::list<Stop *> stops) {
  generation_probabilities_ = probs;
  stops_ = stops;
}
