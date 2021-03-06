/**
* @file bus_factory.cc
*
* @copyright 2020 Daniel Kunkler, all rights reserved.
*/


/*******************************************************************************
  * Includes
******************************************************************************/

#include <time.h>
#include <iostream>
#include <vector>
#include <random>
#include <string>

#include "src/bus_factory.h"
#include "src/large_bus.h"
#include "src/regular_bus.h"
#include "src/small_bus.h"

#include "src/morning_strategy.h"
#include "src/noon_strategy.h"
#include "src/afternoon_strategy.h"
#include "src/alternative_strategy.h"

std::random_device dev1;
std::mt19937 rng(dev1());
std::uniform_int_distribution<std::mt19937::result_type> dist1(1, 3);


/*******************************************************************************
 * Member Functions
 ******************************************************************************/
BusStrategy* BusFactory::strategy_ = NULL;

Bus *BusFactory::Generate(std::string id, Route * out,
                                                    Route *in, int capacity) {
  // std::cout << "MADE IT TO THE FACTORY\n";
  time_t rawtime;  // This will be our time.
  struct tm timeinfo;  // This holds our time info.

  time(&rawtime);  // time is now in rawtime
  localtime_r(&rawtime, &timeinfo);  // timeinfo is now in the time struct

  // Print the time.
  char buff[50];
  std::cout << "Current local time and date: " << asctime_r(&timeinfo, buff);

  // Get the military hour for checking purposes.
  int hour = timeinfo.tm_hour;

  std::cout << "Strategy: ";
  // If its between 6am and 8am we want to use the morning strategy.
  if (hour >= 6 && hour < 8) {
    std::cout << "1.\n";
    strategy_ = new MorningStrategy();
  } else if (hour >=8 && hour < 15) {
      // if its between 8 am and 3 pm we use the noon strat.
      std::cout << "2.\n";
      strategy_ = new NoonStrategy();
    } else if (hour >= 15 && hour < 20) {
      // if between 3 and 8 am we use the afternoon strat.
      std::cout << "3.\n";
      strategy_ = new AfternoonStrategy();
  } else {
      // any other time we use the alternative strat
      std::cout << "small.\n";
      strategy_ = new AlternativeStrategy();
  }

  // Return whatever size bus our strategy deploys
  return strategy_->DeployStrat(id, out, in);
      /*
  int size = dist1(rng);
  if (capacity != 0) {
    size = capacity;
  }
  // std::cout << "Random Bus Size = " << size << std::endl;

  switch ( size ) {
    case 1:
      // std::cout << "Making bus of size 30\n";
      return new SmallBus(id, out, in);
      break;
    case 2:
    // std::cout << "Making bus of size 60\n";
      return new RegularBus(id, out, in);
      break;
    case 3:
    // std::cout << "Making bus of size 90\n";
      return new LargeBus(id, out, in);
      break;

    default:
      std::cout << "ERROR e NOT BETWEEN 1 AND 3!!!\n";
  }
  return NULL;
  */
}
