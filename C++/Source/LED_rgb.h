#ifndef RGBLED_H
#define RGBLED_H

#include "GPIO.h"

class RGBLED
{
	public:
		RGBLED(GPIO*, GPIO*, GPIO*);
		void redOn();
		void redOff();
		void greenOn();
		void greenOff();
		void blueOn();
		void blueOff();
	private:
		GPIO *red;
		GPIO *blue;
	  GPIO *green;
};

#endif
