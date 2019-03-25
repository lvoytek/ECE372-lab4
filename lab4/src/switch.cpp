// Description: This file implements the initialization of an external
// switch.
//----------------------------------------------------------------------//

#include "switch.h"
#include <avr/io.h>

/*
 * Initializes pull-up resistor on PB3 and sets it into input mode
 */
void initSwitch(){
  DDRB &= ~(1 << DDB3);
  PORTB |= (1 << PORTB3);

  // PCICR |= (1 << PCIE0);      // enable PCINT for 7-0
  //PCMSK0 |= (1 << PCINT5);    // enable PCINT for PCINT5
}

void initSwitchPB3(){
  DDRB &= ~(1 << DDB3);
  PORTB |= (1 << PORTB3); // enable pull-up for PORTB3

  PCICR |= (1 << PCIE0);
  // enable interrupts on PB3
  PCMSK0 |= (1 << PCINT3);
}

