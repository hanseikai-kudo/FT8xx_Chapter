#include <avr/io.h>
#include "def.h"
#include "spi.h"







void SPI_Init(void)
{
	outport(SPCR,0x50);//01010000
}



void SPI_Write(unsigned char data)
{
	outport( SPDR,data);
	loop_until_bit_is_set(SPSR,SPIF);//sbis
}



unsigned char SPI_Read(void)
{
	outport( SPDR,0xFF);
	loop_until_bit_is_set(SPSR,SPIF);//sbis
	return inp(SPDR);
}

