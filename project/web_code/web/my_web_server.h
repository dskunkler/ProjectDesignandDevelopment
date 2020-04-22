/**
 * @file Bus.cc
 *
 * @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
 */
#ifndef WEB_CODE_WEB_MY_WEB_SERVER_H_
#define WEB_CODE_WEB_MY_WEB_SERVER_H_
/*******************************************************************************
* Includes
******************************************************************************/
#include <vector>
#include "web_code/web/web_interface.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class MyWebServer : public WebInterface {
 public:
        MyWebServer();
        ~MyWebServer() {}

        void UpdateRoute(const RouteData& route, bool deleted = false) override;
        void UpdateBus(const BusData& bus, bool deleted = false) override;

        std::vector<RouteData> routes;
        std::vector<BusData> busses;
};

#endif  // WEB_CODE_WEB_MY_WEB_SERVER_H_
