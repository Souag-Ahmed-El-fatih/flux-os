#ifndef INFO_H
#define INFO_H

#include <flux/stdint.h>

#define GFX_TEXT_MODE 0x82
#define GFX_GFX_MODE 0x81

typedef struct {
    struct {
        uint8_t mode;
        uintptr_t addr;
        uint32_t width;
        uint32_t height;
        uint32_t pitch;
        uintptr_t bpp;
    }gfx;
}kernel_info_t;

#endif