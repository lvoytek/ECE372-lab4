// Authors: Nadine Najdawi, Jacob Bowles, Jessica Sofka, Lena Voytek    
// Net IDs: nadinealnajdawi, bowlesj, jsofka, dvoytek      
// Date: 25 March 2019      
// Assignment: Lab 4
#include "PWM.h"

void initPWM()
{
    DDRB |= (1 << DDB5); /* pin 11 on the dev board */
    // configure the output compare module for waveform generation mode
    // set Fast PWM 10-bit mode, non-inverting
    TCCR1A |= (1 << COM1A1)|(1 << WGM11)|(1 << WGM10);
    TCCR1B |= (1 << WGM12)|(1 << CS10);
    // set the duty cycle - we just need to determine the value for OCR1A
    // OCR1A = ?
    // set the duty cycle 25%
    OCR1A = 255; // could have done 0x3FF/4;
}

void changeDutyCycle(int dutycycle)
{
    
}