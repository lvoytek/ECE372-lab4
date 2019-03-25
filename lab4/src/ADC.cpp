// Authors: Nadine Najdawi, Jacob Bowles, Jessica Sofka, Lena Voytek    
// Net IDs: nadinealnajdawi, bowlesj, jsofka, dvoytek      
// Date: 25 March 2019      
// Assignment: Lab 4

#include "ADC.h"

void initADC()
{
// set voltage references to be AVCC
  ADMUX |= (1 << REFS0);
  ADMUX &= ~(1 << REFS1);

  // ADLAR = 0 (RIGHT JUSTIFIED)
  ADMUX &= ~(1 << ADLAR);

  // set Auto Trigger Source Selection
  // set to free-running mode ADTS[2:0] = 0b000
  // 
  ADCSRB &= ~(1 << ADTS2 | 1 << ADTS1 | 1 << ADTS0);

  // enable auto-triggering and turn-on ADC
  ADCSRA |= (1 << ADATE) | (1 << ADEN);

  // set the pre-scaler to 128
  // ADC clock frequency is 16 Mhz divided by pre-scaler = 125KHz
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

  // disable ADC0 pin digital input - pin A0 on board
  DIDR0 |= (1 << ADC7D);

  // start the first conversion
  ADCSRA |= (1 << ADSC);
}
