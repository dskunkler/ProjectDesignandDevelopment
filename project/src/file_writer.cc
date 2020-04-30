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
#include "src/file_writer.h"
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
// Input will be the class calling the manager. File name so our write can open
// and the text to be written.

void FileWriter::Write(std::string filename, std::vector<std::string> text) {
  // use our ofsteam to open a file name with the append flag so we don't erase
  // our previous updates.
  fout.open(filename, std::fstream::app);
  for (std::vector<std::string>::iterator it = text.begin(); it != text.end();
                                                                       it++) {
    // write each element of our vector to our csv file.
    fout << *it;
  }
  // append a newline to the end of each line so it doesn't bleed together.
  fout << std::endl;
  // close the file so we don't just keep trying to open the same one.
  fout.close();
}
