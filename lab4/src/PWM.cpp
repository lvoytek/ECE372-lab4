// Authors: Nadine Najdawi, Jacob Bowles, Jessica Sofka, Lena Voytek    
// Net IDs: nadinealnajdawi, bowlesj, jsofka, dvoytek      
// Date: 25 March 2019      
// Assignment: Lab 4
#include "PWM.h"

void initPWM()
{
    DDRE |= (1 << DDE3); /* pin 5 on the dev board */

    // set Fast PWM 10-bit mode, non-inverting
    TCCR3A |= (1 << COM3A1)|(1 << WGM31)|(1 << WGM30);
    TCCR3B |= (1 << WGM32)|(1 << CS30);

    // set the duty cycle 100%
    OCR3A = 255;
}

void changeDutyCycle(int dutycycle)
{
    OCR3A = (int) (1023/100.0 * dutycycle);
}