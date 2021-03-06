/**
 * @file web_interface.h
 *
 * @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
 */
#ifndef WEB_CODE_WEB_WEB_INTERFACE_H_
#define WEB_CODE_WEB_WEB_INTERFACE_H_
/*******************************************************************************
* Includes
******************************************************************************/
#include "src/data_structs.h"
#include "src/bus.h"
#include "src/route.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class WebInterface {
 public:
    virtual ~WebInterface() {}

    virtual void UpdateBus(const BusData& bus, bool deleted = false) = 0;
    virtual void UpdateRoute(const RouteData& route, bool deleted = false) = 0;
};

#endif  // WEB_CODE_WEB_WEB_INTERFACE_H_
