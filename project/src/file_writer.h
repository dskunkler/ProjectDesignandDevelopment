/**
* @file file_writer.h
*
* @copyright 2020 Daniel Kunkler, All rights reserved.
*/
#ifndef SRC_FILE_WRITER_H_
#define SRC_FILE_WRITER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class FileWriter{
 public:
  FileWriter();
  void Write(string, std::vector<string>);
 private:
  ofstream fout;
};

#endif  // SRC_FILE_WRITERL_H_
