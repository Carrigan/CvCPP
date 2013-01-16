#include "GPIO.h"
#include "MKL25Z4.h"

GPIO::GPIO(Pin pPin)
{
	switch(pPin)
	{
		case(PTB18):
			PORTB_PCR18 = 0x00000100;
			BME_mask = 0x00040000;
			BME_bitSet = (int *)0x480FF040;
			BME_bitClear = (int *)0x480FF044;
			break;
		case(PTB19):
			PORTB_PCR18 = 0x00000100;
			BME_mask = 0x00080000;
			BME_bitSet = (int *)0x480FF040;
			BME_bitClear = (int *)0x480FF044;
			break;
		case(PTD1):
			PORTD_PCR1 = 0x00000100;
			BME_mask = 0x00000001;
			BME_bitSet = (int *)0x480FF0C4;
			BME_bitClear = (int *)0x480FF0C8;
			break;
		default:
			break;
	}
}

void GPIO::digitalWrite(DigitalState pDigitalState)
{
	if(pDigitalState == HIGH)
	{
		*BME_bitSet = BME_mask;
	} else {
		*BME_bitClear = BME_mask;
	}
}
