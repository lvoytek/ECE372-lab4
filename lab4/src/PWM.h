// Authors: Nadine Najdawi, Jacob Bowles, Jessica Sofka, Lena Voytek    
// Net IDs: nadinealnajdawi, bowlesj, jsofka, dvoytek      
// Date: 25 March 2019      
// Assignment: Lab 4

#ifndef PWM_H
#define PWM_H

#include <avr/io.h>

void initPWM();

void changeDutyCycle(int dutycycle);


#endif