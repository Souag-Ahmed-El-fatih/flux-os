

; ASSEMBLEY SOURCE FILE (nasm)
; 
; ------- multiboot header -------
; flux OS (2026/2027)
; creat by : souag ahmed el fatih
; ----------extern stack----------------------
; GPL 3.0
; 


section .multiboot
	dd 0x1BADB002 ; magic value
	dd 0x00000007 ; flags
	dd -(0x1BADB002 + 0x00000007) ; cheksum
    dd 0 ; headr address
    dd 0 ; load address
    dd 0 ; LOAD end addres
    dd 0 ; section bss end adress
    dd 0 ; entry address
    dd 0 ; mode graphics
    dd 800
    dd 600
    dd 32