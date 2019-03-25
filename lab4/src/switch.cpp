// Description: This file implements the initialization of an external
// switch.
//----------------------------------------------------------------------//

#include "switch.h"
#include <avr/io.h>


void initSwitchPB3()
{
  DDRB &= ~(1 << DDB3);
  PORTB |= (1 << PORTB3); // enable pull-up for PORTB3

  PCICR |= (1 << PCIE0);
  // enable interrupts on PB3
  PCMSK0 |= (1 << PCINT3);
}

