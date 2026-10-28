#ifndef MENU_GFX_80414430_24_H
#define MENU_GFX_80414430_24_H
extern void Image_EmitMatrix(void *source);
extern void Image_ResetImage(void *image);
struct OwnedImage;
extern void Image_ReleaseImage(struct OwnedImage *image);
#endif
