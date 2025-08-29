/*
 * USART.h
 *
 * Created: 8/29/2025 1:36:48 PM
 *  Author: Bence Benko
 */ 

#include <avr/io.h>

#define FOSC 8000000// Clock Speed
#define BAUD 9600 // BAUD rate is determined with distance - longer distance requires less speed -, and percentage of failure
#define MYUBRR FOSC/16/BAUD-1 // datasheet page 174, normal speed setting

void USART_init(uint16_t ubrr);
void USART_transmit(uint8_t data);
uint8_t USART_receive();
void USART_transmit_string(uint8_t* str);
void USART_transmit_number(uint8_t number);

#ifndef USART_H_
#define USART_H_





#endif /* USART_H_ */