/**
 * @file decorator.h
 *
 * @copyright 2020 and D. Kunkler, All rights reserved.
 */

#ifndef SRC_DECORATOR_H_
#define SRC_DECORATOR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

class Decorator: public IBus {
 public:

   /**
   * @brief Tells whether the entire buses route is finished
   *
   * @return bool whether route out and route in are both at their ends.
   */
    virtual bool IsTripComplete() {BusToDecorate->IsTripComplete();}

   /**
   * @brief Loads passengers onto the bus.
   * @param[in] new_passenger passenger to be added.
   * @param[out] passengers_ passenger list amended with passenger.
   *
   * @return bool whether passenger was added to passengers_ list or not
   */
  virtual bool LoadPassenger(Passenger *) {
    BusToDecorate->LoadPassenger(Passenger *);
  }

   /**
   * @brief Moves the bus to the next stop and updates everything.
   * @param[out] passengers_ passengers updated, added, and removed appropriately
   *
   * @return bool notifying whether bus moved or not.
   */
    virtual bool Move() {BusToDecorate->Move();}

   /**
   * @brief calls Move and UpdateBusData.
   *
   */
    virtual void Update() {BusToDecorate->Update();}

   /**
   * @brief Outputs name_, speed_, passenger_max_capacity_, distance_remaining_,
   * and all passenger information.
   *
   * @param[in] out std::ostream for display purposes.
   */
    virtual void Report(std::ostream&) {BusToDecorate->(std::ostream&);}
   /**
   * @brief Outputs a modified report with no passenger info except
   * total_passengers
   * @param[in] report_text std::ostringstream to write to a csv
   */
    virtual void StatReport(std::ostream&) {
      BusToDecorate->StatReport(std::ostream&);
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
    virtual BusData GetBusData() const {BusToDecorate->GetBusData();}
   /**
   * @brief Gets the bus name.
   * @return name_
   */
    virtual std::string GetName() const {BusToDecorate->GetName();}
   /**
   * @brief Gets the next stop
   * @return next_stop_
   */
    virtual Stop * GetNextStop() const {BusToDecorate->GetNextStop();}
   /**
   * @brief Gets the number of passengers on the bus.
   * @return passengers_.size()
   */
    virtual size_t GetNumPassengers() const {BusToDecorate->GetNumPassengers();}
   /**
   * @brief Gets the capacity of the bus.
   * @return passenger_max_capacity_
   */
   virtual int GetCapacity() const {BusToDecorate->GetCapacity();}

   /**
   * @brief Notifies the observers of the busdata.
   */
    virtual void NotifyObservers(BusData* info) {
      BusToDecorate->NotifyObservers(BusData* info);
    }


 protected:
  IBus *BusToDecorate;

  /**
  * @brief Takes passengers off of the bus via PassengerUnloader.
  * @return passengers_unloaded int
  */
   virtual int UnloadPassengers() {BusToDecorate->UnloadPassengers();}
  /**
  * @brief Signals the bus if a passenger needs to get off at the next stop.
  * @return a bool if passenger wants off.
  */
   virtual bool PassengerRequestOff() {BusToDecorate->PassengerRequestOff();}
};
#endif  // SRC_DECORATOR_H_
