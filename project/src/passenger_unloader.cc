/**
 * @file passenger_unloader.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

 /*******************************************************************************
   * Includes
 ******************************************************************************/
#include <sstream>
#include "src/util.h"
#include "src/passenger_unloader.h"
#include "src/file_writer_manager.h"
#include "src/file_writer.h"

/*******************************************************************************
  * Member Functions
******************************************************************************/
FileWriter *FileWriterManager::instance = 0;
int PassengerUnloader::UnloadPassengers(std::list<Passenger *> *passengers,
                                        Stop * current_stop) {
  // TODO(wendt): may need to do end-of-life here
  // instead of in Passenger or Simulator
  std::ostringstream report_text;  // This will be the text from our report
  int passengers_unloaded = 0;
  for (std::list<Passenger *>::iterator it = passengers->begin();
      it != passengers->end();
      it++) {
    if ((*it)->GetDestination() == current_stop->GetId()) {
      // could be used to inform scheduler of end-of-life?
      // This could be a destructor issue as well.
      // *it->FinalUpdate();
      (*it)->Report(report_text);  // the report is now in the report_text
      FileWriterManager::GetInstance()->Write(passenger_file_name,
                                        Util::processOutput(&report_text));
      it = passengers->erase(it);
      // getting seg faults, probably due to reference deleted objects
      // here
      it--;
      passengers_unloaded++;
    }
  }

  return passengers_unloaded;
}

void PassengerUnloader::SetOutputFile(std::string filename) {
  std::cout << "*********out file set too: " << filename;
  passenger_file_name = filename;
}
