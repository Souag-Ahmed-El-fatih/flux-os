
# ------------ Makefile ------------



# c compiler falgs
CC_FLAGS = -ffreestanding -m32 -I ./include -c

# assembler flags (nasm)
ASM_FLAGS = -f elf32

# linker file flags 
LD_FLAGS = -m elf_i386 -T ./kernel/linker.ld


CC = i686-elf-gcc
ASM = nasm 
LD = i686-elf-ld
QEMU = qemu-system-i386