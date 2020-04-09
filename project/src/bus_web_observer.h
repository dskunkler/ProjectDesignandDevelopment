/**
 * @file bus_web_observer.h
 *
 * @copyright 2020 D. Kunkler, All rights reserved.
 */
#ifndef SRC_BUS_WEB_OBSERVER_H_
#define SRC_BUS_WEB_OBSERVER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/i_observer.h"
#include "web_code/web/my_web_server_session.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class BusWebObserver : public IObserver {
 private:
  MyWebServerSession session;
};

#endif  // SRC_BUS_WEB_OBSERVER_H_
