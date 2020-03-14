/**
 * @file Bus.cc
 *
 * @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
 */
#include "visualization_simulator.h"

#include "bus.h"
#include "route.h"
#include  "bus_factory.h"

VisualizationSimulator::VisualizationSimulator(WebInterface* webI, ConfigManager* configM) {
    webInterface_ = webI;
    configManager_ = configM;
}

VisualizationSimulator::~VisualizationSimulator() {

}

void VisualizationSimulator::Start(const std::vector<int>& busStartTimings, const int& numTimeSteps) {
    busStartTimings_ = busStartTimings;
    numTimeSteps_ = numTimeSteps;

    timeSinceLastBus_.resize(busStartTimings_.size());
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        timeSinceLastBus_[i] = 0;
    }

    simulationTimeElapsed_ = 0;

    prototypeRoutes_ = configManager_->GetRoutes();
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Report(std::cout);

        prototypeRoutes_[i]->UpdateRouteData();
        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());
    }

}

void VisualizationSimulator::Update() {
  if(!paused) {
    simulationTimeElapsed_++;

    std::cout << "~~~~~~~~~~ The time is now " << simulationTimeElapsed_;
    std::cout << "~~~~~~~~~~" << std::endl;

    std::cout << "~~~~~~~~~~ Generating new busses if needed ";
    std::cout << "~~~~~~~~~~" << std::endl;

    // Check if we need to generate new busses
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {


        // Check if we need to make a new bus
        if (0 >= timeSinceLastBus_[i]) {

            Route * outbound = prototypeRoutes_[2 * i];
            Route * inbound = prototypeRoutes_[2 * i + 1];

            busses_.push_back(BusFactory::Generate(std::to_string(busId), outbound->Clone(), inbound->Clone()));
            busId++;

            timeSinceLastBus_[i] = busStartTimings_[i];
        } else {
            timeSinceLastBus_[i]--;
        }
    }

    std::cout << "~~~~~~~~~ Updating busses ";
    std::cout << "~~~~~~~~~" << std::endl;

    // Update busses
    for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
        busses_[i]->Update();

        if (busses_[i]->IsTripComplete()) {
            webInterface_->UpdateBus(busses_[i]->GetBusData(), true);
            busses_.erase(busses_.begin() + i);
            continue;
        }

        webInterface_->UpdateBus(busses_[i]->GetBusData());

        busses_[i]->Report(std::cout);
    }

    std::cout << "~~~~~~~~~ Updating routes ";
    std::cout << "~~~~~~~~~" << std::endl;
    // Update routes
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Update();

        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());

        prototypeRoutes_[i]->Report(std::cout);
    }
  }
}

void VisualizationSimulator::Pause() {
  if(!paused){
    std::cout << "Not paused, pausing\n";
    paused = !paused;
  }
  else{
    std::cout << "Paused, unpausing\n";
    paused = !paused;
  }
}
