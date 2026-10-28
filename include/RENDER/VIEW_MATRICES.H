#ifndef RENDER_VIEW_MATRICES_H
#define RENDER_VIEW_MATRICES_H
/* The loading-screen setup routine and the view-matrix array it fills sit at different addresses in each cartridge. */
#if defined(VERSION_DE)
#define LOAD_SETUP func_80290A90_de
#define VIEW_MATRICES D_8011B510_de
#else
#define LOAD_SETUP func_80290A70_us_rev1
#define VIEW_MATRICES D_8011F5D0_us_rev1
#endif
extern u8 VIEW_MATRICES[];
#endif
