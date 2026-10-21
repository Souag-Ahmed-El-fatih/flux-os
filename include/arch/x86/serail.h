


/*
 * ===== Flux operating system ====
 * (2026-2027)
 * GNU GPL (v3.0)
 * ================================ 
 * creat by : Souag Ahmed El fatih
 * https://github.com/SouagAhmedElfatih/flux_os
 * 
 * File : c header
 * serial File
 *
 * 
*/
#ifndef SERAIL_H
#define SERAIL_H

#include <flux/stdint.h>

bool serial_init();
void serial_putchar(char ch);
void serial_print(char *text);


#endif