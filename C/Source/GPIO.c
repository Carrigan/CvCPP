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
    along with the Evolutionary Blackjack Strategy Solver.  If not, 
    see <http://www.gnu.org/licenses/>.
 */

#include "GPIO.h"
#include "MKL25Z4.h"

void gpioInit()
{
	// Clock up
	SIM_SCGC5 |= (SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTC_MASK |   SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTE_MASK );
	
	// Initialize Pins
	PORTB_PCR18 = 0x00000100;
	PORTB_PCR19 = 0x00000100;
	GPIOB_PDDR |= 0x000C0000;
	PORTD_PCR1 = 0x00000100;
	GPIOD_PDDR |= 0x00000002;
}


void gpioDigitalWrite(DigitalState pDigitalState, Pin pPin)
{
	unsigned int *bitSet;
	unsigned int *bitClear;
	unsigned int bitMask;
	
	switch(pPin)
	{
		case PTB18:
			bitSet = (unsigned int*)&GPIOB_PSOR;
			bitClear = (unsigned int*)&GPIOB_PCOR;
			bitMask = 0x00040000;
			break;
		case PTB19:
			bitSet = (unsigned int*)&GPIOB_PSOR;
			bitClear = (unsigned int*)&GPIOB_PCOR;
			bitMask = 0x00080000;
			break;
		case PTD1:
			bitSet = (unsigned int*)&GPIOD_PSOR;
			bitClear = (unsigned int*)&GPIOD_PCOR;
			bitMask = 0x00000002;			
		default:
			break;
	}
	if(pDigitalState == HIGH)
	{
		*bitSet = bitMask;
	} else {
		*bitClear = bitMask;
	}
}
