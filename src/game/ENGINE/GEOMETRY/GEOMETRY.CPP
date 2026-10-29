#include "include_asm.h"

/* GEOMETRY_1.CPP */
/* 8026E1F8_3.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int g_geometrySplitTextWordEuX[1] = { 0xE6000014U };
#endif

/* 80275E44_4.CPP */
#if defined(VERSION_EU)
unsigned char g_GeometryTrailingBytesBlock1[8] = { 0x46, 0x01, 0x00, 0x01, 0x46, 0x00, 0xA8, 0x02 };
#endif

/* GEOMETRY_2.CPP */
#if defined(VERSION_DE)
unsigned char g_GeometryTrailingBytes[4] = { 0xAF, 0xB5, 0x00, 0xB4 };
#endif

/* GEOMETRY_3.CPP */
/* ROM-grounded data: src/rw_pool_8026B504_CA358_us_rev1.c */
const unsigned int g_geometryLightColorMaximum[1] = {
    0x42FE0000,
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
/* ROM-grounded data: src/rw_text_8026C484_CA384_us_rev1.c */
const unsigned char s_simpModelText[11] = {
    0x73, 0x69, 0x6D, 0x70, 0x20, 0x6D, 0x6F, 0x64, 0x65, 0x6C, 0x00,
};
#endif

/* GEOMETRY_7.CPP */
/* 800C9790.CPP */
/* ROM-grounded data: src/rw_pool_8026CE18_CA390_us_rev1.c */
const unsigned int g_geometryModelDistanceConstants[2] = {
    0x42A00000, 0x43200000,
};

/* 800C9798.CPP */
/* ROM-grounded data: src/rw_pool_8026D27C_CA398_us_rev1.c */
const unsigned int g_geometryModelPartDistanceConstant[1] = {
    0x42A00000,
};
