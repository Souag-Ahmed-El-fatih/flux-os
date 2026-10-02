ENTRY(boot)

SECTIONS 
{
	.multiboot : {*(.multiboot)},
	.text : {*(.text*)},
	.data : {*(.data*)},
	.rodata : {*(.rodata*)},
	.bss : {*(.bss*)}
}