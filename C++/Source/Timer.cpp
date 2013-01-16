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
