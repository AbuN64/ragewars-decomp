#ifndef RENDER_VIEW_MATRICES_H
#define RENDER_VIEW_MATRICES_H
/* The loading-screen setup routine and the view-matrix array it fills sit at different addresses in each cartridge. */
#if defined(VERSION_DE)
#define LOAD_SETUP SetN64_SetupLoadingBackdropDe
#define VIEW_MATRICES g_loadingViewMatricesDe
#else
#define LOAD_SETUP SetN64_SetupLoadingBackdropRev1
#define VIEW_MATRICES g_loadingViewMatricesUsRev1
#endif
extern u8 VIEW_MATRICES[];
#endif
