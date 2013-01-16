#ifndef GPIO_H
#define GPIO_H

enum Pin
{
	PTB18,
	PTB19,
	PTD1
};

enum DigitalState
{
	HIGH,
	LOW
};

class GPIO
{
	public:
		GPIO(Pin);
		void digitalWrite(DigitalState);
	private:
		int *BME_bitSet;
		int *BME_bitClear;
		int BME_mask;
};

#endif
