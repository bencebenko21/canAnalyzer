/*
 * init.c
 *
 * Created: 8/27/2025 3:12:15 PM
 *  Author: Bence Benko
 */ 

#include "init.h"
#include <avr/interrupt.h>

//PORTD may not be initialized, as only CAN pins are connected and they are self initialize with the CAN controller activated
//PORTE may not be initialized, as only USART RX and TX are connected and they are initialized with USART activation

void timerOvfInit(void)
{
	TCCR0A = 0<<CS02 | 1<<CS01 | 1<<CS00; //set an interrupt time of 2ms
	TIMSK0 = 1<<TOIE0; // enable interrupt
	sei(); 
	
}