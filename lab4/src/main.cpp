// Authors: Nadine Najdawi, Jacob Bowles, Jessica Sofka, Lena Voytek    
// Net IDs: nadinealnajdawi, bowlesj, jsofka, dvoytek      
// Date: 25 March 2019      
// Assignment: Lab 4

#include <avr/io.h>
#include "ADC.h"
#include "switch.h"
#include "timer.h"
#include "PWM.h"
#include <Arduino.h> //sei()

/*
* Define a set of states that can be used in the state machine using an enum.
*/
typedef enum stateType_enum
{
    wait_press, debounce_press, wait_release, debounce_release
} stateType;

volatile stateType state = wait_press;
volatile bool button = true;

int main()
{
    int low = 0;
    sei();

    initSwitchPB3();
    initTimer0();
    initADC();
    initPWM();

    while(1)
    {
        // Switch ISR
        switch(state)
        {
            case wait_press:
                low = ADCL;
                low += ((ADCH & 0x3) << 8);
                changeDutyCycle((int) low/1023.0 * 100.0);
                break;

            case debounce_press:
                delayMs(1);
                state = wait_release;
                break;
            
            case wait_release:
                low = 0;
                OCR3A = 0;
                OCR4A = 0;
                break;
            
            case debounce_release:
                delayMs(1);
                state = wait_press;
                break;
           
            default:
                break;
        }
    }

    return 0;
}

//set PCINT
ISR(PCINT0_vect)
{
    if(state == wait_press)
    {
        state = debounce_press;
    }
    else if (state == wait_release)
    {
        button = ~button;
        state = debounce_release;
    }
}