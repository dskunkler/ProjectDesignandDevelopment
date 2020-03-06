/*
 * Students: Use this file as a guide to writing your own unit tests.
 * See the project instructions for more information on which classes
 * and methods must be tested.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>

#include "../src/passenger_loader.h"
#include "../src/passenger_unloader.h"
#include "../src/passenger.h"
#include "../src/stop.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class PassengerTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Passenger *passenger, *passenger1, *passenger2;

  virtual void SetUp() {
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
    passenger = new Passenger();
    passenger1 = new Passenger(1, "Fred");
    passenger2 = new Passenger(2, "Tim");
  }

  virtual void TearDown() {
    delete pass_loader;
    delete pass_unloader;
    delete passenger;
    delete passenger1;
    delete passenger2;
    passenger = NULL;
    passenger1 = NULL;
    passenger2 = NULL;
    pass_loader = NULL;
    pass_unloader = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(PassengerTests, Constructor) {
  std::string expected_out = "Name: Nobody\nDestination: -1\nTotal Wait: 0\n"
    "\tWait at Stop: 0\n\tTime on bus: 0\n";
  std::string expected_out2 = "Name: Fred\nDestination: 1\nTotal Wait: 0\n"
    "\tWait at Stop: 0\n\tTime on bus: 0\n";

  testing::internal::CaptureStdout();
  passenger->Report(cout);
  std::string output = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  passenger1->Report(cout);
  std::string output2 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(passenger->IsOnBus(), false);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
  EXPECT_EQ(passenger->GetDestination(), -1) <<
    "Incorrect passenger default constructor";
  EXPECT_EQ(passenger->GetTotalWait(), 1) <<
    "Incorrect initialization of wait time";
  EXPECT_EQ(output, expected_out) <<
    "Passenger Report incorrect";
  EXPECT_EQ(output2, expected_out2) <<
    "Passenger1 initialization failed";
};

TEST_F(PassengerTests, Update) {
   std::string expected_out1 = "Name: Fred\nDestination: 1\nTotal Wait: 0\n"
    "\tWait at Stop: 0\n\tTime on bus: 0\n";
  std::string expected_out2 = "Name: Fred\nDestination: 1\nTotal Wait: 1\n"
    "\tWait at Stop: 1\n\tTime on bus: 0\n";
  std::string expected_out3 = "Name: Fred\nDestination: 1\nTotal Wait: 3\n"
    "\tWait at Stop: 1\n\tTime on bus: 2\n";


  EXPECT_EQ(passenger1->GetTotalWait(), 0) << "Initial wait wrong passenger1";

  testing::internal::CaptureStdout();
  passenger1->Report(cout);
  std::string output1 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out1) << "Unexpected report output passenger1";

  EXPECT_EQ(passenger1->IsOnBus(), false);
  passenger1->Update();

  EXPECT_EQ(passenger1->GetTotalWait(), 1) <<
    "Wrong wait after update not on bus, passenger1";

  testing::internal::CaptureStdout();
  passenger1->Report(cout);
  std::string output2 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output2, expected_out2) <<
    "Incorrect report after update";

  passenger1->GetOnBus();
  passenger1->Update();

  testing::internal::CaptureStdout();
  passenger1->Report(cout);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output3, expected_out3) << " Update failed on bus, passenger1";
}

TEST_F(PassengerTests, GetOnBus) {
  EXPECT_EQ(passenger->IsOnBus(), false) << "New passenger shouldn't be on bus";
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true) << "Passenger should be on bus";
}

TEST_F(PassengerTests, GetTotalWait) {
  EXPECT_EQ(passenger->GetTotalWait(), 0) <<
    "New passenger should have no wait time";
  passenger->Update();
  passenger->GetOnBus();
  EXPECT_EQ(passenger->GetTotalWait(),2) <<
    "After waiting and getting on bus total should be 2.";
}

TEST_F(PassengerTests, PassengerOnAndOff) {
  std::list<Passenger *> passengers;
  EXPECT_EQ(passenger1->GetTotalWait(), 0) <<
    "New passenger should have 0 wait time";
  EXPECT_EQ(pass_loader->LoadPassenger(passenger1, 1, &passengers), 1) <<
    "LoadPassenger should return 1 if passenger gets on bus";
  EXPECT_EQ(passenger1->GetTotalWait() ,1) <<
    "Wait should be at 1 after call to GetOnBus in LoadPassenger";
  Stop uOfMn(1);
  EXPECT_EQ(pass_unloader->UnloadPassengers(&passengers, &uOfMn), 1) <<
    "Wrenn should get off, its his stop";
}

TEST_F(PassengerTests, GetDestination) {
  EXPECT_EQ(passenger->GetDestination(), -1) <<
    "Default destination should be -1";
  EXPECT_EQ(passenger2->GetDestination(), 2) <<
    "Destination should align with construtor";
}

TEST_F(PassengerTests, Report) {
  std::string expected_out = "Name: Fred\nDestination: 1\nTotal Wait: 0\n"
    "\tWait at Stop: 0\n\tTime on bus: 0\n";

  testing::internal::CaptureStdout();
  passenger1->Report(cout);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, expected_out) << "Report doesn't match expected outcome";
}
