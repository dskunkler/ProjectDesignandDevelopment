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
// #include "web_code/web/my_web_server_command.cc"

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
    std::cout << "observer_ sizeb4 = " << std::to_string(observer_.size());
    std::cout << "Observer registered in ISubject!\n";
    observer_.push_back(observer);
    std::cout << "observer_ sizeafter = " << std::to_string(observer_.size());
  }
  /**
   * @brief ClearObservers clears all observers from observer_ vector
   */
   virtual void ClearObservers() {
    std::cout << "Observer Cleared in ISubject\n";
    observer_.clear();
  }
  /**
  * @brief NotifyObservers is a pure virtual function.
  */
   void NotifyObservers(T info) {
    std::cout << "Notify from ISubject\n observer_size = " << std::to_string(observer_.size()) << std::endl;

    for (int i = 0; i < static_cast<int>(observer_.size()); i++) {
      observer_[i]->Notify(info);
      std::cout << "Observers Notified from ISubject\n";
    }
  }

 protected:
  // this is our list of observers
  std::vector<IObserver<T> *> observer_;
};
#endif  // SRC_I_SUBJECT_H_
