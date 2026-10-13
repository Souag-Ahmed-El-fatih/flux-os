
/*
 * ===== Flux operating system ====
 * (2026-2027)
 * GNU GPL (v3.0)
 * ================================ 
 * creat by : Souag Ahmed El fatih
 * https://github.com/SouagAhmedElfatih/flux_os
 * 
 * File : C source
 * strcpy core File
 *
 * 
*/
#include <flux/stdint.h>


void strcpy(char *strl, char *strr ) {
    uint32_t count = 0;
    while (strl[count] != '\0') {
        strr[count] = strl[count];
        count++;
    }
    strl[count] = '\0';
}