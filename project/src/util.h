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

   static std::vector<std::string> processOutput(std::ostringstream *r_text)
   {
     std::string report_text = r_text->str();
     r_text->str("");
     r_text->clear();
     std::cout << "&&&&&&&&PROCESSING OUTPUT";
     std::vector<std::string> comma_seperated;  // this will be our csv format
     std::istringstream istr(report_text);
     std::string tmp;
     istr >> tmp;
     comma_seperated.push_back(tmp);
     while(istr >> tmp){
       comma_seperated.push_back(",");  // this will put it in its own cell
       comma_seperated.push_back(tmp);
     }
     // comma_seperated.push_back("\n");  // put an endl at the end for a new line
     return comma_seperated;
   }
};

#endif  // SRC_UTIL_H_
