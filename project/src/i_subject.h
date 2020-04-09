/**
 * @file i_subject.h
 *
 * @copyright 2020 and D. Kunkler, All rights reserved.
 */
#ifndef SRC_I_SUBJECT_H_
#define SRC_I_SUBJECT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "src/data_structs.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <typename T>
class ISubject {
 public:
  ISubject() {}
  void RegisterObserver(T *observer);
  void ClearObservers();
  void NotifyObservers(BusData* info);

 protected:
  // this is our list of observers
  std::vector<T *> observer_;
};
#endif  // SRC_I_SUBJECT_H_
