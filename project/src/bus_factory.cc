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

std::random_device dev1;
std::mt19937 rng(dev1());
std::uniform_int_distribution<std::mt19937::result_type> dist1(1,3);
int size = dist1(rng);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
Bus *BusFactory::Generate(std::string id, Route * out, Route *in) {


  switch(size) {
    case 1:
      return new Bus(id, out, in, 30, 1);
      break;
    case 2:
      return new Bus(id, out, in, 60, 1);
      break;
    case 3:
      return new Bus(id, out, in, 90, 1);

    default:
      std::cout << "ERROR e NOT BETWEEN 1 AND 3!!!\n";
  }
  return NULL;
}
