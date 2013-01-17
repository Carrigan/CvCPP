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

void (*mTimerCallback)();
static int mCounter;
static int mTimeout;
static char mTimeoutBool;
static void defaultAttachFunction(void);


// For the max clock:
void timerInit()
{
	// Enable Clock
	SIM_SCGC6 |= 0x01000000;
	SIM_SOPT2 |= 0x01000000;
	NVIC_ISER |= (1 << 17);
	SIM_COPC &= ~0x0000000C;
	
	// Interrupt enabled, divide by 128 (16ms)
	TPM0_SC = 0x00000043;
	
	// Set the timer for 1ms
	TPM0_MOD = 4000;
	
	// Set the boolean
	mTimeoutBool = 0;
	
	mTimerCallback = &defaultAttachFunction;
}

char timerHasTimeoutOccured()
{
	if(mTimeoutBool == 1)
	{
		mTimeoutBool = 0;
		return 1;
	}
	
	return 0;
}

void timerStart(int timeout)
{
	TPM0_SC |= 0x00000008;
	mCounter = 0;
	mTimeout = timeout;
}

void timerAttachCallback(void(*pFunction)())
{
	mTimerCallback = pFunction;
}

void timerIRQHook()
{
	if(mCounter == mTimeout)
	{
		TPM0_SC &= ~0x00000008;
		mTimerCallback();
		mTimeoutBool = 1;
	} else {
		mCounter++;
	}
	TPM0_SC |= 0x00000080;
}


void defaultAttachFunction()
{
	return;
}

