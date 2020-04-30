/**
 * @file i_observer.h
 *
 * @copyright 2020 D. Kunkler, All rights reserved.
 */
#ifndef SRC_I_OBSERVER_H_
#define SRC_I_OBSERVER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/data_structs.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief IObserver Class
  *
  * Calls to /ref IObserver create a new IObserver object
  * Calls to /ref Notify alerts vis_sim to the information passed to it.
  */
template <typename T>
class IObserver {
 public:
   /**
    * @brief Generator for an observer
    *
    * @return IObserver object
    */
  IObserver() {}
  /**
   * @brief Notify is pure virtual Function
   */
  virtual void Notify(T info) = 0;
};

#endif  // SRC_I_OBSERVER_H_
