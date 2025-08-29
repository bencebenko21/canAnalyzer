/*
 * ADC.c
 *
 * Created: 8/29/2025 1:58:15 PM
 *  Author: benko
 */ 

#include <avr/io.h>
#include "ADC.h"

void adc_init()
{
	ADMUX |= (0<<REFS0) | (0<<MUX0);
	ADCSRA |= (1<< ADPS2) | (1<<ADPS1) | (0<<ADPS0);
	ADCSRA |= (1<<ADEN);
}
uint16_t ADC_measure(uint8_t ch)
{
	ch=ch&0x07;
	ADMUX |= ch;
	ADCSRA |= (1<<ADSC);
	while(!(ADCSRA & (1<<ADIF)));
	return adc;
}