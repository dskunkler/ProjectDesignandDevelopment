/**
 * @file passenger_loader.h
 *
 * @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
 */
#ifndef SRC_PASSENGER_LOADER_H_
#define SRC_PASSENGER_LOADER_H_

/*******************************************************************************
* Includes
******************************************************************************/

#include <list>
#include "./passenger.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class adds passengers to a list of passenger and returns whether
 * a passenger was added or not.
 *
 * Calls to \ref LoadPassenger load a passenger into a list as long as the
 * maximum number of passengers isn't full.
 */
class PassengerLoader {
 public:
  // LoadPassenger returns the number of passengers added to the bus.
  // Currently this is either one or zero: either passenger was added or they
  // weren't.
  // This was a design decision. We don't know if we should allow the adding of
  // multiple passengers at a time
  // This allows us to change the Passenger Loader without having to change
  // the Bus.
/**
 * @brief LoadPassenger adds a passenger to a list if the max passengers isn't
 * reached.
 *
 * @param[in] new_passenger passenger to be added
 * @param[in] max_pass maximum passengers allowed
 * @param[in] passengers Passenger list
 * @param[out] passengers has new_passenger added to the back.
 * @return added_passenger bool true if size of passengers is less then max_pass
 * else returns false.
 */
  bool LoadPassenger(Passenger * new_passenger, int max_pass,
                    std::list<Passenger *> * passengers);
};
#endif  // SRC_PASSENGER_LOADER_H_
