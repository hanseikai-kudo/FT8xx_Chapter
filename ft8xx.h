
#ifndef _FT8XX_H_

#define _FT8XX_H_

#define FT81X 1


#define HOST_ACTIVE			0x00
#define HOST_STANDBY		0x41
#define HOST_SLEEP			0x42
#define HOST_PWRDOWN		0x50
#define HOST_CLKEXT			0x44
#define HOST_CLK48M			0x62
#define HOST_CLK36M			0x61
#define HOST_CORERST		0x68

#define HOST_PD_ROMS		0x49
#define HOST_CLKINT			0x48
#define HOST_CLKSEL			0x61
#define HOST_PINDRIVE		0x70
#define HOST_PIN_PD_STATE 	0x71

//offset 
#define RAM_G		0x00000000
#define RAM_DL		0x00300000
#define RAM_CMD		0x00308000UL

#define	REG_ID					0x302000
#define	REG_FRAMES				0x302004
#define	REG_CLOCK				0x302008
#define	REG_FREQUENCY			0x30200C
#define	REG_RENDERMODE			0x302010
#define	REG_SNAPY				0x302014
#define	REG_SNAPSHOT			0x302018
#define	REG_SNAPFORMAT			0x30201C
#define	REG_CPURESET			0x302020
#define	REG_TAP_CRC				0x302024
#define	REG_TAP_MASK			0x302028
#define	REG_HCYCLE				0x30202C
#define	REG_HOFFSET				0x302030
#define	REG_HSIZE				0x302034
#define	REG_HSYNC0				0x302038
#define	REG_HSYNC1				0x30203C
#define	REG_VCYCLE				0x302040
#define	REG_VOFFSET				0x302044
#define	REG_VSIZE				0x302048
#define	REG_VSYNC0				0x30204C
#define	REG_VSYNC1				0x302050
#define	REG_DLSWAP				0x302054
#define	REG_ROTATE				0x302058
#define	REG_OUTBITS				0x30205C
#define	REG_DITHER				0x302060
#define	REG_SWIZZLE				0x302064
#define	REG_CSPREAD				0x302068
#define	REG_PCLK_POL			0x30206C
#define	REG_PCLK				0x302070
#define	REG_TAG_X				0x302074
#define	REG_TAG_Y				0x302078
#define	REG_TAG					0x30207C
#define	REG_VOL_PB				0x302080
#define	REG_VOL_SOUND			0x302084
#define	REG_SOUND				0x302088
#define	REG_PLAY				0x30208C
#define	REG_GPIO_DIR			0x302090
#define	REG_GPIO				0x302094
#define	REG_GPIOX_DIR			0x302098
#define	REG_GPIOX				0x30209C
#define	REG_INT_FLAGS			0x3020A8
#define	REG_INT_EN				0x3020Ac
#define	REG_INT_MASK			0x3020B0
#define	REG_PLAYBACK_START		0x3020B4
#define	REG_PLAYBACK_LENGTH		0x3020B8
#define	REG_PLAYBACK_READPTR	0x3020BC
#define	REG_PLAYBACK_FREQ		0x3020C0
#define	REG_PLAYBACK_FORMAT		0x3020C4
#define	REG_PLAYBACK_LOOP		0x3020C8
#define	REG_PLAYBACK_PLAY		0x3020CC
#define	REG_PWM_HZ				0x3020D0
#define	REG_PWM_DUTY			0x3020D4
#define	REG_MACRO_0				0x3020D8
#define	REG_MACRO_1				0x3020DC
#define	REG_CMD_READ			0x3020F8
#define	REG_CMD_WRITE			0x3020FC
#define	REG_CMD_DL				0x302100
#define	REG_TOUCH_MODE			0x302104
#define	REG_TOUCH_ADC_MODE		0x302108
#define	REG_TOUCH_CHARGE		0x30210C
#define	REG_TOUCH_SETTLE		0x302110
#define	REG_TOUCH_OVERSAMPLE	0x302114
#define	REG_TOUCH_RZTHRESH		0x302118
#define	REG_TOUCH_RAW_XY		0x30211C
#define	REG_TOUCH_RZ			0x302120
#define	REG_TOUCH_SCREEN_XY		0x302124
#define	REG_TOUCH_TAG_XY		0x302128
#define	REG_TOUCH_TAG			0x30212C
#define	REG_TOUCH_TAG1_XY		0x302130
#define	REG_TOUCH_TAG1			0x302134
#define	REG_TOUCH_TAG2_XY		0x302138
#define	REG_TOUCH_TAG2			0x30213C
#define	REG_TOUCH_TAG3_XY		0x302140
#define	REG_TOUCH_TAG3			0x302144
#define	REG_TOUCH_TAG4_XY		0x302148
#define	REG_TOUCH_TAG4			0x30214C
#define	REG_TOUCH_TRANSFORM_A	0x302150
#define	REG_TOUCH_TRANSFORM_B	0x302154
#define	REG_TOUCH_TRANSFORM_C	0x302158
#define	REG_TOUCH_TRANSFORM_D	0x30215C
#define	REG_TOUCH_TRANSFORM_E	0x302160
#define	REG_TOUCH_TRANSFORM_F	0x302164
#define	REG_TOUCH_CONFIG		0x302168
#define	REG_CTOUCH_TOUCH4_X		0x30216C
#define	REG_BIST_EN				0x302174
#define	REG_TRIM				0x302180
#define	REG_ANA_COMP			0x302184
#define	REG_SPI_WIDTH			0x302188
#define	REG_TOUCH_DIRECT_XY		0x30218C
#define	REG_CTOUCH_TOUCH2_XY	0x30218C
#define	REG_TOUCH_DIRECT_Z1Z	0x302190
#define	REG_CTOUCH_TOUCH3_XY	0x302190
#define	REG_DATESTAMP			0x302564
#define	REG_CMDB_SPACE			0x302574
#define	REG_CMDB_WRITE			0x302578




