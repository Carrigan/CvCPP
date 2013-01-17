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

#include "MorseCodeMessenger.h"
#include "GPIO.h"
#include "LED_rgb.h"
#include "Timer.h"

int main()
{
	// Message
	char morseMessage[] = "MICRO CONTROLLER CENTRAL";
	
	// Initializers
	gpioInit();
	timerInit();
	rgbInit(PTB18, PTB19, PTD1);
	morseInit();
	
	// Do something
	morseSetTempo(100);
	morseSendMessage(morseMessage);
	
	// Test access control
	morseRemoveCriticalSafety();
	
	while(1);
	return 0;
}


void TPM0_IRQHandler()
{
	timerIRQHook();
}
