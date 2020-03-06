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

#include "../src/passenger.h"
#include "../src/stop.h"

using namespace std;
/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class StopTests : public ::testing::Test {
protected:
  Stop *stop, *stop1;
  Passenger *passenger;

  virtual void SetUp() {
    stop = new Stop(1);
    stop1 = new Stop(2, 1, 1);
    passenger = new Passenger(1, "Tim");
  }

  virtual void TearDown() {
    delete stop;
    delete stop1;
    delete passenger;
    stop = NULL;
    stop1 = NULL;
    passenger = NULL;
  }
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(StopTests, Constructor) {
  EXPECT_EQ(stop->GetId(), 1) << "Improper initialization of id in stop";
  EXPECT_EQ(stop1->GetId(), 2) << "Improper initialization of id in stop1";
  EXPECT_EQ(stop->GetLongitude(), 44.973723) << "Improper default longitude";
  EXPECT_EQ(stop->GetLatitude(), -93.235365) << "Improper default latitude";
  EXPECT_EQ(stop1->GetLongitude(), 1) <<
    "Improper assignment of longitude in constructor";
  EXPECT_EQ(stop1->GetLatitude(), 1) <<
    "Improper assignment of latitude in constructor";
}
