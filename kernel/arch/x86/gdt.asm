

; ASSEMBLEY SOURCE FILE (nasm)
; 
; ------- multiboot header -------
; flux OS (2026/2027)
; creat by : souag ahmed el fatih
; --------------------------------
; GPL 3.0

BITS 32

global GDT_START
global GDT_END
global GDT_LOAD
global GDT_INFO

GDT_LOAD:
	lgdt [GDT_INFO]
	jmp 0x08:.reload

	.reload:
		mov ax, 0x10
		mov ds, ax
		mov es, ax
		mov fs, ax
		mov gs, ax
		mov ss, ax
		mov eax, 1
		ret

GDT_START:
    dq 0 ; NULL ENTRY
    .kernel_code:
		dw 0xFFFF
		dw 0x0000
		db 0
		db 10011010b
		db 11001111b
		db 0
	.kernel_data:
		dw 0xFFFF
		dw 0x0000
		db 0
		db 10010010b
		db 11001111b
		db 0

GDT_END:

GDT_INFO:
    dw GDT_END - GDT_START -1
    dd GDT_START