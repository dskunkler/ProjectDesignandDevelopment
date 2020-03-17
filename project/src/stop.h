/**
 * @file  stop.h
 *
 * @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
 */
#ifndef SRC_STOP_H_
#define SRC_STOP_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <list>
#include <iostream>

#include "src/bus.h"
#include "src/passenger.h"

class Bus;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The stop class.
 *
 * Calls to \ref Stop generate a new instance of Stop with default location being
 * Westbound Coffman Union stop.
 * Calls to \ref LoadPassengers Load passengers from the stop onto the bus.
 * Calls to \ref AddPassengers Adds a passenger to a stop.
 * Calls to \ref Update calls Passenger::Update on all the passengers at the
 * stop
 * Calls to \ref GetId returns the stop ID
 * Calls to \ref Report Prints the stop ID and the passengers at the stop.
 * Calls to \ref GetLongitude Returns the longitude of the stop.
 * Calls to \ref GetLatitude Returns the latitude of the stop.
 * Calls to \ref GetNumPassengersPresent Returns the number of passengers at the
 * stop.
 */
class Stop {
 public:
/**
 * @brief Generator for a stop with default longitude 44.973723 and latitude
 * -93.235365
 *
 * @param[in] id_ the stop ID.
 * @param[in] longitude_ The longitude of the Stop.
 * @param[in] latitude_ The latitude of the Stop.
 * @param[out] passengers_ is cleared.
 * @return A Stop object with all fields filled.
 */
  explicit Stop(int, double = 44.973723, double = -93.235365);
/**
 * @brief Loads passengers onto a bus object.
 *
 * @param[in] bus a Bus object.
 * Increments passengers_added for every passenger able to be placed on the bus.
 * @return passengers_added int representing the number of passengers added.
 */
  int LoadPassengers(Bus *);  // Removing passengers from stop and onto a bus
/**
 * @brief Adds passengers to the Stop.
 * @param[out] passengers_ the Passenger list.
 * Adds passengers to the list
 * @return passengers_added_to_stop 0 if failed, 1 if successful
 */
  int AddPassengers(Passenger *);  // Adding passengers to the stop
  //(from the generator)

/**
 * @brief Updates all the passengers at the stop.
 */
  void Update();
/**
 * @brief Gets the ID of the stop.
 *
 * @return id_ int representing the Stop's id.
 */
  int GetId() const;
/**
 * @brief Outputs the stop id and all the passengers waiting at it's information
 *
 * @param[in] out an ostream object.
 */
  void Report(std::ostream&) const;

  // Vis Getters
/**
 * @brief Gets the longitude of the stop.
 *
 * @return longitude_ double representing the longitude of the stop.
 */
  double GetLongitude() const { return longitude_; }
/**
 * @brief Gets the latitude of the stop.
 *
 * @return latitude_ double representing the latitude of the stop.
 */
  double GetLatitude() const { return latitude_; }
/**
 * @brief Gets the number of present passengers.
 *
 * @return passengers_.size(), unsigned int representing the number of
 * passengers
 */
  size_t GetNumPassengersPresent() { return passengers_.size(); }

 private:
  int id_;
  std::list<Passenger *> passengers_;  // considered array, vector, queue, list
  double longitude_;
  double latitude_;  // are we using long/lat coords?
  // derived information - not needed depending on passengers_
  // data structure implementation?
  // int passengers_present_;
};
#endif  // SRC_STOP_H_
