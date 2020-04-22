/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
 */


#ifndef SRC_BUS_H_
#define SRC_BUS_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <iostream>
#include <list>
#include <string>

#include "src/data_structs.h"
#include "src/i_subject.h"
#include "src/passenger.h"
#include "src/passenger_loader.h"
#include "src/passenger_unloader.h"
#include "src/route.h"
#include "src/stop.h"
#include "src/i_observer.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for bus.
 *
 * Calls to \ref Bus create a new Bus instance whose default capacity is 60
 * and default speed is 1.
 * Calls to \ref IsTripComplete returns a bool if there are no more stops
 * in either the outgoing or incoming Route.
 * Calls to \ref LoadPassenger returns a bool if the specified passenger was
 * able to be added to the Bus or not.
 * Calls to \ref Move returns bool depending on if the Bus was able to move or
 * not.
 * Calls to \ref Update Moves the bus and updates the bus data.
 * Calls to \ref Report Outputs name, speed, size, distance to next stop,
 * and passengers.
 * Calls to \ref UpdateBusData Updates bus_data_ according to the current Bus
 * data.
 * Calls to \ref GetBusData returns bus_data_.
 * Calls to \ref GetName returns the bus name.
 * Calls to \ref GetNumPassengers returns the number of current passengers.
 * Calls to \ref GetCapacity returns the maximum number of passengers.
 * Calls to \ref UnloadPassengers returns the number of passengers unloaded.
 */
class Bus: public ISubject<BusData*> {
 public:
/**
 * @brief Generator for a bus. Default capacity is 60 and speed is 1.
 * @param[in] name_ Bus name.
 * @param[in] outgoing_route_ Outbound Route.
 * @param[in] incoming_route_ Inbound Route.
 * @param[in] passenger_max_capacity_ size of the bus.
 * @param[in] speed_ the speed of the bus.
 * Sets distance_remaining_ to 0, next_stop_ to the first stop in outbound route
 *
 * @return Bus object with all fields filled
 */
  Bus(std::string name, Route * out, Route * in, int capacity = 60,
        double speed = 1);
/**
 * @brief Tells whether the entire buses route is finished
 *
 * @return bool whether route out and route in are both at their ends.
 */
  bool IsTripComplete();

/**
 * @brief Loads passengers onto the bus.
 * @param[in] new_passenger passenger to be added.
 * @param[out] passengers_ passenger list amended with passenger.
 *
 * @return bool whether passenger was added to passengers_ list or not
 */
  bool LoadPassenger(Passenger *);  // returning revenue delta

/**
 * @brief Moves the bus to the next stop and updates everything.
 * @param[out] passengers_ passengers updated, added, and removed appropriately
 *
 * @return bool notifying whether bus moved or not.
 */
  bool Move();

/**
 * @brief calls Move and UpdateBusData.
 *
 */
  void Update();

/**
 * @brief Outputs name_, speed_, passenger_max_capacity_, distance_remaining_,
 * and all passenger information.
 *
 * @param[in] out std::ostream for display purposes.
 */
  virtual void Report(std::ostream&);
/**
 * @brief Outputs a modified report with no passenger info except
 * total_passengers
 * @param[in] report_text std::ostringstream to write to a csv
 */
  void StatReport(std::ostream&);

  // Vis Getters

/**
 * @brief Updates the bus_data_
 *
 * @param[out] bus_data_
 * @param[out] distance_remaining_
 */
  void UpdateBusData();

/**
 * @brief gets bus_data_
 * @return bus_data_
 */
  BusData GetBusData() const;
/**
 * @brief Gets the bus name.
 * @return name_
 */
  std::string GetName() const { return name_; }
/**
 * @brief Gets the next stop
 * @return next_stop_
 */
  Stop * GetNextStop() const { return next_stop_; }
/**
 * @brief Gets the number of passengers on the bus.
 * @return passengers_.size()
 */
  size_t GetNumPassengers() const { return passengers_.size(); }
/**
 * @brief Gets the capacity of the bus.
 * @return passenger_max_capacity_
 */
  int GetCapacity() const { return passenger_max_capacity_; }

/**
 * @brief Notifies the observers of the busdata.
 */
  void NotifyObservers(BusData* info) override;



 protected:
/**
 * @brief Takes passengers off of the bus via PassengerUnloader.
 * @return passengers_unloaded int
 */
  int UnloadPassengers();  // returning revenue delta
/**
 * @brief Signals the bus if a passenger needs to get off at the next stop.
 * @return a bool if passenger wants off.
 */
  bool PassengerRequestOff();
  // bool Refuel();
  PassengerUnloader * unloader_;
  PassengerLoader * loader_;
  std::list<Passenger *> passengers_;
  int total_passengers;  // the total number of passengers who rode the bus.
  int passenger_max_capacity_;
  // double revenue_; // revenue collected from passengers, doesn't include
                      // passengers who pay on deboard
  // double fuel_;   // may not be necessary for our simulation
  // double max_fuel_;
  std::string name_;
  double speed_;  // could also be called "distance travelled in one time step"
  Route * outgoing_route_;
  Route * incoming_route_;
  double distance_remaining_;  // when negative?, unload/load procedure occurs
                              // AND next stop set
  Stop * next_stop_;
  // bool trip_complete_;  // [DERIVED data] when BOTH routes are at end, trip
  // is complete

  // Vis data for bus
  BusData bus_data_;
};
#endif  // SRC_BUS_H_
