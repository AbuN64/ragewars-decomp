#ifndef GFX_TEXTURE_TILE_TYPES_H
#define GFX_TEXTURE_TILE_TYPES_H
#include "TYPES.H"

typedef struct TextureTileBlock {
    u32 width;
    u32 height;
    u8 pixels[0]; /* Tile pixels follow the eight-byte width/height header. */
} TextureTileBlock;

typedef struct TextureTileGrid {
    u16 columns;
    u16 rows;
    u32 reserved;
    u8 blocks[1];
} TextureTileGrid;

#endif
