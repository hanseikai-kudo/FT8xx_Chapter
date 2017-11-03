/* Chapert
 * avr8-ft8xx.c
 *
 * Created: 2017/09/23 
 * Author : ladybug
 */ 

#include <avr/io.h>
#include "spi.h"
#include "def.h"
#include "ft8xx.h"

//------------------------------------------------

#include <avr/pgmspace.h> 

#define CHAPTER_0 1

#define CHAPTER_1A 0 //FTDI LOGO
#define CHAPTER_1B 0 //'F''T' disp
#define CHAPTER_1C 0 //'F''T' disp move bgcolor
#define CHAPTER_2A 0 //Point disp move bgcolor
#define CHAPTER_2B 0 //Point,Line disp move bgcolor
#define CHAPTER_2C 1




void UserWait( unsigned long time )
{
//	return;

	while( time-- )
	{
		_delay_us(1);
	};

}









void PortInit( void )
{

//	outport(PORTB,0xFF);
	outport(DDRB,0xAD);//10101101
	outport(PORTB,0xFE);

	outport( PORTD,0xFF );
	outport( DDRD,0xFE );
	outport( PORTD,0x0F );

	outport( PORTC,0xFF );
	outport( DDRC,0x00 );
	outport( PORTC,0xFF );

	SPI_Init();

}





