
/*
 * ===== Flux operating system ====
 * (2026-2027)
 * GNU GPL (v3.0)
 * ================================ 
 * creat by : Souag Ahmed El fatih
 * https://github.com/SouagAhmedElfatih/flux_os
 * 
 * File : C header
 * input output port File
 *
 * 
*/
#ifndef OI_PORT_H
#define IO_PORT_H

extern void outByte(uint16_t port, uint8_t value);
extern void outWord(uint16_t port, uint16_t value);

extern uint16_t inByte(uint16_t port);
extern uint16_t inWrod(uint16_t port);

#endif