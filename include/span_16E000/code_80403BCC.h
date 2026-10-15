#include "types.h"
#ifndef UNBAKE_SPAN_16E000_CODE_80403BCC_H
#define UNBAKE_SPAN_16E000_CODE_80403BCC_H
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"

struct EntryRecAt0V3;
struct EntryRecAt0V3 {
    char data[32];
};

struct Menu_func_80403BE0_de;
struct Menu_func_80403BE0_de {
    char pad[0x34];
    int group;
    char pad38[0x3C];
    int id;
};

struct RecordRecAt12;
typedef struct RecordRecAt12 RecordRecAt12;

extern int func_80403BE0_de();

struct Entry_func_804053E0_de;
struct Entry_func_804053E0_de {
    s32 size;
    char data[28];
};

struct Entry_func_804053E0_de;
struct RecordRecAt4V2;
struct RecordRecAt4V2 {
    s32 header;
    struct Entry_func_804053E0_de entries[16];
};

struct NoteState;
struct NoteState {
    u32 file_size;
    u32 game_code;
    u16 company_code;
    char ext_name[4];
    char game_name[16];
    char pad[2];
};

extern f32 func_80403C58_de(f32 from, f32 to, f32 t);

extern s32 func_80403BCC_de(void);

extern unsigned char * D_800D36DC;

extern void func_80403DE8_de(void);

struct NoteState_func_8040458C_de;
typedef struct NoteState_func_8040458C_de NoteState_func_8040458C_de;

struct NoteState_func_8040458C_de;
struct NoteState_func_8040458C_de {
    u32 file_size;
    u32 game_code;
    u16 company_code;
    u8 ext_name[4];
    u8 game_name[16];
    char pad[2];
};

struct PakDirectoryRecAt4;
struct PakDirectoryRecAt4 {
    s32 free;
    NoteState_func_8040458C_de notes[16];
};

struct EntryRecAt0V3;
struct RecordRecAt4V1;
struct RecordRecAt4V1 {
    s32 header;
    struct EntryRecAt0V3 entries[16];
};

struct PakDirectory;
typedef struct PakDirectory PakDirectory;

struct Device;
typedef struct Device Device;

struct RecordRecAt12;
struct RecordRecAt12 {
    char pad[0x11];
    unsigned char kind;
    unsigned char subtype;
};

struct Device;
struct Device {
    s8 pad0[0x68];
};

struct NoteState;
typedef struct NoteState NoteState;

struct PakDirectory;
struct PakDirectory {
    s32 free;
    NoteState notes[16];
};

extern f32 func_80403C98_de(f32 from, f32 to, f32 weight);


struct Menu_func_80403BE0_de;
typedef struct Menu_func_80403BE0_de Menu_func_80403BE0_de;

struct PakDirectoryRecAt4;
typedef struct PakDirectoryRecAt4 PakDirectoryRecAt4;

extern s32 func_804053E0_de(s32 index, s32 entry, s32 *out);

extern void func_80404DDC_de(void);

extern int func_804041E8_de(void);
void func_80404D84_de(void);

extern s32 func_80446F60_de(void *,OSPfs *,s32);
extern s32 func_80403E90_de(s32);

#endif
