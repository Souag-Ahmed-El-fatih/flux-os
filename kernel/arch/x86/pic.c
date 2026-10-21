
/*
 * ===== Flux operating system ====
 * (2026-2027)
 * GNU GPL (v3.0)
 * ================================ 
 * creat by : Souag Ahmed El fatih
 * https://github.com/SouagAhmedElfatih/flux_os
 * 
 * File : C source
 * PIC File
 *
 * 
*/

#include <arch/x86/pic.h>
#include <arch/x86/io_port.h>


#define ICW1_ICW4 0x01
#define ICW1_SINGLE 0x02
#define ICW1_INTERVAL 0x04
#define ICW1_LEVEL 0x08
#define ICW1_INIT 0x10

#define ICW4_8086	0x01
#define ICW4_AUTO	0x02
#define ICW4_BUF_SLAVE	0x08
#define ICW4_BUF_MASTER	0x0C
#define ICW4_SFNM	0x10


// if you call this function, all pic interrupt mask (PIT PS2 ....)
void pic_disable() {
    outByte(PIC1_DATA, 0xff);
    outByte(PIC2_DATA, 0xff);
}

void pic_remap(uint8_t ineter_start, uint8_t ineter_end) {
    outByte(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
	outByte(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
	outByte(PIC1_DATA, ineter_start);
	outByte(PIC2_DATA, ineter_end);
	outByte(PIC1_DATA, 4);
	outByte(PIC2_DATA, 2);
	outByte(PIC1_DATA, ICW4_8086);
	outByte(PIC2_DATA, ICW4_8086);
}

void pic_enable() {
    outByte(PIC1_DATA, 0x00);
    outByte(PIC2_DATA, 0x00);
}