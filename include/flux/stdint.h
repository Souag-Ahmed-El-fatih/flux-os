
/*
 * ===== Flux operating system ====
 * (2026-2027)
 * GNU GPL (v3.0)
 * ================================ 
 * creat by : Souag Ahmed El fatih
 * https://github.com/SouagAhmedElfatih/flux_os
 * 
 * File : C header
 * stdint File
 *
 * 
*/

#ifndef STDINT_H
#define STDINT_H

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

typedef unsigned char u8_t;
typedef unsigned short u16_t;
typedef unsigned int u32_t;
typedef unsigned long long u64_t;

typedef unsigned int uptr_t; 

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long int64_t;

typedef unsigned int uintptr_t;
typedef unsigned char bool;

typedef unsigned int size_t;
#define true 0
#define false 1

#endif