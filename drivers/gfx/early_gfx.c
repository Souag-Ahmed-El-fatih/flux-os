
#include <flux/stdint.h>
#include <drivers/gfx/font.h>
#include <flux/bit.h>

struct early_gfx_info {
    u32_t height;
    u32_t width;
    uptr_t address;
    u32_t depth;
    u32_t pitch;
};

struct early_font_info {
    u32_t scale;
    u32_t x;
    u32_t y;
    u32_t width;
    u32_t height;
    u32_t scaping;
    u32_t color;
};

static struct early_gfx_info early_gfx_info;
static struct early_font_info early_font_info;

/*
 * this function for init gfx and save frame buffer data
 * the function need arg : address width height depth pitch
*/
bool early_gfx_init(uptr_t address, u32_t width, u32_t height, u32_t depth, u32_t pitch) {
    /*
		i verify that the height and width are non-zero to prevent calculation errors
		i verify the addres are not equl zero 
    */
    if (width > 0 && height > 0 && address != 0) {
        early_gfx_info.address = address;
        early_gfx_info.width = width;
        early_gfx_info.height = height;
        early_gfx_info.pitch = pitch;
        early_gfx_info.depth = depth;
        /*
			i calculate the scale for font using a width and height
        */
        if (width == 800 && height == 600) {
            early_font_info.scale = 1;
            early_font_info.scaping = 2;
            early_font_info.y = 0;
            early_font_info.x = 0;
            early_font_info.width = width / (8 + early_font_info.scaping) ;
            early_font_info.height = height / 16;
        }

        early_font_info.color = 0xffffffff;
        /*volatile u32_t *screen = (volatile u32_t *)address;
        for (int i = 0; i < 100 * 800; i++) {
            screen[i] = 0xffffffff;
        }*/
        return true;
    }
    // error or los data
    return false;
}

static void early_gfx_drawchar(char chr) {
    // 11/sep/2026
    int nbyte = 0;

    volatile uptr_t *console = (volatile uptr_t *)early_gfx_info.address;

    // calcute the first pixle index 
    /*
     * 
     *  
     *  
     * 
     *  
     *  
     *  
     *  
     *  
     *  
     *  
     *  
     *  
     *  
     *  
     *  
     *  
     * 
    */
    u32_t index = (early_font_info.y * (16 * early_font_info.scale)) * early_gfx_info.width + (early_font_info.x * (8 * early_font_info.scale + (early_font_info.scaping * early_font_info.scale)));

    while (nbyte < 16) {
        int nbit = 0;
        while (nbit < 8) {
            if (GetBit(font_8x16[chr][nbyte], 7 - nbit) == 1) {
               
                console[index + nbit] = early_font_info.color;
            }
            nbit++;
        }
        index = (nbyte * early_gfx_info.width) + (early_font_info.y * (16 * early_font_info.scale)) * early_gfx_info.width + (early_font_info.x * (8 * early_font_info.scale + (early_font_info.scaping * early_font_info.scale)));
        nbyte++;
    }
}


void early_gfx_pchar(char chr) {
    // if font.x >= font.wdith ; this end for line and i set x = 0 ; y++;
    if (early_font_info.x >= early_font_info.width) {
        early_font_info.y++;
        early_font_info.x = 0;
        early_gfx_drawchar(chr);
    }
    /*
        this not print char;
        if chr == '\n' i jump to next line
        and if chr equl '\t' i print space or tab
        chr equl '\b' i remove char
    */
    else if (chr == '\n') {
        early_font_info.y++;
        early_font_info.x = 0;
    }
    /*
        i print the chr 
    */
    else {
        early_gfx_drawchar(chr);
        early_font_info.x++;
    }
}

/*

    nbyte * width + nbit =  first line .

    font
    pixle

    y x
    pixle xx yy

    y = 1
    x = 3
    ((y * (16 * sacle)) * width + (x * (8 * escale))


*/

/*
 * this mini function for print a string
 * ex : 
 * char test = "hi";
 * early_gfx_print(test);
 * early_gfx_print("user");
*/

void early_gfx_print(char * foramt) {
    uptr_t index = 0;
    // if format[index] not equl end for text
    while (foramt[index] != '\0') {

        early_gfx_pchar(foramt[index]);
        index++;

    }
}

void early_gfx_color(u32_t color) {
    early_font_info.color = color;
}