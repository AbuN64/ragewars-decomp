#ifndef FRONTEND_8040B45C_40_H
#define FRONTEND_8040B45C_40_H
#include "FRONTEND/LAYOUT.H"
extern void Frontend_SetGridForegroundColors(s32 identifier, s32 first, s32 second, s32 third);
extern void Frontend_GetGridSelection(s32 identifier, s32 *first, s32 *second);
extern void Frontend_SetGridBackgroundColors(s32 identifier, s32 first, s32 second, s32 third);
extern void Frontend_SetGridDimensionArrays(s32 identifier, s32 first, s32 second);
extern void Frontend_GetGridCellValues(s32 identifier, s32 row, s32 column, s32 *first, s32 *second);
extern void Frontend_SetGridCellValues(s32 identifier, s32 row, s32 column, s32 first, s32 second);
extern s32 Frontend_CreateGridListFromWidget(s32 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6);
#endif
