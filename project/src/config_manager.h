/**
 * @file config_manager.h
 *
 * @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
 */
#ifndef SRC_CONFIG_MANAGER_H_
#define SRC_CONFIG_MANAGER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/


#include <vector>
#include <string>


class Route;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Sets up the configuration of the Bus System reading from config.txt.
 *
 * Calls to \ref ConfigManager create a new ConfigManager object with a new
 * Route vector
 * Calls to \ref ~ConfigManager sets all routes to a nullptr and then clears the
 * Route vector routes.
 * Calls to \ref ReadConfig creates a Route vector based on the a parsed file.
 */

class ConfigManager {
 public:
/**
 * @brief Generator for ConfigManager object. Routes initialized
 * @return ConfigManager object.
 */
  ConfigManager();
/**
 * @brief Destructor for ConfigManager objects.
 *
 */
  ~ConfigManager();
/**
 * @brief Reads information from provided file and sets up Routes
 *
 * @param[in] filename string for desired file
 * @param[out] routes gets updated with Routes built from filename file
 *
 */
  void ReadConfig(const std::string filename);

/**
 * @brief Gets the Route vector routes.
 *
 * @return routes a Route vector.
 */
  std::vector<Route *> GetRoutes() const { return routes; }

 private:
  std::vector<Route *> routes;
};

#endif  // SRC_CONFIG_MANAGER_H_
