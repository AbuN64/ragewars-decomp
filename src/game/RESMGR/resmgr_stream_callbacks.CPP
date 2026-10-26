#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/LONE/D_8014D0D0.H"
#include "COMMON/MANAGER.H"
#include "COMMON/MESSAGESEMAPHORE.H"
#include "COMMON/INTEGERSTATE14_2.H"
#include "TYPES.H"
#include "RESMGR/resmgr_stream_callbacks.H"
#include "MENU/GFX/80414480_3.H"
#include "SCENE/802508E0_13.H"

typedef void (*FuncPtr)(void);



extern ResourceReadCallback D_800CD92C_de;
extern ResourceSeekCallback D_800CD934_de;
extern FuncPtr D_800CD938_de;
extern FuncPtr D_800CD93C_de;




extern ResourceOpenCallback D_800CD924_de;

extern s32 D_800CD928_de;

/* Allocates the resource once and marks its five-word state ready. */
extern struct CartridgeReadWorker D_801011B8;

extern Record *Cache_AllocateMemory(s32 arg0);

extern void func_8025637C_de(struct CartridgeReadWorker *worker, u32 source, s32 bytes, void *destination);

#include "RESMGR/resmgr_string_memory.H"

/** Return the constant false result used by callers at VRAM 0x802A1F50. */
int func_802A0F50_de(void) {
    return 0;
}

/** Return the zero status used by callers. */
int func_802A0F58_de(void) {
    return 0;
}

/* Forward every seek argument and return the configured callback status. */
s32 XStdio_SeekStream(s32 handle, s32 offset, s32 origin) {
    return D_800CD934_de(handle, offset, origin);
}

void func_802A0F84_de(void) {
    D_800CD938_de();
}

void func_802A0FA8_de(void) {
    extern FuncPtr D_800CD93C_de;
    D_800CD93C_de();
}

s32 func_802A0FCC_de(s32 arg0) {
    u8 sp10;
    s32 result;

    if (D_800CD92C_de(arg0, &sp10, 1) != 0) {
        result = sp10;
    } else {
        result = -1;
    }
    return result;
}

int func_802A1004_de(void) {
    return 0;
}

s32 *func_802A100C_de(s32 arg0, s32 arg1) {
    D_800CD918 = func_80414CCC_de(&D_8014D0D0, arg0, arg1);
    return &D_8014D0D0;
}

void func_802A1050_de(ResourceOpenCallback arg0, s32 arg1, ResourceReadCallback arg2, s32 arg3, ResourceSeekCallback arg4, FuncPtr arg5, FuncPtr arg6) {
    D_800CD924_de = arg0;
    D_800CD928_de = arg1;
    D_800CD92C_de = arg2;
    D_800CD930_de = arg3;
    D_800CD934_de = arg4;
    D_800CD938_de = arg5;
    D_800CD93C_de = arg6;
}

void XStdio_LoadMemoryStream(void) {
    void *buffer;
    IntegerState14_2 *stream;
    if (D_800CD940_de.ready != 1) {
#if defined(VERSION_DE)
        D_800CD940_de.size = 0x8BB01;
        buffer = Cache_AllocateMemory(0x8BB01);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        D_800CD940_de.size = 0x8B245;
        buffer = Cache_AllocateMemory(0x8B245);
#elif defined(VERSION_EU_X)
        D_800CD940_de.size = 0x90385;
        buffer = Cache_AllocateMemory(0x90385);
#endif
        D_800CD940_de.data = buffer;
        func_8025637C_de(&D_801011B8, 0x200000, D_800CD940_de.size, buffer);
        stream = &D_800CD940_de;
        stream->opened = 0;
        D_800CD940_de.ready = 1;
    }
}

void XStdio_FreeMemoryStream(void) {
    if (D_800CD940_de.data != 0) {
        Cache_FreeMemory(D_800CD940_de.data);
    }
    D_800CD940_de.data = 0;
    D_800CD940_de.opened = 0;
    D_800CD940_de.ready = 0;
}

/* Reset the memory stream and return its single valid handle. */
s32 XStdio_OpenMemoryStream(const void *name, const void *mode) {
    const u8 *modeCursor = mode;
    while (*modeCursor != 0) {
        modeCursor++;
    }
    modeCursor++;
    D_800CD940_de.cursor = 0;
    D_800CD940_de.opened = 1;
    return 1;
}

/** Clear the global word at VRAM 0x800D2BBC. */

void func_802A1188_de(void) {
    D_800CD940_de.opened = 0;
}

s32 XStdio_ReadMemoryStream(s32 handle, void *destination, s32 bytes) {
    IntegerState14_2 *stream = &D_800CD940_de;
    XPlus_CopyBytes(destination, stream->data + stream->cursor, bytes);
    stream->cursor = stream->cursor + bytes;
    return 1;
}

/** Return the false result used by callers at VRAM 0x802A21EC. */
int func_802A11EC_de(void) {
    return 0;
}

s32 XStdio_SeekMemoryStream(s32 handle, s32 offset, s32 origin) {

    if (origin == 0) {
        D_800CD940_de.cursor = 0;
    }
    D_800CD940_de.cursor = D_800CD940_de.cursor + offset;
    return 0;
}

/** Return the first global state word. */
unsigned int XStdio_TellMemoryStream(void) {
    return D_800CD940_de.cursor;
}
