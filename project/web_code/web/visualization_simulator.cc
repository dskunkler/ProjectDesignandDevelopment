/**
 * @file visualization_simulator.cc
 *
 * @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <sstream>
#include <list>
#include <vector>
#include "web_code/web/visualization_simulator.h"
#include "src/bus.h"
#include "src/route.h"
#include  "src/bus_factory.h"
#include "src/i_subject.h"
#include "src/util.h"
#include "src/file_writer.h"
#include "src/file_writer_manager.h"
#include "src/bus_color_decorator.h"
#include "src/bus_intensity_decorator.h"
/*******************************************************************************
 * Member Functions
 ******************************************************************************/

VisualizationSimulator::VisualizationSimulator(WebInterface* webI,
                                                      ConfigManager* configM) {
    webInterface_ = webI;
    configManager_ = configM;
    bus_stats_file_name = "BusData.csv";
}

VisualizationSimulator::~VisualizationSimulator() {
}

void VisualizationSimulator::Start(const std::vector<int>& busStartTimings,
   const int& numTimeSteps) {
    busStartTimings_ = busStartTimings;
    numTimeSteps_ = numTimeSteps;

    timeSinceLastBus_.resize(busStartTimings_.size());
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        timeSinceLastBus_[i] = 0;
    }

    simulationTimeElapsed_ = 0;
    std::list<Stop *> stops;
    prototypeRoutes_ = configManager_->GetRoutes();
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Report(std::cout);
        stops = prototypeRoutes_[i]->GetStops();
        for (std::list<Stop *>::iterator it = stops.begin();
                                        it != stops.end(); it++) {
          stops_.push_back(*it);
        }

        prototypeRoutes_[i]->UpdateRouteData();
        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());
    }
}

void VisualizationSimulator::Update() {

  std::ostringstream report_text;  // This will be the text of our report
  if (!paused) {
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

            busses_.push_back(BusFactory::Generate(std::to_string(busId),
               outbound->Clone(), inbound->Clone()));
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
        if(busses_[i]->OutboundComplete() && !busses_[i]->IsDecorated()){
          std::cout << "DECORATOR WRAPPED!*!*\n";
          busses_[i] = new BusColorDecorator(busses_[i]);
        }

        busses_[i] = new BusIntensityDecorator(busses_[i]);

        if (busses_[i]->IsTripComplete()) {
          // if the bus is at the end of the line, put its stat report into the
          // ostringstream named report_text.
          busses_[i]->StatReport(report_text);
          // Have the FileWriterManager write to the bus stats file the
          // report_text
          FileWriterManager::GetInstance()->Write(bus_stats_file_name,
                                            Util::processOutput(&report_text));
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

void VisualizationSimulator::TogglePause() {
  if (!paused) {
    std::cout << "Not paused, pausing\n";
    paused = !paused;
  } else {
    std::cout << "Paused, unpausing\n";
    paused = !paused;
  }
}

void VisualizationSimulator::ClearBusListeners() {
  for (int i = 0; i < static_cast<int>(busses_.size()); i++) {
    std::cout << "Cleared from ClearBusListeners\n";
    busses_[i]->ClearObservers();
  }
}

void VisualizationSimulator::AddBusListener(std::string* id,
                                              IObserver<BusData*>* observer) {
  // iterate through to find the bus
  for (int i = 0; i < static_cast<int>(busses_.size()); i++) {
    std::cout << "AddBusListener called\n";
    if (busses_[i]->GetName() == *id) {
      std::cout << "Bus Observer " << *id << " added\n";
      busses_[i]->RegisterObserver(observer);
    }
  }
}

void VisualizationSimulator::ClearStopListeners() {
  for (int i = 0; i < static_cast<int>(stops_.size()); i++) {
    stops_[i]->ClearObservers();
  }
}

void VisualizationSimulator::AddStopListener(std::string* id,
                                              IObserver<StopData*>* observer) {
   std::cout << "Hello From StopObserver!\n";
  // iterate through to find the bus
  for (int i = 0; i < static_cast<int>(stops_.size()); i++) {
      if (std::to_string(stops_[i]->GetId()) == *id) {
        std::cout << "Stop Observer " << *id << " added\n";
        stops_[i]->RegisterObserver(observer);
    }
  }
}
