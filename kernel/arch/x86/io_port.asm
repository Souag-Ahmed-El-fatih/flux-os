

; ASSEMBLEY SOURCE FILE (nasm)
; 
; ------- multiboot header -------
; flux OS (2026/2027)
; creat by : souag ahmed el fatih
; --------------------------------
; GPL 3.0

BITS 32

global outByte
global inByte
global outWrod
global inWord

inByte:
	mov eax, 0
	mov edx, [esp+4]
	in al, dx
	ret
	
outByte:
	mov edx, [esp+4]
	mov eax, [esp+8]
	out dx, al
	ret

inWord:
	mov eax, 0
	mov edx, [esp+4]
	in ax, dx
	ret

outWord:
	mov edx, [esp+4]
	mov eax, [esp+8]
	out dx, ax
	ret