// Display list commands to be embedded in Graphics Processor
#define DL_ALPHA_FUNC			0x09000000UL
#define DL_BITMAP_HANDLE		0x05000000UL
#define DL_BITMAP_LAYOUT		0x07000000UL
#define DL_BITMAP_SIZE			0x08000000UL
#define DL_BITMAP_SOURCE		0x01000000UL
#define DL_BITMAP_TFORM_A		0x15000000UL
#define DL_BITMAP_TFORM_B		0x16000000UL
#define DL_BITMAP_TFORM_C		0x17000000UL
#define DL_BITMAP_TFORM_D		0x18000000UL
#define DL_BITMAP_TFORM_E		0x19000000UL
#define DL_BITMAP_TFORM_F		0x1A000000UL
#define DL_BLEND_FUNC			0x0B000000UL
#define DL_BEGIN				0x1F000000UL
#define DL_CALL					0x1D000000UL
#define DL_CLEAR				0x26000000UL
#define DL_CELL					0x06000000UL
#define DL_CLEAR_RGB			0x02000000UL
#define DL_CLEAR_STENCIL		0x11000000UL
#define DL_CLEAR_TAG			0x12000000UL
#define DL_COLOR_A				0x0F000000UL
#define DL_COLOR_MASK			0x20000000UL
#define DL_COLOR_RGB			0x04000000UL
#define DL_DISPLAY				0x00000000UL
#define DL_END					0x21000000UL
#define DL_JUMP					0x1E000000UL
#define DL_LINE_WIDTH			0x0E000000UL
#define DL_MACRO				0x25000000UL
#define DL_POINT_SIZE			0x0D000000UL
#define DL_RESTORE_CONTEXT  	0x23000000UL
#define DL_RETURN				0x24000000UL
#define DL_SAVE_CONTEXT			0x22000000UL
#define DL_SCISSOR_SIZE	 		0x1C000000UL
#define DL_SCISSOR_XY			0x1B000000UL
#define DL_STENCIL_FUNC			0x0A000000UL
#define DL_STENCIL_MASK			0x13000000UL
#define DL_STENCIL_OP			0x0C000000UL
#define DL_TAG					0x03000000UL
#define DL_TAG_MASK				0x14000000UL
#define DL_VERTEX2F				0x40000000UL
#define DL_VERTEX2II			0x02000000UL
#define DL_VERTEX_FORMAT		0x27000000UL



