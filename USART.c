/*
 * USART.c
 *
 * Created: 8/29/2025 1:36:38 PM
 *  Author: Bence Benko
 */ 

#include <avr/io.h>
#include "USART.h"

void USART_init(uint16_t ubrr) // datasheet page 177
{
	/* Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(0<<UCSZ02);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<USBS0)|(1<<UCSZ01)|(1<<UCSZ00);
}
void USART_transmit(uint8_t data) // datasheet page 178
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) ) // datasheet page 189
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
}
uint8_t USART_receive() // datasheet page 181
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) )
	;
	/* Get and return received data from buffer */
	return UDR0;
}

void USART_transmit_string(uint8_t* str)
{
	
	while(*str)
	{
		while (*str != '\0') {           // transmit until string ending /0
			USART_transmit(*str);        // Transmit characters one-by-one
			str++;                       // increment pointer, thus the character in my string
		}
	}
}
/*
void USART_transmit_number(uint8_t number)
{
	USART_transmit('0'+number);
}*/