<<<<<<< HEAD

#ifndef CONFIG_MANAGER_H_
#define CONFIG_MANAGER_H_
=======
/**
 * @file config_manager.h
 *
 * @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
 */
#ifndef SRC_CONFIG_MANAGER_H_
#define SRC_CONFIG_MANAGER_H_
>>>>>>> devel

#include <vector>
#include <string>


class Route;

class ConfigManager { 

    public:
        ConfigManager();
        ~ConfigManager();

        void ReadConfig(const std::string filename);

        std::vector<Route *> GetRoutes() const { return routes; };

    private:
        std::vector<Route *> routes;

};

#endif // CONFIG_MANAGER_H_
