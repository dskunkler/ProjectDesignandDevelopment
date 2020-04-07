/**
 * @file i_subject.cc
 *
 * @copyright 2020 Daniel Kunkler, All rights reserved.
 */

 /*******************************************************************************
   * Includes
 ******************************************************************************/
 #include <vector>
 #include "i_subject.h"

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
void ISubject<T>::NotifyObservers(T* observer ) {
  observer_[0]->UpdateObserver(observer->bus_data_);
}
