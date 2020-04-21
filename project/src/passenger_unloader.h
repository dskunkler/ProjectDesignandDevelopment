/**
 * @file passenger_unloader.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_UNLOADER_H_
#define SRC_PASSENGER_UNLOADER_H_
/*******************************************************************************
* Includes
******************************************************************************/
#include <string>
#include <list>
#include "src/passenger.h"
#include "src/stop.h"
class Stop;
class Passenger;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class unloads passengers to their appropriate stop.
 *
 * Calls to \ref UnloadPassengers takes passengers out of the passenger list
 * if they're at their desired location.
 */
class PassengerUnloader {
 public:
  // UnloadPassengers returns the number of passengers removed from the bus.
/**
 * @brief Unloads passengers at their desired stop.
 *
 * @param[in, out] passengers Passenger list.
 * @param[in] current_stop the Stop the bus is currently at.
 * @return passengers_unloaded
 */
  int UnloadPassengers(std::list<Passenger*> *passengers, Stop * current_stop);
  // todo(Kunkler)  doxygen this
  void SetOutputFile(std::string);
 private:
   std::string passenger_file_name;
};
#endif  // SRC_PASSENGER_UNLOADER_H_
