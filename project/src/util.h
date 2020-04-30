/**
* @file util.h
*
* @copyright 2020 Daniel Kunkler, All rights reserved.
*/
#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Util {
 public:
  static std::vector<std::string> processOutput(std::ostringstream *r_text){
    // produce a string from our ostringstream
    std::string report_text = r_text->str();
    // clear the ostring stream so we can use it later
    r_text->str("");
    r_text->clear();
    // declare our vector that we will be returning
    std::vector<std::string> comma_seperated;  // this will be our csv format
    // convert the text to a istringstream so we can iterate through it
    std::istringstream istr(report_text);
    // create a temp holder for each word that our istr will produce
    std::string tmp;
    // put the first word in so we can have consistent comma insertions
    istr >> tmp;
    comma_seperated.push_back(tmp);  // put the first word in our vector
    // while the istringstream has something in it, place the thing into tmp
    while (istr >> tmp) {
      comma_seperated.push_back(",");  // this will put seperate cells
      comma_seperated.push_back(tmp);  // push the word to the end of the vect
    }
    return comma_seperated;  // return the vector
  }
};

#endif  // SRC_UTIL_H_
