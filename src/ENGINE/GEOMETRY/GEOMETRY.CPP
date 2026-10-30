#include "include_asm.h"

/* GEOMETRY_1.CPP */
/* 8026E1F8_3.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
/* Alignment fill to the next 16-byte object boundary. */
unsigned int g_geometrySplitTextWordEuXAlignmentPad[1] = { 0xE6000014U };
#endif

/* 80275E44_4.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_GeometryTrailingBytesBlock1AlignmentPad[8] = { 0x46, 0x01, 0x00, 0x01, 0x46, 0x00, 0xA8, 0x02 };
#endif

/* GEOMETRY_2.CPP */
#if defined(VERSION_DE)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_GeometryTrailingBytesAlignmentPad[4] = { 0xAF, 0xB5, 0x00, 0xB4 };
#endif

/* GEOMETRY_3.CPP */
/* ROM-grounded data: src/g_geometryLightColorMaximum_Geometry.c */
const float g_geometryLightColorMaximum[1] = {
    127.0f,
};

/* GEOMETRY_4.CPP */
#if !(defined(VERSION_US_REV1))
const char s_simpleObjectIndexText[18] =
    "simp object index\000";
#endif

#if defined(VERSION_US_REV1)
const char s_simpObjectIndexText[18] = "simp object index";
#endif

/* GEOMETRY_5.CPP */
#if !(defined(VERSION_US_REV1))
const char s_simpleModelsIndexText[18] =
    "simp models index\000";
#endif

#if defined(VERSION_US_REV1)
const char s_simpModelsIndexText[18] = "simp models index";
#endif

/* GEOMETRY_6.CPP */
#if !(defined(VERSION_US_REV1))
const char s_simpleModelText[11] =
    "simp model\000";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/s_simpModelText_Geometry.c */
const char s_simpModelText[11] =
    "simp model";
#endif

/* GEOMETRY_7.CPP */
/* 800C9790.CPP */
/* ROM-grounded data: src/g_geometryModelDistanceConstants_Geometry.c */
const float g_geometryModelDistanceConstants[2] = {
    8.0e+01f, 1.6e+02f,
};

/* 800C9798.CPP */
/* ROM-grounded data: src/g_geometryModelPartDistanceConstant_Geometry.c */
const float g_geometryModelPartDistanceConstant[1] = {
    8e+01f,
};
