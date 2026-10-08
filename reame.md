

# FLUX OS

welcome to open source project .

flux-os is basic and simple operating system for computer x86 32bit .

you can have source code and edit free but you need agree the GNUv3.0

## devloper :
It was completely made by `souag ahmed el fatih`

The project is 100% Algerian.

## Goals for project :


## the struct folder ? :
1. boot    : the first code work in kernel !
2. config  : config makefiles and secripts
3. docs    : 
4. drivers : kenrel drivers (gfx, keyboard, user ...)
5. include : C header file for os
6. kernel  : the source code for core kernel (GDT, IDT MEM MANAGER ...)
7. lib     : user libC source code
8. rootFS  : the root file system for iso
9. tmp     : hte output for build



## how to build flux ? :
1. in first you need setup tmp folder

* ` make setup `

2. build kernel and drivers and linker all in elf file

* ` make `

3. thred build cdROM or iso file boot by GRUB

* ` make cdrom `

you can fild iso in 
./flux.iso

so you can run this in real computer or VM but you need arch x86 (AMD-INTEL)

if you have qemu :

` qemu-system-i386 -cdrom flux.iso `

else 

` <VM> <OPTIONS> flux.iso `