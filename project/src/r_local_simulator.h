/**
 * @file r_local_simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_R_LOCAL_SIMULATOR_H_
#define SRC_R_LOCAL_SIMULATOR_H_
/*******************************************************************************
  * Includes
******************************************************************************/
#include <vector>
#include <string>
#include "src/simulator.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief rLocalSimulator class simulates a route to test our program
  *
  * Calls to \ref Start() Start our simulation.
  * Calls to \ref Update() Update the simulation.
  */
class rLocalSimulator : public Simulator {
 public:
/**
 * @brief Starts the instance of the local simulator. Fills in all the
 * bus, route, and passenger information.
 * @return bool instance true if it worked properly.
 */
  bool Start() override;
  /**
   * @brief Updates the instance of the local simulator appropriately for each
   * stop and movement of the bus on the route.
   * @return bool instance true if it worked properly.
   */
  bool Update() override;
 private:
  std::vector<int> bus_counters_;
  std::vector<int> bus_start_timings_;
  std::vector<int> time_since_last_bus_generation_;
  int simulation_time_elapsed_;
};

#endif  // SRC_R_LOCAL_SIMULATOR_H_
