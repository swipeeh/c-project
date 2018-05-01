/*
 * test.c
 *
 * Created: 4/26/2018 11:51:23
 * Author : Patrik Kucerka
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

int counter = 0;																							// used to keep track of inputs
int results[5] = {0b00111111, 0b10011111, 0b00111111, 0b00111111, 0b00111111};								// array with results
int levels[5] = {0b11111101, 0b01111111, 0b11011111, 0b11111110, 0b11110111};								// array with bytes for each level

void nextLevel();
int checkResult();
void win();

int main(void)
{
	DDRA = 0xff;																							// set up
	DDRB = 0x00;																							// set up
	
	PCICR ^= (1<<PCIE0);																					// enabling interrupts for PCINT0 (portb)
	PCMSK0 ^= (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3)  | (1<<PB4)  | (1<<PB5)  | (1<<PB6)  | (1<<PB7);    // enabling interrupts on port b bit from bit 0 to 7
	sei();																									// enable global interrupts
    
	int finish = 0b01010101;																				//	sequence displayed when the level is completed
	
	for (int i = 1; i < 6; i++)																				//	loop through levels
	{
		counter = 0;																						// reset counter to 0
		nextLevel(i);
		_delay_ms(1000);																						// function containing next level
		int a = checkResult(i);																				// function for checking the answers is called, returns 0 or 1 (true or false)
		if (a == 0)																							// if incorrect input was detected, failure sequence is displayed
		{
			finish = 0b11100111;																			// sequence for lost level
			break;																							// breaks out of the loops since the game is lost
		}
		PORTA = finish;																						// sequence depending on the result is displayed (win/lose sequence)
		_delay_ms(2000);																					// time for player to prepare for the next level
	}
	if (finish == 0b01010101)																				// if all levels are won, sequence indicating end of the game is displayed
	{
		win();																								// final win sequence
	}
	else
	{
		PORTA = 0b11100111;																					// lose sequence if the game is lost
	}
}

void win(){																									// function which displays final win sequence
	for (int i = 0; i < 4; i++)
	{
		PORTA = 0b10101010;
		_delay_ms(500);
		PORTA = 0b01010101;
		_delay_ms(500);
	}
	PORTA = 0xff;
}

void nextLevel(int level)																					// function containing all levels
{
	
	if (level == 1)
	{
		PORTA = 0b11111101;																					// each bit is displayed
		_delay_ms(1000);																					// and followed by delay
		
	}
	else if(level == 2)
	{
		PORTA = 0b11111101;
		_delay_ms(1000);
		PORTA = 0b01111111;
	}
	else if(level == 3)
	{
		PORTA = 0b11111101;
		_delay_ms(1000);
		PORTA = 0b01111111;
		_delay_ms(1000);
		PORTA = 0b11011111;
	}
	else if(level == 4)
	{
		PORTA = 0b11111101;
		_delay_ms(1000);
		PORTA = 0b01111111;
		_delay_ms(1000);
		PORTA = 0b11011111;
		_delay_ms(1000);
		PORTA = 0b11111110;
	}
	else if(level == 5)
	{
		PORTA = 0b11111101;
		_delay_ms(1000);
		PORTA = 0b01111111;
		_delay_ms(1000);
		PORTA = 0b11011111;
		_delay_ms(1000);
		PORTA = 0b11111110;
		_delay_ms(1000);
		PORTA = 0b11110111;
	}
}

int check(int sequence, int answer)																			// function for comparing input with sequence displayed
{
	if (sequence == answer)																					// if an input is correct, 1 (true) is returned
	{
		return 1;
	}
	return 0;																								// otherwise false is returned
}

int checkResult(int level)																					// function that checks all inputs
{
	int res = 1;																							// at the beginning result is set to 1 (true)
	for (int i = 0; i < level; i++)																			// check all inputs in current level
	{
		res = check(results[i], levels[i]);																	// function for check is used to compare input and sequence
		if (res == 0)																						// if incorrect input is found, breaks out of the loop
		{
			break;
		}
	}
	return res;																								// method returns 1 (true) or 0 (false) depending on the user's input
}

ISR(PCINT0_vect, ISR_BLOCK)																					// interruption for taking input anytime
{
		if (counter == 0)																					// counter represents order of the input in a level
		{
			results[0] = PINB;																				// provided input is stored in array with results
			counter = 1;																					// counter is increased
		}
		else if (counter == 1 && PINB == levels[1])															//
		{
			results[1] = PINB;
			counter = 2;
		}
		else if (counter == 2 && PINB == levels[2])
		{
			results[2] = PINB;
			counter = 3;
		}
		else if (counter == 3 && PINB == levels[3])
		{
			results[3] = PINB;
			counter = 4;
		}
		else if (counter == 4 && PINB == levels[4])
		{
			results[4] = PINB;
		}
}

