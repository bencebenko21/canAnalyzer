/*
 * init.c
 *
 * Created: 8/27/2025 3:12:15 PM
 *  Author: Bence Benko
 */ 

#define 

#include "init.h"
#include <avr/interrupt.h>

void timerOvfInit(void)
{
	TCCR0A = 0<<CS02 | 1<<CS01 | 1<<CS00; //set an interrupt time of 2ms
	TIMSK0 = 1<<TOIE0; // enable interrupt
	sei(); 
	
}