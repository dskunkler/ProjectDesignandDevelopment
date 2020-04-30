/**
* @file file_writer_manager.h
*
* @copyright 2020 Daniel Kunkler, All rights reserved.
*/
#ifndef SRC_FILE_WRITER_MANAGER_H_
#define SRC_FILE_WRITER_MANAGER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "src/file_writer.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class FileWriterManager {
 private:
  static FileWriter *instance;
  FileWriter file_writer;  // %TODO : Do you actually need this?

 public:
  static FileWriter *GetInstance() {
    if (!instance) {
      instance = new FileWriter;
    }
    return instance;
  }
};

#endif  // SRC_FILE_WRITER_MANAGER_H_
