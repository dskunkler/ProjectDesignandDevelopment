/**
 * @file i_bus.h
 *
 * @copyright 2020 and D. Kunkler, All rights reserved.
 */
#ifndef SRC_I_BUS_H_
#define SRC_I_BUS_H_
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
#include "src/i_bus.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/*
 * @brief a template so our decorator can color our bus. 
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
class IBus: public ISubject<BusData*> {
public:
virtual ~IBus() {};
/**
* @brief Tells whether the entire buses route is finished
*
* @return bool whether route out and route in are both at their ends.
*/
 virtual bool IsTripComplete() = 0;

/**
* @brief Loads passengers onto the bus.
* @param[in] new_passenger passenger to be added.
* @param[out] passengers_ passenger list amended with passenger.
*
* @return bool whether passenger was added to passengers_ list or not
*/
 virtual bool LoadPassenger(Passenger *) = 0;  // returning revenue delta

/**
* @brief Moves the bus to the next stop and updates everything.
* @param[out] passengers_ passengers updated, added, and removed appropriately
*
* @return bool notifying whether bus moved or not.
*/
 virtual bool Move() = 0;

/**
* @brief calls Move and UpdateBusData.
*
*/
 virtual void Update() = 0;

/**
* @brief Outputs name_, speed_, passenger_max_capacity_, distance_remaining_,
* and all passenger information.
*
* @param[in] out std::ostream for display purposes.
*/
 virtual void Report(std::ostream&) = 0;
/**
* @brief Outputs a modified report with no passenger info except
* total_passengers
* @param[in] report_text std::ostringstream to write to a csv
*/
 virtual void StatReport(std::ostream&) = 0;

 // Vis Getters

/**
* @brief Updates the bus_data_
*
* @param[out] bus_data_
* @param[out] distance_remaining_
*/
 virtual void UpdateBusData() = 0;

/**
* @brief gets bus_data_
* @return bus_data_
*/
 virtual BusData GetBusData() const = 0;
/**
* @brief Gets the bus name.
* @return name_
*/
 virtual std::string GetName() const = 0;
/**
* @brief Gets the next stop
* @return next_stop_
*/
 virtual Stop * GetNextStop() const = 0;
/**
* @brief Gets the number of passengers on the bus.
* @return passengers_.size()
*/
 virtual size_t GetNumPassengers() const = 0;
/**
* @brief Gets the capacity of the bus.
* @return passenger_max_capacity_
*/
virtual int GetCapacity() const = 0;

/**
* @brief Notifies the observers of the busdata.
*/
 virtual void NotifyObservers(BusData* info) = 0;



protected:
/**
* @brief Takes passengers off of the bus via PassengerUnloader.
* @return passengers_unloaded int
*/
 virtual int UnloadPassengers() = 0;  // returning revenue delta
/**
* @brief Signals the bus if a passenger needs to get off at the next stop.
* @return a bool if passenger wants off.
*/
 virtual bool PassengerRequestOff() = 0;
 // // bool Refuel();
 // PassengerUnloader * unloader_;
 // PassengerLoader * loader_;
 // std::list<Passenger *> passengers_;
 // int total_passengers;  // the total number of passengers who rode the bus.
 // int passenger_max_capacity_;
 // // double revenue_; // revenue collected from passengers, doesn't include
 //                     // passengers who pay on deboard
 // // double fuel_;   // may not be necessary for our simulation
 // // double max_fuel_;
 // std::string name_;
 // double speed_;  // could also be called "distance travelled in one time step"
 // Route * outgoing_route_;
 // Route * incoming_route_;
 // double distance_remaining_;  // when negative?, unload/load procedure occurs
 //                             // AND next stop set
 // Stop * next_stop_;
 // // bool trip_complete_;  // [DERIVED data] when BOTH routes are at end, trip
 // // is complete
 //
 // // Vis data for bus
 // BusData bus_data_;
};
#endif  // SRC_I_BUS_H_
