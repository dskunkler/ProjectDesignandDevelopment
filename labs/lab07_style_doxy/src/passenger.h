/**
 * @file passenger_factory.h
 *
 * @copyright 2019 3081 Staff with ammendments by Daniel Kunkler
 * , All rights reserved.
 */
#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for passengers.
 *
 * Calls to \ref Passenger generate a new Passenger instant default name is
 * "Nobody" and destination is NULL.
 * Calls to \ref Update increments wait_at_stop_.
 * Calls to \ref GetOnBus sets time of bus to 1.
 * Calls to \ref GetTotalWait returns wait_at_stop_.
 * Calls to \ref IsOnBus returns bool false.
 * Calls to \ref GetDestination returns destination_stop_id_.
 * Calls to \ref Report outputs name, destination, total wait, time at stop
 * and time on bus.
 */
class Passenger {  // : public Reporter {
 public:
 /**
  * @brief Generation of a passenger with name Nobody.
  *
  * @param[in] destination_stop_id destination stop id
  * @param[in] name_ name of passenge
  * Sets wait_at_stop_ to 0, time_on_bus_ to 0, and the id_ to the count then
  * increments count
  *
  * @return Passenger object with all fields filled.
  */
  explicit Passenger(int = -1, std::string = "Nobody");
  /**
   * @brief Updates wait at stop
   *
   * Increments wait_at_stop_ by 1
   */
  void Update();
   /**
    * @brief Sets time on bus to 1.
    *
    */
  void GetOnBus();
  /**
   * @brief Gets total wait time.
   *
   * @return wait_at_stop_ as int
   */
  int GetTotalWait() const;
  /**
   * @brief Returns bool of false
   *
   * @return false
   */
  bool IsOnBus() const;
  /**
   * @brief Gets destination id of passenger
   *
   * @return destination_stop_id_
   */
  int GetDestination() const;
  /**
   * @brief Prints passenger information
   *
   * Prints Name of passenger, destination, total wait time, waits at stop
   * and time on bus.
   */
  void Report() const;

 private:
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  int id_;
  static int count_;  // global count, used to set ID for new instances
};
#endif  // SRC_PASSENGER_H_
