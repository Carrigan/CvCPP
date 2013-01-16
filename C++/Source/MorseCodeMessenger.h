#include "LED_rgb.h"
#include "Timer.h"

class MorseCodeMessenger 
{
	public:
		void sendMessage(char*);
		void setTempo(int);
		MorseCodeMessenger(RGBLED*, Timer*);
	private:
		int tempo;
	  int generateMorseIndexFromCharacter(char);
		RGBLED *myLED;
		Timer *myTimer;
};
