

# FLUX OS

welcome to open source project .

flux-os is basic and simple operating system for computer x86 32bit .

you can have source code and edit free but you need agree the GNUv3.0

مرحبا بيكم في مشروع نتاعي لي مفتوح المصدر

هاذا مجرد نظام تشغيل بسيط مني انا لمعمارية 
x86 32bit

هاذا مشروع تحت رخصية جنو حي بي ال 3
## devloper :
It was completely made by `souag ahmed el fatih`

The project is 100% Algerian.

تم تصميم مشروعي بواسطة : صواق أحمد الفاتح

هاذا المشروع جزائري

## Goals for project :
[X] multiboot 
[X] GDT - (32bit)
[X] early graphics 
[ ] IDT - (32bit)
[ ] syscalls 
[ ] memory manger
[ ] graphics manager
[ ] VMM
[ ] VFS - v system file
[ ] user mode
[ ] init system
[ ] programmes execute

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

1. راك محتاج تهيئ المجلدات 

* ` make setup `

2. build kernel and drivers and linker all in elf file

2. باش تبني النواة و تعريفات و تربط النواة لازم تكتب

* ` make `

3. thred build cdROM or iso file boot by GRUB

3. باش تبني صورة قابلة للاقلاع و ايضا مع محمل اقلاع جراب لازم تكتب

* ` make cdrom `

من بعد تقدر تشوف النظام

you can fild iso in 
./flux.iso

هاذا جزئية مفهومة و ما تحتاج شرح بزاف 

so you can run this in real computer or VM but you need arch x86 (AMD-INTEL)

if you have qemu :

` qemu-system-i386 -cdrom flux.iso `

else 

` <VM> <OPTIONS> flux.iso `


اذا تقدر تتكرم علينا و دير ستار للبروجي و ادعمني 