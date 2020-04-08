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
template <typename T>
class IObserver {
 public:
   IObserver() {};
   virtual void Notify(T info) = 0;
};

#endif  // SRC_I_OBSERVER_H_
