/**
* @file bus_factory.cc
*
* @copyright 2020 Daniel Kunkler, all rights reserved.
*/


/*******************************************************************************
  * Includes
******************************************************************************/
#include <vector>
#include <random>
#include <string>
#include "src/bus_factory.h"
#include "src/large_bus.h"
#include "src/regular_bus.h"
#include "src/small_bus.h"

std::random_device dev1;
std::mt19937 rng(dev1());
std::uniform_int_distribution<std::mt19937::result_type> dist1(1, 3);


/*******************************************************************************
 * Member Functions
 ******************************************************************************/
Bus *BusFactory::Generate(std::string id, Route * out,
    Route *in, int capacity) {
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
}
