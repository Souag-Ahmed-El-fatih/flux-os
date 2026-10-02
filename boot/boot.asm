
; ASSEMBLEY SOURCE FILE (nasm)
; 
; ------- multiboot header -------
; flux OS (2026/2027)
; creat by : souag ahmed el fatih
; --------------------------------
; GPL 3.0
; 
extern stack


bits 32

global boot
extern kernel_main
extern stack

section .text
boot:
	mov esp, stack
	cmp eax, 0x2BADB002

	jz .kernel_call
	jmp .end

	.kernel_call:
		push ebx
		call kernel_main
		pop ebx

	.end:
		; i think add shutdown
		jmp $

