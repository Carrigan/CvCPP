#ifndef TIMER_H
#define TIMER_H

class Timer
{
	public:
		Timer();
		void start(int);
		void attachCallback( void(*)() );
		void timerIRQHook();
		char hasTimeoutOccured();
	private:
		void (*timerCallback)();
		int counter;
		int timeout;
		char timeoutBool;
};

#endif
