

ARCH = x86

include ./config/makefile/flags.mk
include ./config/makefile/paths.mk

all: drivers_compile stdlib_compile kernel_compile kernel_linker 

kernel_compile: 
	$(ASM) $(ASM_FLAGS) $(BOOT_DIR)boot.asm -o $(TMP_DIR)obj/boot.o
	$(ASM) $(ASM_FLAGS) $(BOOT_DIR)multiboot.asm -o $(TMP_DIR)obj/multiboot.o
	$(ASM) $(ASM_FLAGS) $(BOOT_DIR)stack.asm -o $(TMP_DIR)obj/stack.o
	$(ASM) $(ASM_FLAGS) $(ARCH_DIR)io_port.asm -o $(TMP_DIR)obj/io_port.o
	$(ASM) $(ASM_FLAGS) $(ARCH_DIR)gdt.asm -o $(TMP_DIR)obj/gdt.o
	$(CC) $(CC_FLAGS) $(KENREL_DIR)kernel.c -o $(TMP_DIR)obj/kernel.o

stdlib_compile:
	#$(CC) $(CC_FLAGS) $(STDLIB_DIR) -o $(TMP_DIR)obj/.o
	$(CC) $(CC_FLAGS) $(STDLIB_DIR)strcpy.c -o $(TMP_DIR)obj/strcpy.o 
	$(CC) $(CC_FLAGS) $(STDLIB_DIR)strcmp.c -o $(TMP_DIR)obj/strcmp.o 

kernel_linker:
	$(LD) $(LD_FLAGS) $(TMP_DIR)obj/*.o -o $(KENREL_ELF)

drivers_compile:
	$(CC) $(CC_FLAGS) $(DRIVERS_DIR)gfx/early_gfx.c -o $(TMP_DIR)obj/early_gfx.o
	
cdrom:
	grub-mkrescue rootFS -o flux.iso


qemu:
	$(QEMU) -cdrom flux.iso

setup:
	rm -rf $(TMP_DIR)
	mkdir $(TMP_DIR)
	mkdir $(TMP_DIR)/elf
	mkdir $(TMP_DIR)/bin
	mkdir $(TMP_DIR)/obj