

ARCH = x86
VERSION = 1.0


include ./config/makefile/flags.mk
include ./config/makefile/paths.mk

# call all lable for build kenrel
all: drivers_compile stdlib_compile kernel_compile kernel_linker 

kernel_compile: 
	$(ASM) $(ASM_FLAGS) $(BOOT_DIR)boot.asm -o $(TMP_DIR)obj/boot.o
	$(ASM) $(ASM_FLAGS) $(BOOT_DIR)multiboot.asm -o $(TMP_DIR)obj/multiboot.o
	$(ASM) $(ASM_FLAGS) $(BOOT_DIR)stack.asm -o $(TMP_DIR)obj/stack.o
	$(ASM) $(ASM_FLAGS) $(ARCH_DIR)io_port.asm -o $(TMP_DIR)obj/io_port.o
	$(ASM) $(ASM_FLAGS) $(ARCH_DIR)gdt.asm -o $(TMP_DIR)obj/gdt.o
	$(CC) $(CC_FLAGS) $(KENREL_DIR)kernel.c -o $(TMP_DIR)obj/kernel.o
	$(CC) $(CC_FLAGS) $(ARCH_DIR)pic.c -o $(TMP_DIR)obj/pic.o
	$(CC) $(CC_FLAGS) $(ARCH_DIR)serail.c -o $(TMP_DIR)obj/serail.o

stdlib_compile:
	#$(CC) $(CC_FLAGS) $(STDLIB_DIR) -o $(TMP_DIR)obj/.o
	$(CC) $(CC_FLAGS) $(STDLIB_DIR)strcpy.c -o $(TMP_DIR)obj/strcpy.o 
	$(CC) $(CC_FLAGS) $(STDLIB_DIR)strcmp.c -o $(TMP_DIR)obj/strcmp.o 

kernel_linker:
	$(LD) $(LD_FLAGS) $(TMP_DIR)obj/*.o -o $(KENREL_ELF)

drivers_compile:
	$(CC) $(CC_FLAGS) $(DRIVERS_DIR)gfx/early_gfx.c -o $(TMP_DIR)obj/early_gfx.o

# ------------------------ CREAT BOOTABLE CD-DVD ------------------------
cdrom:
	grub-mkrescue rootFS -o flux.iso

# ------------------------ QEMU RUN ------------------------
qemu:
	$(QEMU) -cdrom flux.iso

# ------------------------ SETUP FILE & FOLDERS ------------------------
setup:
	rm -rf $(TMP_DIR)
	mkdir $(TMP_DIR)
	mkdir $(TMP_DIR)/elf
	mkdir $(TMP_DIR)/bin
	mkdir $(TMP_DIR)/obj