#ifndef EARLY_H
#define EARLY_H

#include <flux/stdint.h>

bool early_gfx_init(uptr_t address, u32_t width, u32_t height, u32_t depth, u32_t pitch);
void early_gfx_pchar(char chr);
void early_gfx_print(char * foramt);
void early_gfx_color(u32_t color);
#endif