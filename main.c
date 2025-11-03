/*
 * canAnalyzer.c
 *
 * Created: 8/27/2025 3:10:27 PM
 * Author : Bence Benko
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "main.h"


    
int main(void)
{
    USART_init(MYUBRR);
    CAN_init();
    uint8_t data[8];
    uint32_t id;
    uint8_t len;
    char buf[64];
    
    USART_transmit_string("CAN ready \r\n");
	
    while (1) 
    {
        uint8_t len = CAN_receive(&id, data);
        if (len) {
            sprintf(buf, "ID:%03lX ", id);
            USART_transmit_string(buf);
            for (uint8_t i=0; i<len; i++) {
                sprintf(buf, "%02X ", data[i]);
                USART_transmit_string(buf);
            }
            USART_transmit_string("\r\n");
                 }
    }
}