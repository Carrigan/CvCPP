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

#include "Timer.h"
#include "MKL25Z4.h"

// For the max clock:
Timer::Timer()
{
	// Interrupt enabled, divide by 128 (16ms)
	TPM0_SC = 0x00000043;
	
	// Set the timer for 1ms
	TPM0_MOD = 4000;
	
	// Set hte boolean
	timeoutBool = 0;
}

char Timer::hasTimeoutOccured()
{
	if(timeoutBool == 1)
	{
		timeoutBool = 0;
		return 1;
	}
	
	return 0;
}

void Timer::start(int pCounter)
{
	TPM0_SC |= 0x00000010;
	counter = 0;
	timeout = pCounter;
}

void Timer::attachCallback(void(*pFunction)())
{
	timerCallback = pFunction;
}

void Timer::timerIRQHook()
{
	if(counter == timeout)
	{
		TPM0_SC &= 0xFFFFFFF7;
		timerCallback();
		timeoutBool = 1;
	} else {
		counter++;
	}
}
