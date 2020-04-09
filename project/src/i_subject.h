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
 /**
  * @brief Main class ISubject.
  *
  * Calls to \ref RegisterObserver adds an IObserver to our observer_ vector.
  * Calls to \ref ClearObservers clears all IObservers from observer_ vector.
  * Calls to \ref NotifyObservers is a pure virtual function cannot call it here
  */
template <typename T>
class ISubject {
 public:
   /**
    * @brief Generator for a ISubject object
    *
    * @return ISubject object.
    */
  ISubject() {}
  /**
   * @brief Registers IObservers to our observer_ vector.
   * @param[in] observer an IObserver object
   */
  void RegisterObserver(IObserver<T> *observer) {
    observer_.push_back(observer);
  }
  /**
   * @brief ClearObservers clears all observers from observer_ vector
   */
  void ClearObservers() {
    observer_.clear();
  }
  /**
  * @brief NotifyObservers is a pure virtual function.
  */
  virtual void NotifyObservers(T info) = 0;

 protected:
  // this is our list of observers
  std::vector<IObserver<T> *> observer_;
};
#endif  // SRC_I_SUBJECT_H_
