/**
 * @file bus_color_decorator.h
 *
 * @copyright 2020 and D. Kunkler, All rights reserved.
 */

#ifndef SRC_BUS_COLOR_DECORATOR_H_
#define SRC_BUS_COLOR_DECORATOR_H_
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
#include "src/bus.h"
#include "src/bus_decorator.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief BusColorDecorator
 *
 * \ref BusDecorator is the parent class. Go here method overview.
 */
class BusColorDecorator : public BusDecorator {
 public:
/**
* @brief Constructor for BusColorDecorator, wraps the base IBus.
* @param[in] base_bus an IBus pointer
*/
  explicit BusColorDecorator(IBus *base_bus) {
    BusDecorator::BusToDecorate = base_bus;
  }

  /**
  * @brief Tells whether the entire buses route is finished
  *
  * @return BusToDecorate's bool whether route out and route in are both at
  * their ends.
  */
  virtual bool IsTripComplete() {return BusToDecorate->IsTripComplete();}

  /**
  * @brief Loads passengers onto the bus.
  * @param[in] new_passenger passenger to be added.
  * @param[out] passengers_ passenger list amended with passenger.
  *
  * @return BusToDecorate's bool whether passenger was added to passengers_
  * list or not
  */
  virtual bool LoadPassenger(Passenger * passenger ) {
    return BusToDecorate->LoadPassenger(passenger);
  }

  /**
  * @brief Moves the bus to the next stop and updates everything.
  * @param[out] passengers_ passengers updated, added, and removed appropriately
  *
  * @return BusToDecorate's bool notifying whether bus moved or not.
  */
  virtual bool Move() {return BusToDecorate->Move();}

  /**
  * @brief calls Move and UpdateBusData.
  *
  */
  virtual void Update() {
    std::cout << "Color Update\n";
    BusToDecorate->Update();
  }

  /**
  * @brief Outputs name_, speed_, passenger_max_capacity_, distance_remaining_,
  * and all passenger information.
  *
  * @param[in] out std::ostream for display purposes.
  */
  virtual void Report(std::ostream& out) {BusToDecorate->Report(out);}
  /**
  * @brief Outputs a modified report with no passenger info except
  * total_passengers
  * @param[in] report_text std::ostringstream to write to a csv
  */
  virtual void StatReport(std::ostream& out) {
    BusToDecorate->StatReport(out);
  }

  // Vis Getters

  /**
  * @brief Updates the bus_data_
  *
  * @param[out] bus_data_
  * @param[out] distance_remaining_
  */
  virtual void UpdateBusData() {BusToDecorate->UpdateBusData();}

  /**
  * @brief gets bus_data_ from our BusToDecorate, creates a gold color object
  * and assigns data's color to gold.
  * @return data a BusData object colored gold
  */
  virtual BusData GetBusData() const {
    BusData data = BusToDecorate->GetBusData();
    Color gold = Color(255, 215, 0, 120);
    data.color = gold;
    return data;
  }
  /**
  * @brief Gets the bus name.
  * @return BustoDecorate's name_
  */
  virtual std::string GetName() const {return BusToDecorate->GetName();}
  /**
  * @brief Gets the next stop
  * @return BusToDecorate's  next_stop_
  */
  virtual Stop * GetNextStop() const {return BusToDecorate->GetNextStop();}
  /**
  * @brief Gets the number of passengers on the bus.
  * @return passengers_.size()
  */
  virtual size_t GetNumPassengers() const {
    return BusToDecorate->GetNumPassengers();
  }
  /**
  * @brief Gets the capacity of the bus.
  * @return BusToDecorate's passenger_max_capacity_
  */
  virtual int GetCapacity() const {return BusToDecorate->GetCapacity();}


 /**
  * @brief Tells us whether our outgoing route is finished or not.
  */
  bool OutboundComplete() { return BusToDecorate->OutboundComplete();}

  /**
  * @brief Tells us whether we're decorated or not.
  */
  bool IsDecorated() { return true;}
};

#endif  // SRC_BUS_COLOR_DECORATOR_H_