// Graphics Engine Commands
// Refer to the FT800 Programmers Guide
#define CMDBUF_SIZE			4096UL
#define CMD_APPEND			0xffffff1eUL
#define CMD_BGCOLOR			0xffffff09UL
#define CMD_BUTTON			0xffffff0dUL
#define CMD_CALIBRATE		0xffffff15UL
#define CMD_CLOCK			0xffffff14UL
#define CMD_COLDSTART		0xffffff32UL
#define CMD_DIAL			0xffffff2dUL
#define CMD_DLSTART			0xffffff00UL
#define CMD_FGCOLOR			0xffffff0aUL
#define CMD_GAUGE			0xffffff13UL
#define CMD_GETMATRIX		0xffffff33UL
#define CMD_GETPTR			0xffffff23UL
#define CMD_GRADCOLOR		0xffffff34UL
#define CMD_GRADIENT		0xffffff0bUL
#define CMD_INFLATE			0xffffff22UL
#define CMD_INTERRUPT		0xffffff02UL
#define CMD_KEYS			0xffffff0eUL
#define CMD_LOADIDENTITY	0xffffff26UL
#define CMD_LOADIMAGE		0xffffff24UL
#define CMD_LOGO			0xffffff31UL
#define CMD_MEMCPY			0xffffff1dUL
#define CMD_MEMCRC			0xffffff18UL
#define CMD_MEMSET			0xffffff1bUL
#define CMD_MEMWRITE		0xffffff1aUL
#define CMD_MEMZERO			0xffffff1cUL
#define CMD_NUMBER			0xffffff2eUL
#define CMD_PROGRESS		0xffffff0fUL
#define CMD_REGREAD			0xffffff19UL
#define CMD_ROTATE			0xffffff29UL
#define CMD_SCALE			0xffffff28UL
#define CMD_SCREENSAVER		0xffffff2fUL
#define CMD_SCROLLBAR		0xffffff11UL
#define CMD_SETFONT			0xffffff2bUL
#define CMD_SETMATRIX		0xffffff2aUL
#define CMD_SKETCH			0xffffff30UL
#define CMD_SLIDER			0xffffff10UL
#define CMD_SNAPSHOT		0xffffff1fUL
#define CMD_SPINNER			0xffffff16UL
#define CMD_STOP			0xffffff17UL
#define CMD_DLSTART			0xffffff00UL
#define CMD_SWAP			0xffffff01UL
#define CMD_TEXT			0xffffff0cUL
#define CMD_TOGGLE			0xffffff12UL
#define CMD_TRACK			0xffffff2cUL
#define CMD_TRANSLATE		0xffffff27UL

#define CMD_SETBITMAP		0xffffff43UL
#define CMD_ROMFONT			0xffffff3fUL

// Command and register value options
#define CLR_COL					0x4
#define CLR_STN					0x2
#define CLR_TAG					0x1
#define DECR					4UL
#define DECR_WRAP				7UL
#define DLSWAP_DONE				0UL
#define DLSWAP_FRAME			2UL
#define DLSWAP_LINE				1UL
#define DST_ALPHA				3UL
#define EDGE_STRIP_A			7UL
#define EDGE_STRIP_B			8UL
#define EDGE_STRIP_L			6UL
#define EDGE_STRIP_R			5UL
#define EQUAL					5UL
#define GEQUAL					4UL
#define GREATER					3UL
#define INCR					3UL
#define INCR_WRAP				6UL
#define INT_CMDEMPTY			32UL
#define INT_CMDFLAG				64UL
#define INT_CONVCOMPLETE		128UL
#define INT_PLAYBACK			16UL
#define INT_SOUND				8UL
#define INT_SWAP				1UL
#define INT_TAG					4UL
#define INT_TOUCH				2UL
#define INVERT					5UL
#define KEEP					1UL
#define L1						1UL
#define L4						2UL
#define L8						3UL
#define LEQUAL					2UL
#define LESS					1UL
#define LINEAR_SAMPLES			0UL
#define LINES					3UL
#define LINE_STRIP				4UL
#define NEAREST					0UL
#define NEVER					0UL
#define NOTEQUAL				6UL
#define ONE						1UL
#define ONE_MINUS_DST_ALPHA		5UL
#define ONE_MINUS_SRC_ALPHA		4UL
#define OPT_CENTER				1536UL 
#define OPT_CENTERX				512UL 
#define OPT_CENTERY				1024UL 
#define OPT_FLAT				256UL 
#define OPT_MONO				1UL
#define OPT_NOBACK				4096UL 
#define OPT_NODL				2UL
#define OPT_NOHANDS				49152UL
#define OPT_NOHM				16384UL
#define OPT_NOPOINTER			16384UL
#define OPT_NOSECS				32768UL
#define OPT_NOTICKS				8192UL 
#define OPT_RIGHTX				2048UL 
#define OPT_SIGNED				256UL 
#define PALETTED				8UL
#define PLAYCOLOR				0x00a0a080
#define FTPOINTS				2UL
#define RECTS					9UL
#define REPEAT					1UL
#define REPLACE					2UL
#define RGB332					4UL
#define RGB565					7UL
#define ARGB1555				0UL
#define SRC_ALPHA				2UL
#define TEXT8X8					9UL
#define TEXTVGA					10UL
#define TOUCHMODE_CONTINUOUS	3UL
#define TOUCHMODE_FRAME			2UL
#define TOUCHMODE_OFF			0UL
#define TOUCHMODE_ONESHOT		1UL
#define ULAW_SAMPLES			1UL
#define ZERO					0UL

#define BEGIN(md) (( DL_BEGIN & 0xFFFFFFF0 ) | (unsigned long )(md & 0x0000000F) )

#define BEGIN_BITMAPS			BEGIN(1)
#define BEGIN_POINTS			BEGIN(2)
#define BEGIN_LINES				BEGIN(3)
#define BEGIN_LINESTRIP			BEGIN(4)
#define BEGIN_EDGE_STRIP_R		BEGIN(5)
#define BEGIN_EDGE_STRIP_L		BEGIN(6)
#define BEGIN_EDGE_STRIP_A		BEGIN(7)
#define BEGIN_EDGE_STRIP_B		BEGIN(8)
#define BEGIN_RECTS				BEGIN(9)

