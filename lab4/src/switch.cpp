// Description: This file implements the initialization of an external
// switch.
//----------------------------------------------------------------------//

#include "switch.h"
#include <avr/io.h>

/*
 * Initializes pull-up resistor on PB3 and sets it into input mode
 */
void initSwitch(){
  // enable pin-change interrupts
  // enable interrupts on PB3
  DDRB  &= ~(1 << DDB3);//initialize input for switch
  PORTB |= (1 << PORTB3);// turn on switch, enable pull-up for PORTB3

  PCICR  |= (1 << PCIE0);      // enable PCINT for 7-0
  PCMSK0 |= (1 << PCINT3);    // enable PCINT for PCINT3
}

void switchOn() {

}

void switchOff() {

}
