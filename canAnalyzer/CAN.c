/*
 * CAN.c
 *
 * Created: 9/2/2025 6:40:15 PM
 *  Author: benko
 */ 

#include "CAN.h"

void CAN_init(void)
{
	CANGCON = (1 << SWRES); //Reset CAN controller
	while (CANGCON & (1 << SWRES)); //wait for reset
	CANGCON = (1 << ENASTB); //enable CAN controller 
	while (!(CANGSTA & (1 << ENFG))); //wait for enable
	
	//Configure bit timing
	
	//for 500Kbps bit rate and 8Mhz clock i have 8M/500k=16Tq to divide
	// BRP = 0 
	// SYNS = 0 (1Tq)
	// PRS = 4 (5Tq)
	// PHS1 = 6 (7Tq)
	// PHS2 = 4 (5TQ) (? PHS1 and ? INFORMATION PROCESSING TIME (2))
	// SMP = 0
	CANBT1 = 0x00;
	
}