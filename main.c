/*
 * canAnalyzer.c
 *
 * Created: 8/27/2025 3:10:27 PM
 * Author : Bence Benko
 */ 

#define F_CPU 8000000UL
#define BAUD 11500
#define MYUBRR ((F_CPU / (16UL * BAUD)) - 1)


#include <avr/io.h>
#include <stdio.h>
#include "main.h"


int main(void)
{
    //adc_init();
	USART_init(MYUBRR);
	timerOvfInit();
    CAN_init();
	
    while (1) 
    {
    }
}