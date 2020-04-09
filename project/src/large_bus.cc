/**
 * @file large_bus.cc
 *
 * @copyright Daniel Kunkler 2020
 */
 /*******************************************************************************
   * Includes
 ******************************************************************************/
#include <list>
#include "src/bus.h"
#include "src/large_bus.h"

/*******************************************************************************
  * Member Functions
******************************************************************************/
  void LargeBus::Report(std::ostream& out) {
    out << "Name: " << name_ << std::endl;
    out << "Speed: " << speed_ << std::endl;
    out << "Size: " << passenger_max_capacity_ << std::endl;
    out << "Distance to next stop: " << distance_remaining_ << std::endl;
    out << "\tPassengers (" << passengers_.size() << "): " << std::endl;
    for (std::list<Passenger *>::iterator it = passengers_.begin();
                                         it != passengers_.end(); it++) {
      (*it)->Report(out);
    }
  }
