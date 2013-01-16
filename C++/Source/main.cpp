#include "MorseCodeMessenger.h"
#include "GPIO.h"
#include "LED_rgb.h"
#include "Timer.h"

// LED Color goes along with buffer
Timer myTimer;

int main()
{
	// Peripheral Classes
	GPIO myRedLED(PTB18);
	GPIO myGreenLED(PTB19);
	GPIO myBlueLED(PTD1);
	
	// Advanced Classes
	RGBLED myRGB(&myRedLED, &myGreenLED, &myBlueLED);
	MorseCodeMessenger messenger(&myRGB, &myTimer);
	
	// Message
	char morseMessage[] = "MICRO CONTROLLER CENTRAL";
	
	// Do something
	messenger.setTempo(100);
	messenger.sendMessage(morseMessage);
	
	while(1);
	return 0;
}

void TPM0_IRQHandler()
{
	myTimer.timerIRQHook();
}
