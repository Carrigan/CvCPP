#include "LED_rgb.h"
#include "GPIO.h"

RGBLED::RGBLED(GPIO *redLED, GPIO *greenLED, GPIO *blueLED)
{
	red = redLED;
	green = greenLED;
	blue = blueLED;
	
	red->digitalWrite(LOW);
	green->digitalWrite(LOW);
	blue->digitalWrite(LOW);
}

void RGBLED::redOn()
{
	red->digitalWrite(HIGH);
}

void RGBLED::redOff()
{
	red->digitalWrite(LOW);
}

void RGBLED::greenOn()
{
	green->digitalWrite(HIGH);
}

void RGBLED::greenOff()
{
	green->digitalWrite(LOW);
}

void RGBLED::blueOn()
{
	blue->digitalWrite(HIGH);
}

void RGBLED::blueOff()
{
	blue->digitalWrite(LOW);
}
