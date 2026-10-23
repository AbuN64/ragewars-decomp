#ifndef MENU_GFX_80414430_24_H
#define MENU_GFX_80414430_24_H
extern void Gfx_EmitMatrix(void *source);
extern void Gfx_ResetImage(void *image);
struct OwnedImage;
extern void Gfx_ReleaseImage(struct OwnedImage *image);
#endif
