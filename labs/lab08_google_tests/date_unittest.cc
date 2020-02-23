/**
 * @file date.h
 *
 * @copyright 208 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <math.h>
#include <ctime>
#include <iostream>
#include "lab08_google_tests/date.h"
#include "gtest/gtest.h"

class DateTest : public ::testing::Test {
 public:
  void SetUp() {
  // code here will execute just before the test ensues
  first_day = Date(2018, 9, 4);
  last_day = Date(2018, 12, 11);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
};



TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";

  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  // You must do this EVERY TIME, or else it will segfault
  testing::internal::CaptureStdout();
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";

  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  *
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */

TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") <<
    "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") <<
    "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) <<
    "Days between is not calculated properly";
}

TEST_F(DateTest, GetDatesCorrectCharacters) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  EXPECT_EQ(y2k.GetDate(), "1999-12-31") <<
    "y2k not retrieved properly";
  EXPECT_EQ(ind_day.GetDate(), "1776-07-04") <<
    "Independence day not retrieved properly";
  EXPECT_EQ(best_holiday.GetDate(), "2018-10-31") <<
    "Halloween not not retrieved properly";
  EXPECT_EQ(first_day.GetDate(), "2018-09-04") <<
    "First day of class not retrieved properly";
  EXPECT_EQ(last_day.GetDate(), "2018-12-11") <<
    "Last day of class not retrieved properly";
}


TEST_F(DateTest, GetUsDateTest) {
  Date early_day(1999, 11, 4);
  Date new_year(2020, 1, 1);
  EXPECT_EQ(early_day.GetUsDate(), "11-04-1999") <<
    "GetUsDate improperly applied";
  EXPECT_EQ(new_year.GetUsDate(), "01-01-2020") <<
    "GetUsDate improperly applied";
}


TEST_F(DateTest, DatesLeadingZeros) {
  Date early_day(1999, 11, 4);
  Date new_year(2020, 1, 1);

  std::string early_day_string = early_day.GetUsDate();
  std::string new_year_string = new_year.GetUsDate();
  std::string early_string = early_day.GetDate();
  std::string new_string = new_year.GetDate();
  EXPECT_EQ(new_year_string[0], '0') <<
    "Single digit month missing leading 0 from GetUsDate";
  EXPECT_EQ(early_day_string[3], '0') <<
    "Single digit day missing leading 0 from GetUsDate";
  EXPECT_EQ(new_string[5], '0') <<
    "Single digit month missing leading 0 from GetDate";
  EXPECT_EQ(early_string[8], '0') <<
    "Single digit day missing leading 0 from GetDate";
}

/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/

TEST_F(DateTest, TodaysDate) {
  Date todays_date;
  std::string month_string = todays_date.GetUsDate();
  std::string month = month_string.substr(0, 2);
  int month_int = std::stoi(month);
  EXPECT_NE(month[1], '-') << "Month missing leading 0 from GetUsDate";
  EXPECT_EQ(month_int, 2) << "Incorrect month in default constructor";
}

TEST_F(DateTest, MinusTest) {
  Date big(1999, 12, 20);
  Date small = big - 10;
  EXPECT_EQ(big.GetUsDate(), "12-20-1999") << "Incorrect retrieval of US Date";
  EXPECT_EQ(small.GetUsDate(), "12-10-1999") <<
    "Minus operator incorrectly implemented";
}

TEST_F(DateTest, TestEpoch) {
  Date two_months(1582324893);
  EXPECT_EQ(two_months.GetUsDate(), "02-21-2020") <<
    "Epoch showing incorrect date";
}

TEST_F(DateTest, TestJanToFeb) {
  Date jan(2016, 1, 1);
  Date feb(2016, 3, 1);
  EXPECT_EQ(jan.GetUsDate(), "01-01-2016") <<"Incorrect retreival of US date";
  EXPECT_EQ(feb.GetUsDate(), "03-01-2016") << "Incorrect retrieval of US date";
  EXPECT_EQ(jan.DaysBetween(feb), 60) <<
    "Incorrect number of days between 1/1/2016 and 3/1/2016";
}

TEST_F(DateTest, DaysBetweenLeapYearTest) {
  Date leapyear(2020, 1, 1);
  Date nextyear(2021, 1, 1);
  EXPECT_EQ(leapyear.GetUsDate(), "01-01-2020") <<
    "Incorrect retrieval of US date";
  EXPECT_EQ(nextyear.GetUsDate(), "01-01-2021") <<
    "Incorrect retrieval of US date";
  EXPECT_EQ(leapyear.DaysBetween(nextyear), 366) <<
    "Incorrect days on leap years";
}

TEST_F(DateTest, AddLeapYearTest) {
  Date leapyear(2020, 1, 1);
  Date nextyear = leapyear + 366;
  EXPECT_EQ(leapyear.GetUsDate(), "01-01-2020") <<
    "Incorrect retrieval of US date";
  EXPECT_EQ(nextyear.GetUsDate(), "01-01-2021") <<
    "Incorrect addition on leap year";
}

TEST_F(DateTest, AddNonLeapYear) {
  Date regyear(2019, 1, 1);
  Date nextyear = regyear + 365;
  EXPECT_EQ(regyear.GetUsDate(), "01-01-2019") <<
    "Incorrect retrieval of US date";
  EXPECT_EQ(nextyear.GetUsDate(), "01-01-2020") <<
    "Incorrect addition of non leap year";
}

TEST_F(DateTest, SubLeapYear) {
  Date leapyear(2021, 1, 1);
  Date prevyear = leapyear - 366;
  EXPECT_EQ(leapyear.GetUsDate(), "01-01-2021") <<
    "Incorrect retrieval of US date";
  EXPECT_EQ(prevyear.GetUsDate(), "01-01-2020") <<
    "Incorrect addition on leap year";
}

TEST_F(DateTest, SubNonLeapYear) {
  Date regyear(2020, 1, 1);
  Date prevyear = regyear - 365;
  EXPECT_EQ(regyear.GetUsDate(), "01-01-2020") <<
    "Incorrect retrieval of US date";
  EXPECT_EQ(prevyear.GetUsDate(), "01-01-2019") <<
    "Incorrect addition of non leap year";
}

TEST_F(DateTest, TodaysYear) {
  Date todays_date;
  std::string year_string = todays_date.GetDate();
  std::string year = year_string.substr(0, 4);
  int year_int = std::stoi(year);
  EXPECT_EQ(year_string[4], '-') << "Output not configured properly";
  EXPECT_EQ(year_int, 2020) << "Incorrect month in default constructor";
}

TEST_F(DateTest, PrintUsDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "12-31-1999\n";
  std::string expected_out_2 = "07-04-1776\n";
  std::string expected_out_3 = "10-31-2018\n";

  testing::internal::CaptureStdout();
  y2k.PrintUsDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();
  // You must do this EVERY TIME, or else it will segfault
  testing::internal::CaptureStdout();
  ind_day.PrintUsDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintUsDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "12-31-1999";
  std::string expected_out_2 = "07-04-1776";
  std::string expected_out_3 = "10-31-2018";

  testing::internal::CaptureStdout();
  y2k.PrintUsDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintUsDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, EarlyYears) {
  Date oneAD(1, 1, 1);
  EXPECT_EQ(oneAD.GetUsDate(), "01-01-1") <<
    "Incorrect date formatting for year < 1000";
}
