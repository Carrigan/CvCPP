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

#include "MorseCodeMessenger.h"
#include "GPIO.h"
#include "LED_rgb.h"
#include "Timer.h"

// Must be declared above main since it will be used in the IRQ handler.
Timer myTimer;

int main()
{
	// Peripheral Classes
	GPIO myRedLED(PTB18);
	GPIO myGreenLED(PTB19);
	GPIO myBlueLED(PTD1);
	
	// Driver Classes
	RGBLED myRGB(&myRedLED, &myGreenLED, &myBlueLED);
	
	// Application Classes
	MorseCodeMessenger messenger(&myRGB, &myTimer);
	
	// Message
	char morseMessage[] = "MICRO CONTROLLER CENTRAL";
	
	// Do something
	messenger.setTempo(100);
	messenger.sendMessage(morseMessage);
	
	// Test access controls
	// messenger.removeCriticalSafety();
	
	while(1);
	return 0;
}

extern "C" {

	void TPM0_IRQHandler()
	{
		myTimer.timerIRQHook();
	}

}
