

/*
 * ===== Flux operating system ====
 * (2026-2027)
 * GNU GPL (v3.0)
 * ================================ 
 * creat by : Souag Ahmed El fatih
 * https://github.com/SouagAhmedElfatih/flux_os
 * 
 * File : C source
 * Kernel core File
 *
 * 
*/
#include <flux/info.h>
#include <drivers/gfx/early.h>
#include <multiboot.h>
#include <arch/x86/gdt.h>

kernel_info_t kernel_info;

void kernel_main(uint32_t ebx) {

    multiboot_info_t *mbi = (multiboot_info_t*)ebx;

    /* 
    * i have some graphics info and set in struct kenrel info
        * address
        * width
        * height
        * pitch
        * bpp or depth
    */
    if (mbi->flags & MULTIBOOT_INFO_FRAMEBUFFER_INFO) {
        kernel_info.gfx.addr = mbi->framebuffer_addr ;
        kernel_info.gfx.width = mbi->framebuffer_width ;
        kernel_info.gfx.height = mbi->framebuffer_height ;
        kernel_info.gfx.pitch = mbi->framebuffer_pitch ;
        kernel_info.gfx.bpp = mbi->framebuffer_bpp ;


        if (kernel_info.gfx.addr == 0xb8000 && kernel_info.gfx.width == 80 && kernel_info.gfx.height == 25) {
            kernel_info.gfx.mode = GFX_TEXT_MODE;
        } 
        else {
            kernel_info.gfx.mode = GFX_GFX_MODE;
            
        }

    }

    /*
        init early graphics driver  
    */
    
    if (kernel_info.gfx.mode == GFX_GFX_MODE) {
        early_gfx_init(
                kernel_info.gfx.addr,
                kernel_info.gfx.width,
                kernel_info.gfx.height,
                kernel_info.gfx.bpp,
                kernel_info.gfx.pitch
        );
        early_gfx_color(0xFFC0C0C0);
        early_gfx_print("welcome to ");
        early_gfx_color(0xFF2ECC71);
        early_gfx_print("flux os \n");
        early_gfx_color(0xFFC0C0C0);
    }

    GDT_LOAD();

    if (kernel_info.gfx.mode == GFX_GFX_MODE) {
        early_gfx_print("[ ok ] global descriptor table init \n");
    }
    else {
        //
    }

    
}