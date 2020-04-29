/**
 * @file bus_intensity_decorator.h
 *
 * @copyright 2020 and D. Kunkler, All rights reserved.
 */

#ifndef SRC_BUS_INTENSITY_DECORATOR_H_
#define SRC_BUS_INTENSITY_DECORATOR_H_
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
/*
 * @brief BusIntesnsityDecorator
 * will set the intensity of whatever Ibus object it's passed based on the number
 * of passengers and the bus size.
 */

class BusIntensityDecorator : public BusDecorator {
public:
/**
* @brief Constructor for BusDecorator, wraps the base bus.
*/
 BusIntensityDecorator(IBus *base_bus): BusToDecorate(base_bus) {}

  /**
  * @brief Tells whether the entire buses route is finished
  *
  * @return bool whether route out and route in are both at their ends.
  */
   virtual bool IsTripComplete() {return BusToDecorate->IsTripComplete();}

  /**
  * @brief Loads passengers onto the bus.
  * @param[in] new_passenger passenger to be added.
  * @param[out] passengers_ passenger list amended with passenger.
  *
  * @return bool whether passenger was added to passengers_ list or not
  */
 virtual bool LoadPassenger(Passenger * passenger ) {
   return BusToDecorate->LoadPassenger(passenger);
 }

  /**
  * @brief Moves the bus to the next stop and updates everything.
  * @param[out] passengers_ passengers updated, added, and removed appropriately
  *
  * @return bool notifying whether bus moved or not.
  */
   virtual bool Move() {return BusToDecorate->Move();}

  /**
  * @brief calls Move and UpdateBusData.
  *
  */
  virtual void Update() {
    std::cout << "Intensity Update\n";
    BusToDecorate->Move();
    BusToDecorate->UpdateBusData();
    BusData wrapped_bus_data = GetBusData();
    // BusToDecorate->ClearObservers();
    NotifyObservers(&wrapped_bus_data);
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
  * @brief gets bus_data_
  * @return bus_data_
  */
   virtual BusData GetBusData() const {
     BusData data = BusToDecorate->GetBusData();
     Color color = data.color;
     float pass = data.num_passengers;
     float capacity_ = data.capacity;
     // Percent filled will depend on the size of the bus
     float percent_filled = pass/capacity_;
     color.alpha = 120 + (int)135*percent_filled;
     data.color = color;
     return data;
   }
  /**
  * @brief Gets the bus name.
  * @return name_
  */
   virtual std::string GetName() const {return BusToDecorate->GetName();}
  /**
  * @brief Gets the next stop
  * @return next_stop_
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
  * @return passenger_max_capacity_
  */
  virtual int GetCapacity() const {return BusToDecorate->GetCapacity();}



 /**
  * @brief Tells us whether our outgoing route is finished or not.
  */
   bool OutboundComplete() { return BusToDecorate->OutboundComplete();}

 /**
  * @brief Tells us whether we're decorated or not.
  */
   bool IsDecorated() { return BusToDecorate->IsDecorated();}


protected:
 IBus *BusToDecorate;

};


#endif  // SRC_BUS_INTENSITY_DECORATOR_H_
