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
