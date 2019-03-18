// Authors: Nadine Najdawi, Jacob Bowles, Jessica Sofka, Lena Voytek    
// Net IDs: nadinealnajdawi, bowlesj, jsofka, dvoytek      
// Date: 25 March 2019      
// Assignment: Lab 4

#include "timer.h"

/* Initialize timer 0, you should not turn the timer on here.
* You will need to use CTC mode */
void initTimer0()
{
    TCCR0A &= ~(1 << WGM00); // Set timer to be in CTC mode
    TCCR0A |= (1 << WGM01);
    TCCR0B &= ~(1 << WGM02);
    TCCR0B |= (1 << CS01) | (1 << CS00); // Sets the prescaler to 1024
    OCR0A = 250;
}

/* This delays the program an amount specified by unsigned int delay.
* Use timer 0. Keep in mind that you need to choose your prescalar wisely
* such that your timer is precise to 1 millisecond and can be used for
* 100-200 milliseconds
*/
void delayMs(unsigned int delay)
{
    unsigned int delayCnt = 0;
    TIFR0 |= (1 << OCF0A); // sets the flag down
    TCNT0 = 0;
    
    while(delayCnt < delay)
    {
        if(TIFR0 & (1 << OCF0A))
        {
            delayCnt++;
            TIFR0 |= (1 << OCF0A);
        }
    }
}