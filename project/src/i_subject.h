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
#include "src/i_observer.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

template <typename T>
class ISubject {
 public:
  ISubject() {}
  void RegisterObserver(IObserver<T> *observer) {
    observer_.push_back(observer);
  }
  void ClearObservers() {
    observer_.clear();
  }
  virtual void NotifyObservers(T info) = 0;

 protected:
  // this is our list of observers
  std::vector<IObserver<T> *> observer_;
};
#endif  // SRC_I_SUBJECT_H_
