/* Chapert
 * ft8xx.c
 *
 * Created: 2017/09/23 
 * Author : ladybug
 */ 
#include <avr/io.h>
#include "def.h"
#include "ft8xx.h"
#include "spi.h"





unsigned char TransByte( unsigned char byte )
{
	unsigned short rcv;

	outport( SPDR,byte);
	loop_until_bit_is_set(SPSR,SPIF);//sbis
	return inp(SPDR);
}



void HostCommand( unsigned char cmd, unsigned char p1, unsigned char p2 )
{
	FT8XX_nCS_Low();

		TransByte( cmd );
		TransByte( p1 );
		TransByte( p2 );

	FT8XX_nCS_Hi();

	return;
}



void HostMemWrite_RomBurst( unsigned long adr, unsigned char *ptr,unsigned long size )
{
	unsigned long addres = adr | 0x00800000;

	FT8XX_nCS_Low();

		TransByte( (unsigned char)((addres & 0x00FF0000)>>16) );
		TransByte( (unsigned char)((addres & 0x0000FF00)>>8) );
		TransByte( (unsigned char)(addres & 0x000000FF) );

		while( size )
		{
			TransByte( (unsigned char)( pgm_read_byte(*ptr++) ) );
		};

	FT8XX_nCS_Hi();

	return;
}



void HostMemWriteByte( unsigned long adr, unsigned char p1 )
{
	unsigned long addres = adr | 0x00800000;

	FT8XX_nCS_Low();

		TransByte( (unsigned char)((addres & 0x00FF0000)>>16) );
		TransByte( (unsigned char)((addres & 0x0000FF00)>>8) );
		TransByte( (unsigned char)(addres & 0x000000FF) );
		TransByte( (unsigned char)(p1) );

	FT8XX_nCS_Hi();

	return;
}

void HostMemWriteWord( unsigned long adr, unsigned short word )
{
	unsigned long addres = adr | 0x00800000;

	FT8XX_nCS_Low();

		TransByte( (unsigned char)((addres & 0x00FF0000)>>16) );
		TransByte( (unsigned char)((addres & 0x0000FF00)>>8) );
		TransByte( (unsigned char)(addres & 0x000000FF) );
		TransByte( (unsigned char)(word&0x00FF) );
		TransByte( (unsigned char)((word&0xFF00)>>8) );

	FT8XX_nCS_Hi();

	return;
}


void HostMemWriteDoubleWord( unsigned long adr, unsigned long dword )
{
	unsigned long addres = adr | 0x00800000;

	FT8XX_nCS_Low();

		TransByte( (unsigned char)((addres & 0x00FF0000)>>16) );
		TransByte( (unsigned char)((addres & 0x0000FF00)>>8) );
		TransByte( (unsigned char)(addres & 0x000000FF) );
		TransByte( (unsigned char)(dword&0x000000FF) );
		TransByte( (unsigned char)((dword&0x0000FF00)>> 8) );
		TransByte( (unsigned char)((dword&0x00FF0000)>>16) );
		TransByte( (unsigned char)((dword&0xFF000000)>>24) );

	FT8XX_nCS_Hi();
	return;
}



unsigned char HostMemReadByte( unsigned long adr )
{
	unsigned long addres = adr | 0x00000000;
	unsigned char data;

	FT8XX_nCS_Low();

		TransByte( (unsigned char)((addres & 0x00FF0000)>>16) );
		TransByte( (unsigned char)((addres & 0x0000FF00)>>8) );
		TransByte( (unsigned char)(addres & 0x000000FF) );

		TransByte( 0x00 );//dummy byte

		data = TransByte( 0x00 );

	FT8XX_nCS_Hi();

	return data;
}

unsigned short HostMemReadWord( unsigned long adr )
{
	unsigned long addres = adr | 0x00000000;
	unsigned char H_byte;
	unsigned char L_byte;

	FT8XX_nCS_Low();

		TransByte( (unsigned char)((addres & 0x00FF0000)>>16) );
		TransByte( (unsigned char)((addres & 0x0000FF00)>>8) );
		TransByte( (unsigned char)(addres & 0x000000FF) );

		TransByte( 0x00 );//dummy byte

		L_byte = TransByte( 0x00 );//Low byte
		H_byte = TransByte( 0x00 );//Hi  byte

	FT8XX_nCS_Hi();

	return ((unsigned short)(H_byte * 256 + L_byte)) ;
}


unsigned long HostMemReadDoubleWord( unsigned long adr )
{
	unsigned long addres = adr | 0x00000000;
	unsigned char ary[4];
	unsigned long value;

	FT8XX_nCS_Low();

		TransByte( (unsigned char)((addres & 0x00FF0000)>>16) );
		TransByte( (unsigned char)((addres & 0x0000FF00)>>8) );
		TransByte( (unsigned char)(addres & 0x000000FF) );

		TransByte( 0x00 );//dummy byte

		ary[3]= TransByte( 0x00 );
		ary[2]= TransByte( 0x00 );
		ary[1]= TransByte( 0x00 );
		ary[0]= TransByte( 0x00 );

	FT8XX_nCS_Hi();

	value = (((unsigned long)(ary[0]))<<24)|(((unsigned long)(ary[1]))<<16)|(((unsigned long)(ary[2]))<<8)|((unsigned long)(ary[3]));

	return value;
}



unsigned int incCMDOffset(unsigned int currentOffset, unsigned char commandSize)
{
	unsigned int newOffset;
	newOffset = currentOffset + commandSize;
	if(newOffset > 4095)
	{
		newOffset = (newOffset - 4096);
	}
	return newOffset;
}










