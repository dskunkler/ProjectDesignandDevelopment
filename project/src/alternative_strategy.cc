#include <iostream>
#include "src/bus.h"
#include "src/small_bus.h"
#include "src/bus_strategy.h"
#include "src/alternative_strategy.h"

// This strategy doesn't need to monitor state.
AlternativeStrategy::AlternativeStrategy() {}

// Every time it's called, simply return a small bus.
Bus *AlternativeStrategy::DeployStrat(std::string id, Route * out, Route *in) {
  // std::cout <<"MAKING A SMALL BUS! FROM ALTSTRAT\n";
  return new SmallBus(id, out, in);
}