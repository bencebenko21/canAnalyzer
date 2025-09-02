/*
 * canAnalyzer.c
 *
 * Created: 8/27/2025 3:10:27 PM
 * Author : Bence Benko
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdio.h>
#include "main.h"


int main(void)
{
    adc_init();
	USART_init();
	timerOvfInit();
	
    while (1) 
    {
    }
}
ISR(TIMER0_OVF_vect)
{
	
}
