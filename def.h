#ifndef _DEF_H_

#define _DEF_H_


#define F_CPU 8000000UL
#include <util/delay.h>


typedef enum
{
	true = 1,
	false = 0,
}bool;


#define BV(bit)          (1<<(bit))
#define cbi(addr,bit)    addr&=~_BV(bit)
#define sbi(addr,bit)    addr|=_BV(bit)
#define outp(data,addr)  addr=(data)
#define inp(addr)        (addr)
#define outb(addr,data)  addr=(data)
#define inb(addr)        (addr)
#define PRG_RDB(addr)    (pgm_read_byte(addr))
#define PRG_RDW(addr)    (pgm_read_word(addr))
#define outport(port,d) port = d
#define nop() __asm__ __volatile__ ("nop")



#define FT8XX_nCS_Low() cbi(PORTB,2)
#define FT8XX_nCS_Hi() sbi(PORTB,2)

#define PORTB0_Low() cbi(PORTB,0)
#define PORTB0_Hi() sbi(PORTB,0)





#endif

