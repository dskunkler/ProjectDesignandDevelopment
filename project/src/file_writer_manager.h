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
/*
 * @brief the main class for FileWriterManager.
 * \ref GetInstance returns a new FileWriter if one doesn't exist, or it returns
 * the instance of Filewriter if it exists.
 */
class FileWriterManager {
 private:
  static FileWriter *instance;

 public:
/*
 * @brief Returns the singleton Filewriter instance.
 * @return instance a Filewriter
 */
  static FileWriter *GetInstance() {
    if (!instance) {
      instance = new FileWriter;
    }
    return instance;
  }
};

#endif  // SRC_FILE_WRITER_MANAGER_H_
