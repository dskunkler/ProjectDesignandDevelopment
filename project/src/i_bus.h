/**
 * @file i_bus.h
 *
 * @copyright 2020 and D. Kunkler, All rights reserved.
 */
#ifndef SRC_I_BUS_H_
#define SRC_I_BUS_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/*
 * @brief a template so our decorator can color our bus
 */
class IBus: public ISubject<BusData*> {
};
#endif  // SRC_I_BUS_H_