int main(void)
{
	unsigned int cmdOffset = 0x0000;												// Used to navigate command rung buffer
	unsigned int cmdBufferRd = 0x0000;											// Used to navigate command ring buffer
	unsigned int cmdBufferWr = 0x0000;											// Used to navigate command ring buffer


	if(CHAPTER_0)
	{
		PortInit();

		UserWait(100000);
		UserWait(100000);
		UserWait(100000);
		UserWait(100000);

		HostCommand(HOST_CLKINT,0,0);//send command to "CLKEXT" to FT81X 
		HostCommand(HOST_ACTIVE,0,0);//send host command "ACTIVE" to FT81X 
		UserWait(100000);
		UserWait(100000);


		HostMemWriteByte(REG_CPURESET, 0x01); 
	//	PORTB0_Hi();
		_delay_ms(10);
	//	PORTB0_Low();
		HostMemWriteByte(REG_CPURESET, 0x00); 

	// Now start clocking data to the LCD panel
		HostMemWriteByte(REG_PCLK, 7);
		HostMemWriteByte(REG_DITHER, 0x00);
	/* Configure display registers - demonstration for WQVGA resolution */ 
		HostMemWriteWord(REG_HSIZE, 480); 
		HostMemWriteWord(REG_HCYCLE, 531); 
		HostMemWriteWord(REG_HOFFSET, 51); 
		HostMemWriteWord(REG_HSYNC0, 8); 
		HostMemWriteWord(REG_HSYNC1, 43); 
		HostMemWriteWord(REG_VSIZE, 272); 
		HostMemWriteWord(REG_VCYCLE, 288); 
		HostMemWriteWord(REG_VOFFSET, 12); 
		HostMemWriteWord(REG_VSYNC0, 4); 
		HostMemWriteWord(REG_VSYNC1, 14); 
		HostMemWriteByte(REG_SWIZZLE, 0); 
		HostMemWriteByte(REG_PCLK_POL, 1); 


	//	HostMemWriteByte(REG_GPIO_DIR, 0x80); 
	//	HostMemWriteByte(REG_GPIO, 0x80); 
	//	HostMemWriteByte(REG_PWM_DUTY, 128); 

		HostMemWriteDoubleWord( REG_GPIO_DIR, 0x00000080 );
		HostMemWriteDoubleWord( REG_GPIO, 0x00000080 );

		HostMemWriteDoubleWord( REG_PWM_DUTY, 0x00000080 );
	}


	//while(1)
	if(CHAPTER_1A)
	{
		do
		{
			cmdBufferRd = HostMemReadWord(REG_CMD_READ);
			cmdBufferWr = HostMemReadWord(REG_CMD_WRITE);
		}while (cmdBufferWr != cmdBufferRd);
		cmdOffset = cmdBufferWr;

		HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (CMD_DLSTART));
		cmdOffset = incCMDOffset(cmdOffset, 4);

		HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_CLEAR_RGB | WHITE));
		cmdOffset = incCMDOffset(cmdOffset, 4);

		HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_CLEAR | CLR_COL | CLR_STN | CLR_TAG));
		cmdOffset = incCMDOffset(cmdOffset, 4);

		HostMemWriteDoubleWord( RAM_CMD + cmdOffset, (CMD_LOGO));
		cmdOffset = incCMDOffset(cmdOffset, 4);

		HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (CMD_SWAP));
		cmdOffset = incCMDOffset(cmdOffset, 4);

		HostMemWriteWord(REG_CMD_WRITE, cmdOffset);

		do
		{
			cmdBufferRd = HostMemReadWord(REG_CMD_READ);
			cmdBufferWr = HostMemReadWord(REG_CMD_WRITE);
		}while (cmdBufferWr != cmdBufferRd);

		while(1);
	}


	if(CHAPTER_1B)
	{
		do
		{
			cmdBufferRd = HostMemReadWord(REG_CMD_READ);
			cmdBufferWr = HostMemReadWord(REG_CMD_WRITE);
		}while (cmdBufferWr != cmdBufferRd);
		cmdOffset = cmdBufferWr;

		HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (CMD_DLSTART));
		cmdOffset = incCMDOffset(cmdOffset, 4);

		HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_CLEAR_RGB | BLUE));
		cmdOffset = incCMDOffset(cmdOffset, 4);

		HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_COLOR_RGB | WHITE));
		cmdOffset = incCMDOffset(cmdOffset, 4);

		HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_CLEAR | CLR_COL | CLR_STN | CLR_TAG));
		cmdOffset = incCMDOffset(cmdOffset, 4);


		HostMemWriteDoubleWord( RAM_CMD + cmdOffset, (CMD_ROMFONT));
		cmdOffset = incCMDOffset(cmdOffset, 4);
		HostMemWriteDoubleWord( RAM_CMD + cmdOffset, (2));
		cmdOffset = incCMDOffset(cmdOffset, 4);
		HostMemWriteDoubleWord( RAM_CMD + cmdOffset, (34));
		cmdOffset = incCMDOffset(cmdOffset, 4);


		HostMemWriteDoubleWord(RAM_CMD + cmdOffset, BITMAP_HANDLE(2));
		cmdOffset = incCMDOffset(cmdOffset, 4);

		HostMemWriteDoubleWord(RAM_CMD + cmdOffset, BEGIN_BITMAPS );
		cmdOffset = incCMDOffset(cmdOffset, 4);
		HostMemWriteDoubleWord(RAM_CMD + cmdOffset, VERTEX2II(0,0, 2, 'F'));
		cmdOffset = incCMDOffset(cmdOffset, 4);

		HostMemWriteDoubleWord(RAM_CMD + cmdOffset, VERTEX2II(64,0, 2, 'T'));
		cmdOffset = incCMDOffset(cmdOffset, 4);


		HostMemWriteDoubleWord(RAM_CMD + cmdOffset, DL_END);
		cmdOffset = incCMDOffset(cmdOffset, 4);

		HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_DISPLAY));
		cmdOffset = incCMDOffset(cmdOffset, 4);

		HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (CMD_SWAP));
		cmdOffset = incCMDOffset(cmdOffset, 4);

		HostMemWriteWord(REG_CMD_WRITE, cmdOffset);

		do
		{
			cmdBufferRd = HostMemReadWord(REG_CMD_READ);
			cmdBufferWr = HostMemReadWord(REG_CMD_WRITE);
		}while (cmdBufferWr != cmdBufferRd);
		cmdOffset = cmdBufferWr;

		while(1);
	}



	if(CHAPTER_1C)
	{
		unsigned long color;
		signed long point_x = 0;
		signed long point_y = 0;
		signed long delta_x = 2;
		signed long delta_y = 1;

		long rr=0,gg=0,bb=0;

		while(1)
		{
			point_x += delta_x;
			point_y += delta_y;

			if( point_x >= 479 )delta_x *= -1;
			if( point_x <= 0 )delta_x *= -1;
			if( point_y >= 271 )delta_y *= -1;
			if( point_y <= 0 )delta_y *= -1;

			bb = (long)(( (53) *(point_x) )/100);
			gg = (long)(( (94) *(point_y) )/100);

			do
			{
				cmdBufferRd = HostMemReadWord(REG_CMD_READ);
				cmdBufferWr = HostMemReadWord(REG_CMD_WRITE);
			}while (cmdBufferWr != cmdBufferRd);
			cmdOffset = cmdBufferWr;

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (CMD_DLSTART));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			color = RGB( 128,  gg, bb );
			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_CLEAR_RGB | color));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			color = RGB( 255,  0, 0 );
			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_COLOR_RGB | (color)));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_CLEAR | CLR_COL | CLR_STN | CLR_TAG));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord( RAM_CMD + cmdOffset, (CMD_ROMFONT));
			cmdOffset = incCMDOffset(cmdOffset, 4);
			HostMemWriteDoubleWord( RAM_CMD + cmdOffset, (2));
			cmdOffset = incCMDOffset(cmdOffset, 4);
			HostMemWriteDoubleWord( RAM_CMD + cmdOffset, (34));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, BEGIN_BITMAPS );
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, VERTEX2II(point_x, 0, 2, 'F'));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, VERTEX2II(32,point_y, 2, 'T'));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, DL_END);
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_DISPLAY));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (CMD_SWAP));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteWord(REG_CMD_WRITE, cmdOffset);

			do
			{
				cmdBufferRd = HostMemReadWord(REG_CMD_READ);
				cmdBufferWr = HostMemReadWord(REG_CMD_WRITE);
			}while (cmdBufferWr != cmdBufferRd);
			cmdOffset = cmdBufferWr;
		}
		while(1);
	}



	if(CHAPTER_2A)
	{
		unsigned long color;
		signed long point_x = 0;
		signed long point_y = 0;
		signed long delta_x = 2;
		signed long delta_y = 1;

		long rr=0,gg=0,bb=0;

		while(1)
		{
			point_x += delta_x;
			point_y += delta_y;

			if( point_x >= 479 )delta_x *= -1;
			if( point_x <= 0 )delta_x *= -1;
			if( point_y >= 271 )delta_y *= -1;
			if( point_y <= 0 )delta_y *= -1;

			bb = (long)(( (53) *(point_x) )/100);
			gg = (long)(( (94) *(point_y) )/100);

			do
			{
				cmdBufferRd = HostMemReadWord(REG_CMD_READ);
				cmdBufferWr = HostMemReadWord(REG_CMD_WRITE);
			}while (cmdBufferWr != cmdBufferRd);
			cmdOffset = cmdBufferWr;

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (CMD_DLSTART));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			color = RGB( 128,  gg, bb );
			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_CLEAR_RGB | color));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			color = RGB( 255,  0, 0 );
			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_COLOR_RGB | (color)));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_CLEAR | CLR_COL | CLR_STN | CLR_TAG));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, BITMAP_HANDLE(2));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, BEGIN_POINTS );
			cmdOffset = incCMDOffset(cmdOffset, 4);
			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, POINT_SIZE(16*16) );
			cmdOffset = incCMDOffset(cmdOffset, 4);
			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, VERTEX2II(point_x,point_y, 2, 0));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, DL_END);
			cmdOffset = incCMDOffset(cmdOffset, 4);




			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_DISPLAY));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (CMD_SWAP));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteWord(REG_CMD_WRITE, cmdOffset);

			do
			{
				cmdBufferRd = HostMemReadWord(REG_CMD_READ);
				cmdBufferWr = HostMemReadWord(REG_CMD_WRITE);
			}while (cmdBufferWr != cmdBufferRd);
			cmdOffset = cmdBufferWr;
		}
		while(1);
	}



	if(CHAPTER_2B)
	{
		unsigned long color;
		signed long point_x = 0;
		signed long point_y = 0;
		signed long delta_x = 2;
		signed long delta_y = 1;

		long rr=0,gg=0,bb=0;

		while(1)
		{
			point_x += delta_x;
			point_y += delta_y;

			if( point_x >= 479 )delta_x *= -1;
			if( point_x <= 0 )delta_x *= -1;
			if( point_y >= 271 )delta_y *= -1;
			if( point_y <= 0 )delta_y *= -1;

			bb = (long)(( (53) *(point_x) )/100);
			gg = (long)(( (94) *(point_y) )/100);

			do
			{
				cmdBufferRd = HostMemReadWord(REG_CMD_READ);
				cmdBufferWr = HostMemReadWord(REG_CMD_WRITE);
			}while (cmdBufferWr != cmdBufferRd);
			cmdOffset = cmdBufferWr;

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (CMD_DLSTART));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			color = RGB( 128,  gg, bb );
			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_CLEAR_RGB | color));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			color = RGB( 255,  0, 0 );
			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_COLOR_RGB | (color)));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_CLEAR | CLR_COL | CLR_STN | CLR_TAG));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord( RAM_CMD + cmdOffset, VERTEX_FORMAT(0) );
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, BITMAP_HANDLE(2));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, BEGIN_POINTS );
			cmdOffset = incCMDOffset(cmdOffset, 4);
			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, POINT_SIZE(16*16) );
			cmdOffset = incCMDOffset(cmdOffset, 4);
			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, VERTEX2II(point_x,point_y, 0, 0));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, BEGIN_LINES );
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, LINE_WIDTH(8*16) );
			cmdOffset = incCMDOffset(cmdOffset, 4);
			color = RGB( 255,  0, 255 );
			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_COLOR_RGB | (color)));
			cmdOffset = incCMDOffset(cmdOffset, 4);
			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, VERTEX2F(240, 136));
			cmdOffset = incCMDOffset(cmdOffset, 4);
			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, VERTEX2F(point_x, point_y));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, DL_END);
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (DL_DISPLAY));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteDoubleWord(RAM_CMD + cmdOffset, (CMD_SWAP));
			cmdOffset = incCMDOffset(cmdOffset, 4);

			HostMemWriteWord(REG_CMD_WRITE, cmdOffset);

			do
			{
				cmdBufferRd = HostMemReadWord(REG_CMD_READ);
				cmdBufferWr = HostMemReadWord(REG_CMD_WRITE);
			}while (cmdBufferWr != cmdBufferRd);
			cmdOffset = cmdBufferWr;
		}
		while(1);
	}


}


