/**
 *
 * @filename bus_strategy.h
 * @copyright Daniel Kunkler 2020
 */
/*******************************************************************************
   * Includes
 ******************************************************************************/
#include  "src/bus_strategy.h"

// I kept getting errors that it was referencing an undefined type so here is
// the definition. Now I'm not getting errors.
int BusStrategy::state_ = 0;
