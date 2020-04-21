/**
* @file file_writer.cc
*
* @copyright 2020 Daniel Kunkler, all rights reserved.
*/


/*******************************************************************************
  * Includes
******************************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "file_writer.h"
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
// Input will be the class calling the manager. File name so our write can open
// and the text to be written.

void FileWriter::Write(std::string filename, std::vector<std::string> text) {
  fout.open(filename, std::fstream::app);
  for (std::vector<std::string>::iterator it = text.begin(); it != text.end();
                                                                       it++) {
    fout << *it;
  }
  fout << std::endl;
  fout.close();

}
