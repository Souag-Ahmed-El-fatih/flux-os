
; ASSEMBLEY SOURCE FILE (nasm)
; 
; ------- stack  -------
; flux OS (2026/2027)
; creat by : souag ahmed el fatih
; --------------------------------
; GPL 3.0
; 

bits 32

global stack

section .bss
	resb 4096
	stack:

