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
    along with the C vs. CPP Project.  If not, 
    see <http://www.gnu.org/licenses/>.
 */

#include "MorseCodeMessenger.h"
#include "Timer.h"

int tempo;
int generateMorseIndexFromCharacter(char message);
void morseRemoveCriticalSafety(void);

// 0-9, A-Z, SPACE
const int morseLengths[] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 
																2, 4, 4, 3, 1, 4, 3, 4, 2, 4, 
																3, 4, 2, 2, 3, 4, 4, 3, 3, 1, 
																3, 4, 3, 4, 4, 4, 1};

// 0 = REST, 1 = SHORT, 2 = LONG
const char morseA[] = { 1, 2 };
const char morseB[] = { 2, 1, 1, 1};
const char morseC[] = { 2, 1, 2, 1};
const char morseD[] = { 2, 1, 1};
const char morseE[] = { 1};
const char morseF[] = { 1, 1, 2, 1};
const char morseG[] = { 2, 2, 1};
const char morseH[] = { 1, 1, 1, 1};
const char morseI[] = { 1, 1};
const char morseJ[] = { 1, 2, 2, 2};
const char morseK[] = { 2, 1, 2};
const char morseL[] = { 1, 2, 1, 1};
const char morseM[] = { 2, 2};
const char morseN[] = { 2, 1};
const char morseO[] = { 2, 2, 2};
const char morseP[] = { 1, 2, 2, 1};
const char morseQ[] = { 2, 2, 1, 1};
const char morseR[] = { 1, 2, 1};
const char morseS[] = { 1, 1, 1};
const char morseT[] = { 2};
const char morseU[] = { 1, 1, 2};
const char morseV[] = { 1, 1, 1, 2};
const char morseW[] = { 1, 2, 2};
const char morseX[] = { 2, 1, 1, 2};
const char morseY[] = { 2, 1, 2, 2};
const char morseZ[] = { 2, 2, 1, 1};

const char morse1[] = { 1, 2, 2, 2, 2};
const char morse2[] = { 1, 1, 2, 2, 2};
const char morse3[] = { 1, 1, 1, 2, 2};
const char morse4[] = { 1, 1, 1, 1, 2};
const char morse5[] = { 1, 1, 1, 1, 1};
const char morse6[] = { 2, 1, 1, 1, 1};
const char morse7[] = { 2, 2, 1, 1, 1};
const char morse8[] = { 2, 2, 2, 1, 1};
const char morse9[] = { 2, 2, 2, 2, 1};
const char morse0[] = { 2, 2, 2, 2, 2};

const char morseSPACE[] = { 0};

const char *morseTranslation[] = {morse0, morse1, morse2, morse3, morse4, morse5, morse6, morse7, morse8,
																	morse9, morseA, morseB, morseC, morseD, morseE, morseF, morseG, morseH,
																	morseI, morseJ, morseK, morseL, morseM, morseN, morseO, morseP, morseQ,
																	morseR, morseS, morseT, morseU, morseV, morseW, morseX, morseY, morseZ,
																	morseSPACE};

int generateMorseIndexFromCharacter(char message)
{
	// For numbers, map 48-57 to 0-9
	if(message >= '0' && message <= '9')
	{
		return message-48;
	}

	// For characters, map 65-90 to 10-35
	if(message >= 'A' && message <= 'Z')
	{
		return message-55;
	}
	
	// Otherwise, must be a break
	else
		return 36;
}

void morseInit()
{
	tempo = 0;	
}

void morseSendMessage(char *pMessage)
{
	char *message = pMessage;
	int i;
	
	while(*message != 0)
	{
		// Convert the letter to an index for the lookup arrays
		int arrayIndex = generateMorseIndexFromCharacter(*message);
		
		// For each symbol in the morse version of the letter, blink;
		for(i = 0; i < morseLengths[arrayIndex]; i++)
		{
			char currentOutput = *(morseTranslation[arrayIndex]+i);
			switch(currentOutput)
			{
				case 0:
					timerStart(tempo*2);
					while(!timerHasTimeoutOccured());
					break;
				case 1:
					rgbGreenOn();
					timerStart(tempo);
					while(!timerHasTimeoutOccured());
					rgbGreenOff();
					break;
				case 2:
					rgbGreenOn();
					timerStart(tempo*3);
					while(!timerHasTimeoutOccured());
					rgbGreenOff();
					break;
			}
			// Small delay after each blink
			timerStart(tempo);
			while(!timerHasTimeoutOccured());
		}
		
		// Small delay after each letter
		timerStart(tempo*3);
		while(!timerHasTimeoutOccured());
		
		// Increment letter
		message++;
	}
}

void morseSetTempo(int newTempo)
{
	tempo = newTempo;
}

void morseRemoveCriticalSafety()
{
	// WARNING: This function has a 30% chance
	// of calling Cthulu to the mortal realm.
	// should not be called after development
	// EVER
}
