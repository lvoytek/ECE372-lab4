// Authors: Nadine Najdawi, Jacob Bowles, Jessica Sofka, Lena Voytek    
// Net IDs: nadinealnajdawi, bowlesj, jsofka, dvoytek      
// Date: 25 March 2019      
// Assignment: Lab 4
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
#include "PWM.h"
#include "timer.h"

int main()
{
    initPWM();
    initTimer0();

    int duty = 100;
    while(1)
    {
      changeDutyCycle(duty);
      delayMs(10);
      duty--;

      if(duty == 0)
        duty = 100;
    }

  return 0;
}
