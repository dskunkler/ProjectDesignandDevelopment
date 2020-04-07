/**
 * @file visualization_simulator.h
 *
 * @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
 */
#ifndef WEB_VISUALIZATION_SIMULATOR_H_
#define WEB_VISUALIZATION_SIMULATOR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <vector>
#include <list>

#include "web_code/web/web_interface.h"
#include "src/config_manager.h"

class Route;
class Bus;
class Stop;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the Visualization Simulator.
 *
 * Calls to \ref VisualizationSimulator create a new instance of
 * VisualizationSimulator
 * Calls to \ref ~VisualizationSimulator invoke the destructor for the instance.
 * Calls to \ref Start() Starts the simulation.
 * Calls to \ref Update update the simulation.
 * Calls to \ref Pause pause the simulation.
 */
class VisualizationSimulator {
 public:
/**
 * @brief Generator for a Visualization Simulator.
 *
 * @return Visualization Simulator object
 */
  VisualizationSimulator(WebInterface*, ConfigManager*);
/**
 * @brief Destructor for a VisualizationSimulator
 */
  ~VisualizationSimulator();
/**
 * @brief Starts the Visualization Simulator
 *
 * @param[in] busStartTimings_ an int vector of bus start times
 * @param[in] numTimeSteps_ an integer
 * sets timeSinceLastBus_ to be the size of busStartTimings_
 * sets all the times in timeSinceLastBus_ to 0
 * sets simulationTimeElapsed_ to 0
 * sets prototypeRoutes_ to be the routes from the config manager
 * each route reports and updates the routedata struct
 * webinterface then updates the routes.
 */

  void Start(const std::vector<int>&, const int&);
/**
 * @brief Updates the Visual Simulation.
 *
 * If the simulation is not paused:
 * simulationTimeElapsed_ is incremented by 1, then printed to display.
 * If time time since last bus is <= 0, We will generate a new bus from the
 * bus factory. Othwerwise we decrement the time timeSinceLastBus_ by 1.
 * We then update all the buses and if the busses trip is complete we delete it.
 * A report of the buses is then printed.
 * We then update all the routes and print their report.
 */
  void Update();
/**
 * @brief Toggles whether the Visualization simulator is paused or not.
 */
  void TogglePause();

/**
 * @brief Clears the listeners of the Bus
 */

  void ClearListeners();

/**
 * @brief Adds a listener to the bus.
 * @param[in] id the id of the bus
 * @param[in] BusWebObserver A web observer object
 */

 void AddListener(std::string* id, IObserver* observer );

 private:
        WebInterface* webInterface_;
        ConfigManager* configManager_;

  std::vector<int> busStartTimings_;
  std::vector<int> timeSinceLastBus_;
  int numTimeSteps_;
  int simulationTimeElapsed_;

  std::vector<Route *> prototypeRoutes_;
  std::vector<Bus *> busses_;
  Bus* subject_;

  bool paused = false;

  int busId = 1000;
};

#endif  // WEB_VISUALIZATION_SIMULATOR_H_
