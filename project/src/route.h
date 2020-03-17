/**
 * @file route.h
 *
 * @Copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
 */

#ifndef SRC_ROUTE_H_
#define SRC_ROUTE_H_
/*******************************************************************************
* Includes
******************************************************************************/

#include <list>
#include <iostream>
#include <string>

#include "src/data_structs.h"

#include "src/passenger_generator.h"
#include "src/stop.h"

class PassengerGenerator;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class for Routes.
 *
 * Calls to \ref Route create a new instance of a Route.
 * Calls to \ref Clone makes a copy of the Route.
 * Calls to \ref Update Generates new passengers, updates all passengers, and
 * updates the route data struct.
 * Calls to \ref Report prints the name of the route, the number of stops, and
 * the report of each stop on the route.
 * Calls to \ref IsAtEnd notifies us if we're at the end of the route.
 * Calls to \ref PrevStop return the stop before the destination stop.
 * Calls to \ref ToNextStop change the destination_stop_ to the next stop.
 * Calls to \ref GetDestinationStop return a pointer to the next stop.
 * Calls to \ref GetTotalRouteDistance returns the total distance of the route.
 * Calls to \ref GetNextStopDistance returns the distance to the next stop.
 * Calls to \ref GetName returns the route name.
 * Calls to \ref GetStops returns the list of Stops in the route.
 * Calls to \ref UpdateRouteData updates the Route data struct to the current
 * information.
 * Calls to \ref GetRouteData returns the Route data struct.
 * Calls to \ref GenerateNewPassengers generates new passengers at the stops.
 */
class Route {
 public:
/*
 * @brief Generates a Route instance
 *
 * @param[in] name_ string of Route name.
 * @param[in] stops_ A list of Stop objects
 * @param[in] distances_between_ a list of doubles
 * @param[in] num_stops_ int the number of stops in the Route.
 * @param[in] generator_ a RandomPassengerGenerator
 * @param[out] destination_stop_index_ set to 0
 * @param[out] destination_stop_ set to first Stop.
 * @return Route object
 */
  Route(std::string name, Stop ** stops, double * distances, int num_stops,
        PassengerGenerator *);
/**
 * @brief Creates a clone of the current Route.
 *
 * @return Route object with same information as this Route.
 */
  Route * Clone();
/**
 * @brief Generates new passengers if needed, updates each passenger, and
 * updates route_data_ struct.
 */
  void Update();
/**
 * @brief outputs name of route, number of stops, the stop report, and whether
 * or not the bus is at its destination stop.
 * @param[in] out ostream object
 */
  void Report(std::ostream&);
/**
 * @brief Returns whether the route is at the end or not.
 *
 * @return bool value representing if destination_stop_index_ is greater then or
 * equal to the number of stops.
 */
  bool IsAtEnd() const;

/**
 * @brief Returns the Stop object before destination stop.
 *
 * @return a Stop that the iterator is pointing to.
 */

  Stop * PrevStop();  // Returns stop before destination stop
/**
 * @brief Changes destination_stop_ to the next stop.
 */
  void ToNextStop();  // Change destination_stop_ to next stop
/**
 * @brief Gets the destination stop.
 *
 * @return destination_stop_
 */
  Stop * GetDestinationStop() const;    // Get pointer to next stop
/**
 * @brief Gets the total Route distance.
 *
 * @param[out] total_distance double
 * @return total_distance double the total distance of the Route
 */
  double GetTotalRouteDistance() const;
/**
 * @brief Gets the distance to the next stop.
 *
 * @return double of the distance to the next stop.
 */
  double GetNextStopDistance() const;

  // Vis Getters
/**
 * @brief Gets the name of the Route.
 *
 * @return name_ a string that is the Route's name.
 */
  std::string GetName() const { return name_; }
/**
 * @breif Get the list of Stops.
 *
 * @return stops_
 */
  std::list<Stop *> GetStops() const { return stops_; }
/**
 * @brief Updates the RouteData structs.
 *
 * @param[out] route_data_
 */
  void UpdateRouteData();
/**
 * @brief Gets the route_data struct.
 *
 * @return route_data_ a RouteData struct that has all the Routes information.
 */
  RouteData GetRouteData() const;

 private:
/**
 * @brief Generates new passengers on the route.
 *
 * @return int the number of new passengers added.
 */
  int GenerateNewPassengers();       // generates passengers on its route
  PassengerGenerator * generator_;
  std::list<Stop *> stops_;
  std::list<double> distances_between_;  // length = num_stops_ - 1
  std::string name_;
  int num_stops_;
  int destination_stop_index_;  // always starts at zero, no init needed
  Stop * destination_stop_;
  // double trip_time_; // derived data - total distance travelled on route

  RouteData route_data_;
};
#endif  // SRC_ROUTE_H_
