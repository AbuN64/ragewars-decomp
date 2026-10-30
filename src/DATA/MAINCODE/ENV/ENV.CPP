#include "DATA/REST_SOURCE_RECORDS.H"
#include "COMMON/ALPARAM_S.H"
#include "TYPES.H"
#include "abi.h"
#include "acmd.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/ALAUXBUS_S.H"
#include "include_asm.h"

/* 802AFD5C_7.CPP */
#if defined(VERSION_EU)
RestLinkerAlignmentFill12 g_EnvBlock1LinkerAlignmentFill540 = {
    { 175, 176, 0, 24, 0, 128, 128, 33, 175, 177, 0, 28 },
};
#endif

/* ENV_SFX_PADDING_BYTES_US.CPP */
#if defined(VERSION_US)
char func_80212FBC_de_padding_13BD4[12] =
    "\000\000\000\000\000\027SFX_CE";
#endif

#if defined(VERSION_US_REV1)
RestLinkerAlignmentFill12 g_EnvLinkerAlignmentFill541 = {
    { 162, 34, 0, 53, 130, 35, 0, 202, 16, 101, 0, 4 },
};
#endif
