
/*
 * ===== Flux operating system ====
 * (2026-2027)
 * GNU GPL (v3.0)
 * ================================ 
 * creat by : Souag Ahmed El fatih
 * https://github.com/SouagAhmedElfatih/flux_os
 * 
 * File : c source
 * serial File
 *
 * 
*/

#include <arch/x86/io_port.h>
#include <flux/stdint.h>

#define COM1 0x3f8


bool serial_init() {
    outByte(COM1 + 1, 0x00); // disable all interrupt 
    outByte(COM1 + 3, 0x80); // enable DLAB bit (MODE DLAB)
    outByte(COM1 + 0, 0x03); // 
    outByte(COM1 + 1, 0x00); // 
    outByte(COM1 + 3, 0x03); // disable DLAB bit  and set 8bit in word
    outByte(COM1 + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
    outByte(COM1 + 4, 0x0B);   
    outByte(COM1 + 4, 0x1E);
    // هاذا تيست برك و تقدر تنحيه منا  
    outByte(COM1 + 0, 0x11); 

   
   if(inByte(COM1 + 0) != 0x11) {
      return false;
   }


   outByte(COM1 + 4, 0x0F);
   return true;
}

// هنا ننتظرو شوية باش يجهز سيريال للارسال
// we wait some time because is ready for send
int serial_is_ready() {
   return inByte(COM1 + 5) & 0x20;
}

// print or send 1 char 
// هاذي دالة تبعث حرف واحد برك
void serial_putchar(char ch) {
   while (serial_is_ready() == 0);

   outByte(COM1, ch);
}

// هاذا دالة تبعث حروف عديدة 
// this function print a string 
void serial_print(char *text) {
    int count = 0;
    while (text[count] != '\0') {
        serial_putchar(text[count]);
        count++;
    }
}