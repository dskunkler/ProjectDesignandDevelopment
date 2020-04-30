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
/**
 * @brief The main class for FileWriter
 *
 * Calls to \ref Write writes the contents of a string vector to a specified
 * file.
 */
class FileWriter{
 public:
/*
 * @brief Writes the content of the vector to the file specified.
 * @param[in] filename std::string
 * @param[in] text std::vector<std::string>
 */
  void Write(std::string, std::vector<std::string>);
 private:
  std::ofstream fout;
};

#endif  // SRC_FILE_WRITER_H_
