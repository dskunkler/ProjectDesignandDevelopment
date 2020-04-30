/**
 * @file bus_decorator.h
 *
 * @copyright 2020 and D. Kunkler, All rights reserved.
 */

#ifndef SRC_BUS_DECORATOR_H_
#define SRC_BUS_DECORATOR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "src/data_structs.h"
#include "src/i_subject.h"
#include "src/passenger.h"
#include "src/passenger_loader.h"
#include "src/passenger_unloader.h"
#include "src/route.h"
#include "src/stop.h"
#include "src/i_observer.h"
#include "src/i_bus.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/*
 * @brief BusColorDecorator
 * \ref IBus is the parent class. Go here method overview. This template does
 * have a protected member BusToDecorate which is an IBus pointer.
 */
class BusDecorator: public IBus {
 public:
/*
 * @brief Virtual destructor for BusDecorator
 */
  virtual ~BusDecorator() {}
 /**
 * @brief Tells whether the entire buses route is finished
 *
 * @return whether BusToDecorate's route out and route in are both at their ends
 */
  virtual bool IsTripComplete() {return BusToDecorate->IsTripComplete();}

 /**
 * @brief Loads passengers onto the bus.
 * @param[in] new_passenger passenger to be added.
 * @param[out] passengers_ passenger list amended with passenger.
 *
 * @return bool whether passenger was added to BusToDecorate's passengers_ list
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
  virtual void Update() = 0;

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
 * @return BusToDecorate's bus_data_
 */
  virtual BusData GetBusData() const = 0;
 /**
 * @brief Gets the bus name.
 * @return BusToDecorate's name_
 */
  virtual std::string GetName() const {
    std::cout << "decorator get name called returning "
                                     << BusToDecorate->GetName() << std::endl;
    return BusToDecorate->GetName();}
 /**
 * @brief Gets the next stop
 * @return BusToDecorate's next_stop_
 */
  virtual Stop * GetNextStop() const {return BusToDecorate->GetNextStop();}
 /**
 * @brief Gets the number of passengers on the bus.
 * @return BusToDecorate's passengers_.size()
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

  virtual void RegisterObserver(IObserver<BusData*> *observer) {
    BusToDecorate->RegisterObserver(observer);
  }
   /**
    * @brief ClearObservers clears all observers from observer_ vector
    */
  virtual void ClearObservers() {
    BusToDecorate->ClearObservers();
  }
   /**
   * @brief NotifyObservers is a pure virtual function.
   */
  virtual void NotifyObservers(BusData* info) {
    BusToDecorate->NotifyObservers(info);
  }

 protected:
  IBus *BusToDecorate;
};
#endif  // SRC_BUS_DECORATOR_H_