#define VERTEX2II( x,y,h,c ) (0x80000000 | ((signed long)(x)<<21) | ((signed long)(y)<<12) | ((unsigned long)(h)<<7) | ((unsigned long)(c)) )

#define VERTEX2F( x,y ) (0x40000000 | ((((signed long)(x)&0x00007FFF)<<15) | ((signed long)(y)&0x00007FFF)) )
#define DEF_POS( x,y ) ( ((unsigned long)(x)<<16) | ((unsigned long )(y)) )
#define DEF_WH( w,h ) ( ((unsigned long)(w)<<16) | ((unsigned long )(h)) )

#define BITMAP_HANDLE(h) (DL_BITMAP_HANDLE|(0x0000001F & h)) 

#define BITMAP_LAYOUT(f,s,h) \
					(DL_BITMAP_LAYOUT | (((unsigned long )(f) & 0x0000001F)<<19) \
								 | (((unsigned long)(s) & 0x000003FF)<<9) \
								 | ((unsigned long )(h) & 0x000001FF) )

#define BITMAP_SIZE(f,wx,wy,w,h) \
					(DL_BITMAP_SIZE | (((unsigned long)(f) & 0x00000001)<<20) \
									| (((unsigned long)(wx) & 0x00000001)<<19) \
									| (((unsigned long)(wy) & 0x00000001) << 18) \
									| (((unsigned long)(w) & 0x000001FF) << 9) \
									| ((unsigned long)(h) & 0x000001FF)) 
#define POINT_SIZE( s )		( DL_POINT_SIZE | ((unsigned long)(s) & 0x00001FFF) )
#define LINE_WIDTH( s )		( DL_LINE_WIDTH | ((unsigned long)(s) & 0x00000FFF) )
#define VERTEX_FORMAT( f )	( DL_VERTEX_FORMAT | ((unsigned long)(f) & 0x00000007) )

#define BITMAP_SOURCE(a) (DL_BITMAP_SOURCE | (a & 0x003FFFFF) ) 
#define BITMAP_TFOM_A(a) (DL_BITMAP_TFORM_A | ((unsigned long)(a) & 0x0001FFFF) ) 
#define BITMAP_TFOM_B(a) (DL_BITMAP_TFORM_B | ((unsigned long)(a) & 0x0001FFFF) ) 
#define BITMAP_TFOM_C(a) (DL_BITMAP_TFORM_C | ((unsigned long)(a) & 0x0001FFFF) ) 
#define BITMAP_TFOM_D(a) (DL_BITMAP_TFORM_D | ((unsigned long)(a) & 0x0001FFFF) ) 
#define BITMAP_TFOM_E(a) (DL_BITMAP_TFORM_E | ((unsigned long)(a) & 0x0001FFFF) ) 
#define BITMAP_TFOM_F(a) (DL_BITMAP_TFORM_F | ((unsigned long)(a) & 0x0001FFFF) ) 

#define SCISSOR_XY(x,y)		(DL_SCISSOR_XY | (((unsigned long)x & 0x000007FF)<<11)|((unsigned long)y & 0x000007FF))
#define SCISSOR_SIZE(w,h)	(DL_SCISSOR_SIZE | (((unsigned long)w & 0x00000FFF)<<12)|((unsigned long)h & 0x00000FFF))

#define BLACK		0x000000UL		// Black
#define BLUE		0x0000FFUL		// Blue
#define RED			0xFF0000UL		// Red
#define PURPLE 		0xFF00FFUL		// Purple 
#define GREEN		0x00FF00UL		// Green
#define CYAN		0x00FFFFUL		// Cyan
#define YELLOW		0xFFFF00UL		// Yellow
#define WHITE		0xFFFFFFUL		// White

#define RGB(r,g,b)			( ((unsigned long)(r)<<16) |((unsigned long)(g)<<8) | (unsigned long)(b) )

unsigned int incCMDOffset(unsigned int currentOffset, unsigned char commandSize);
unsigned long HostMemReadDoubleWord( unsigned long adr );
unsigned short HostMemReadWord( unsigned long adr );
unsigned char HostMemReadByte( unsigned long adr );
void HostMemWriteDoubleWord( unsigned long adr, unsigned long dword );
void HostMemWriteWord( unsigned long adr, unsigned short word );
void HostMemWriteByte( unsigned long adr, unsigned char p1 );
void HostCommand( unsigned char cmd, unsigned char p1, unsigned char p2 );
unsigned char TransByte( unsigned char byte );

void HostMemWrite_RomBurst( unsigned long adr, unsigned char *ptr,unsigned long size );

#endif


