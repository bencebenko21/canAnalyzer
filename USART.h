/* 
 * File:   USART.h
 * Author: benko
 *
 * Created on November 3, 2025, 1:47 PM
 */

#define FOSC 8000000// Clock Speed
#define BAUD 9600 // a BAUD ratet a t?vol?sg ?s a sebess?g hat?roza meg, nagy t?vols?gon kisebb sebess?g kell, illetve a sz?zal?kos hibahat?r alapj?n d?nt?k
#define MYUBRR FOSC/16/BAUD-1 // datasheet page 174, normal speed setting


void USART_init(uint16_t);
void USART_transmit(uint8_t);
uint8_t USART_receive();
void USART_transmit_string(uint8_t*);
void USART_transmit_number(uint8_t number);

#ifndef USART_H
#define	USART_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* USART_H */

