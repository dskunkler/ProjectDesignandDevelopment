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

#include "../src/stop.h"
#include "../src/route.h"
#include "../src/random_passenger_generator.h"

using namespace std;
/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class RouteTests : public ::testing::Test {
protected:
  Route *route, *route1;
  Stop** rawStops;
  Stop *stop1, *stop2;
  double * distance;
  std::list<double> currProbabilities = std::list<double>();
  std::list<Stop *> stops = std::list<Stop *>();

  virtual void SetUp() {
    currProbabilities.push_back(.9);
    currProbabilities.push_back(0);
    stop1 = new Stop(1);
    stop2 = new Stop(2, 1, 1);
    stops.push_back(stop1);
    stops.push_back(stop2);
    rawStops = new Stop *[2];
    rawStops[0] = stop1;
    rawStops[1] = stop2;
    distance = new double[2];
    distance[0] = 4;
    distance[1] = 5;
    route = new Route("run1", rawStops, distance, 2,
                       new RandomPassengerGenerator(currProbabilities, stops));

    //TODO Change the next route to 3 stops and test it's distances
    route1 = new Route("run2", rawStops, distance, 1,
                       new RandomPassengerGenerator(currProbabilities, stops));
  }

  virtual void TearDown() {
    delete stop1;
    delete stop2;
    delete rawStops;
    delete route;
    delete route1;
    stop1 = NULL;
    stop2 = NULL;
    rawStops = NULL;
    route = NULL;
    route1 = NULL;
  }
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(RouteTests, Constructor) {
  Stop* testCons = route->GetDestinationStop();
  EXPECT_EQ(stop1->GetId(), testCons->GetId()) <<
    "Incorrect id from get destination stop after constructor";
  EXPECT_EQ(stop1->GetLongitude(), testCons->GetLongitude()) <<
    "Incorrect longitude from constructor";
  EXPECT_EQ(stop1->GetLatitude(), testCons->GetLatitude()) <<
    "Incorrect Latitude from constructor";
  EXPECT_EQ(route->GetName(), "run1") << "Incorrect name on construction";
  EXPECT_EQ(route->GetTotalRouteDistance(), 4) << "Incorrect total distance";
  EXPECT_EQ(route->GetNextStopDistance(), 0) <<
    "Incorrect distance before start";
  route->ToNextStop();
  EXPECT_EQ(route->GetNextStopDistance(), 4) <<
    "Incorrect distance to first start";
}

TEST_F(RouteTests, IsAtEnd) {
  EXPECT_EQ(route1->IsAtEnd(), false) << "Incorrect end in start route1";
  route1->ToNextStop();
  EXPECT_EQ(route1->IsAtEnd(), true) << "Incorrect false and end route1";

  EXPECT_EQ(route->IsAtEnd(), false) << "Incorrect end at start in route";
  route->ToNextStop();
  EXPECT_EQ(route->IsAtEnd(), false) <<
    "Incorrect end at first stop  route";
  route->ToNextStop();
  EXPECT_EQ(route->IsAtEnd(), true) << "Incorrect false at end of route";
}
