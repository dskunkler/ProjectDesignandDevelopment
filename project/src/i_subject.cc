/**
 * @file i_subject.cc
 *
 * @copyright 2020 Daniel Kunkler, All rights reserved.
 */

 /*******************************************************************************
   * Includes
 ******************************************************************************/
 #include <vector>
 #include "src/i_subject.h"
 #include "src/data_structs.h"

 /*******************************************************************************
   * Member Functions
 ******************************************************************************/
template <typename T>
void ISubject<T>::RegisterObserver(T *observer ) {
  observer_.push_back(observer);
}

template <typename T>
void ISubject<T>::ClearObservers() {
  observer_.clear();
}

template <typename T>
void ISubject<T>::NotifyObservers(BusData* info ) {
  observer_[0]->Notify(info);
}
