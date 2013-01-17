/*
  	Author: Brian Carrigan
  	Date: 1/15/2013
  	Email: brian.c.carrigan@gmail.com
 
   This file is part of the C vs. CPP Project.

    The C vs. CPP Project is free software: you 
    can redistribute it and/or modify it under the terms of the GNU 
    General Public License as published by the Free Software Foundation, 
    either version 3 of the License, or (at your option) any later 
    version.

    The C vs. CPP Project is distributed in 
    the hope that it will be useful, but WITHOUT ANY WARRANTY; without 
    even the implied warranty of MERCHANTABILITY or FITNESS FOR A 
    PARTICULAR PURPOSE.  See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with the C vs. CPP Project.  If not, 
    see <http://www.gnu.org/licenses/>.
 */

#include "GPIO.h"
#include "MKL25Z4.h"

GPIO::GPIO(Pin pPin)
{
	
	SIM_SCGC5 |= (SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTC_MASK |   SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTE_MASK );
	
	switch(pPin)
	{
		case(PTB18):
			PORTB_PCR18 = 0x00000100;
			GPIOB_PDDR |= 0x00040000;
			BME_mask = 0x00040000;
			BME_bitSet = (int *)&GPIOB_PSOR;
			BME_bitClear = (int *)&GPIOB_PCOR;
			break;
		case(PTB19):
			PORTB_PCR19 = 0x00000100;
			BME_mask = 0x00080000;
			GPIOB_PDDR |= 0x00080000;
			BME_bitSet = (int *)0x400FF044;
			BME_bitClear = (int *)0x400FF048;
			break;
		case(PTD1):
			PORTD_PCR1 = 0x00000100;
			GPIOD_PDDR |= 0x00000002;
			BME_mask = 0x00000002;
			BME_bitSet = (int *)0x400FF0C4;
			BME_bitClear = (int *)0x400FF0C8;
			break;
		default:
			break;
	}
}

void GPIO::digitalWrite(DigitalState pDigitalState)
{
	if(pDigitalState == HIGH)
	{
		*BME_bitSet = BME_mask;
	} else {
		*BME_bitClear = BME_mask;
	}
}
