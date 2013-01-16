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
