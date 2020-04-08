#include <iostream>
#include "src/bus.h"
#include "src/bus_strategy.h"
#include "src/noon_strategy.h"

void NoonStrategy::DeployStrat(std::string id, Route * out, Route *in) {
  if(state == 0) {
    return new RegularBus(id, out, in);
    state++;
  }
  else if(state == 1) {
    return new LargeBus(id, out, in);
    state = 0;
  }
  else {
    std::cout << "***ERROR INCORRECT STATE IN NOON STRAT***\n";
  }

}
