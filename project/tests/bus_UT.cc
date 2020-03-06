/*
*
* copyright Daniel Kunkler 2020
*
*/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>

#include "../src/bus.h"
#include "../src/passenger.h"
#include "../src/stop.h"
#include "../src/route.h"
#include "../src/random_passenger_generator.h"

using namespace std;
/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class BusTests : public ::testing::Test {
protected:
  Route *route, *route1;
  Stop** rawStops;
  Stop *stop1, *stop2, *stop3;
  double * distance;
  std::list<double> currProbabilities = std::list<double>();
  std::list<Stop *> stops = std::list<Stop *>();
  Bus *bus1, *bus2, *bus3, *bus4;
  Passenger *passenger, *passenger1;

  virtual void SetUp() {
    passenger = new Passenger();
    passenger1 = new Passenger(3, "Tim");
    currProbabilities.push_back(1);
    currProbabilities.push_back(1);
    currProbabilities.push_back(1);
    stop1 = new Stop(1);
    stop2 = new Stop(2, 1, 1);
    stop3 = new Stop(3);
    stop2->AddPassengers(passenger1);
    stops.push_back(stop1);
    stops.push_back(stop2);
    stops.push_back(stop3);
    rawStops = new Stop *[3];
    rawStops[0] = stop1;
    rawStops[1] = stop2;
    rawStops[2] = stop3;
    distance = new double[3];
    distance[0] = 4;
    distance[1] = 5;
    distance[2] = 3;
    route = new Route("run1", rawStops, distance, 3,
                       new RandomPassengerGenerator(currProbabilities, stops));
    route1 = new Route("run2", rawStops, distance, 1,
                       new RandomPassengerGenerator(currProbabilities, stops));
    bus1 = new Bus("PartyBus", route, route1);
    bus2 = new Bus("StudyBus", route1, route, 30, 5);
    bus3 = new Bus("LimoBus", route, route1, 1, 1);
    bus4 = new Bus("BrokedownBus", route, route1, 100, 0);
}

  virtual void TearDown() {
    delete stop1;
    delete stop2;
    delete stop3;
    delete rawStops;
    delete route;
    delete route1;
    delete bus1;
    delete bus2;
    delete bus3;
    delete bus4;
    delete passenger;
    delete passenger1;
    stop1 = NULL;
    stop2 = NULL;
    stop3 = NULL;
    rawStops = NULL;
    route = NULL;
    route1 = NULL;
    bus1 = NULL;
    bus2 = NULL;
    bus3 = NULL;
    bus4 = NULL;
    passenger = NULL;
    passenger1 = NULL;
  }
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(BusTests, Constructor) {
  EXPECT_EQ(bus1->GetName(), "PartyBus") <<
    "Improper name via PartyBus Constructor";
  EXPECT_EQ(bus2->GetName(), "StudyBus") <<
    "Improper name, StudyBus Constructor";
  EXPECT_EQ(bus1->GetCapacity(), 60) << "Improper default capacity";
  EXPECT_EQ(bus2->GetCapacity(), 30) << "Short bus instanciated incorrectly";
}

TEST_F(BusTests, IsTripComplete) {
  EXPECT_EQ(bus1->IsTripComplete(), false) << "Incorrect end true at route start";
  EXPECT_EQ(route->IsAtEnd(), false) << "Incorrect end at start in route";
  route->NextStop();
  EXPECT_EQ(route->IsAtEnd(), false) <<
    "Incorrect end at first stop  route";
  route->NextStop();
  EXPECT_EQ(route->IsAtEnd(), false) << "Route has one more stop";
  EXPECT_EQ(bus1->IsTripComplete(), false) <<
   "Incorrect, but route out has one more stop";
  route->NextStop();
  EXPECT_EQ(route->IsAtEnd(), true) << "route should be over";
  EXPECT_EQ(bus1->IsTripComplete(), false) << "Still needs to do incoming route";
  EXPECT_EQ(route1->IsAtEnd(), false) << "Incorrect end in start route1";
  route1->NextStop();
  EXPECT_EQ(route1->IsAtEnd(), true) << "Incorrect false end route1";
  EXPECT_EQ(bus1->IsTripComplete(), true) << "Incorrect false end at true bus end";
}

TEST_F(BusTests, LoadPassenger) {
  EXPECT_EQ(bus3->GetCapacity(), 1) << "Incorrect capacity bus3";
  EXPECT_EQ(bus3->LoadPassenger(passenger), true) <<
    "Should be able to load one passenger into bus of capacity 1";
  EXPECT_EQ(bus3->LoadPassenger(passenger1), false) <<
    "Should not be able to load two passengers onto capacity 1";
}

TEST_F(BusTests, Move) {
  EXPECT_EQ(bus4->Move(), false) << "Bus with speed 0 shouldn't move";
  EXPECT_EQ(route->IsAtEnd(), false) << "first stop";
  bus3->UpdateBusData();
  EXPECT_EQ(bus3->Move(), true) << "Bus should move from first stop";
  bus3->UpdateBusData();
  EXPECT_EQ(route->IsAtEnd(), false) << "2nd stop";
  EXPECT_EQ(bus3->Move(), true) << "move2";
  EXPECT_EQ(route->IsAtEnd(), false) << "At 3rd stop in route";

}
