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
  static FileWriterManager *instance;
  FileWriteManager() {
    file_writer = new FileWriter();
  }

  ~FileWriteManager() {
    delete file_writer;
  }

  FileWriter file_writer;

 public:
  static FileWriterManager *Getinstance() {
    if (!instance) {
      instance = new FileWriterManager;
    }
    return instance;
  }
  void Write(string file, std::vector<std::string> text) {
    file_writer->Write(file, text);
  }
};

#endif  // SRC_FILE_WRITER_MANAGERL_H_
