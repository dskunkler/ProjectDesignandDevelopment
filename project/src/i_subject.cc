/**
 * @file i_subject.cc
 *
 * @copyright 2020 Daniel Kunkler, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <iostream>
#include "src/i_subject.h"
#include "src/i_observer.h"
#include "src/data_structs.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

/*
template <typename T>
ISubject<T>::ISubject() {}
*/
template <typename T>
void ISubject<T>::RegisterObserver(IObserver<T> *observer ) {
  observer_.push_back(observer);
}

template <typename T>
void ISubject<T>::ClearObservers() {
  observer_.clear();
}

template <typename T>
void ISubject<T>::NotifyObservers(T* info ) {
  observer_[0]->Notify(info);
  std::cout << "notify called from subject";
}
