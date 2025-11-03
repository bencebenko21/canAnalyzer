/*
 * CAN.c
 *
 * Created: 9/2/2025 6:40:15 PM
 *  Author: benko
 */ 

#include <avr/io.h>
#include "CAN.h"

void CAN_init(void)
{
	CANGCON = (1 << SWRES); //Reset CAN controller
	while (CANGCON & (1 << SWRES)); //wait for reset
	CANGCON = (1 << ENASTB); //enable CAN controller 
	while (!(CANGSTA & (1 << ENFG))); //wait for enable
	
	//Configure bit timing
	
	// I have 8Mhz clock frequency, and my target is 250Kbit/s speed. 1 bit speed is 1/250= 4uS
    // To calculate the required time quanta, which is 16, so 4us/16Tq = 250 ns
    // The required prescaler is 8Mhz/250ns= 2 (BP+1) so the prescaler is 1
    
	CANBT1 = 0x02;
    
    // Now i need to divide the TQ up
    //Sync segment: 1 TQ (fixed) Propagation: 4 TQ Phase1 : 6 TQ Phase2 : 4 TQ
    
	CANBT2 = 0x28;
	CANBT3 = 0x35;
    
    CANPAGE = (0<<MOBNB0);      //select mob0
    CANCDMOB = 0x00;            // disable first
    CANSTMOB = 0x00;            // clear status
    CANIDM1 = 0x00;             // set 0 for mask to accept all messages
    CANIDM2 = 0x00;             
    CANIDM3 = 0x00;
    CANIDM4 = 0x00;
    CANCDMOB = (1<<CONMOB1);    //Enable RX - Datasheet page 263
    
    CANGCON = (1 << ENASTB);    // Enable CAN
    while (!(CANGSTA & (1 << ENFG)));   
    
}
uint8_t CAN_receive(uint32_t *id, uint8_t *data)
{
    CANPAGE = 0x00;                        // MOb0
    if (!(CANSTMOB & (1<<RXOK))) return 0; // no new frame
    *id = ((uint32_t)CANIDT1 << 3) | (CANIDT2 >> 5);
    uint8_t len = CANCDMOB & 0x0F;
    for (uint8_t i = 0; i < len; i++) data[i] = CANMSG;

    CANSTMOB = 0x00;                       // clear RX flag
    CANCDMOB = (1<<CONMOB1);               // re-enable reception
    return len;
}