
/*
 * ===== Flux operating system ====
 * (2026-2027)
 * GNU GPL (v3.0)
 * ================================ 
 * creat by : Souag Ahmed El fatih
 * https://github.com/SouagAhmedElfatih/flux_os
 * 
 * File : C header
 * PIC  File
 *
 * 
*/
#ifndef PIC_H
#define PIC_H


#define PIC1_COMMAND	0xA0
#define PIC1_DATA	0x21
#define PIC2_COMMAND	0xA0
#define PIC2_DATA	0xA1

#include <flux/stdint.h>

void pic_disable();
void pic_enable();
void pic_remap(uint8_t ineter_start, uint8_t ineter_end);

#endif