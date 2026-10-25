#ifndef COMMON_ENTRYRECAT0V3_H
#define COMMON_ENTRYRECAT0V3_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"

struct EntryRecAt0V3;
struct EntryRecAt0V3 {
    char data[32];
};

struct MenuPakRequestTrackBundle;
struct MenuPakRequestTrackBundle {
    char pad[0x34];
    int group;
    char pad38[0x3C];
    int id;
};

struct RecordRecAt12;
typedef struct RecordRecAt12 RecordRecAt12;


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



extern unsigned char * D_800D36DC;


struct NoteStatePakReadNoteInfo;
typedef struct NoteStatePakReadNoteInfo NoteStatePakReadNoteInfo;

struct NoteStatePakReadNoteInfo;
struct NoteStatePakReadNoteInfo {
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
    NoteStatePakReadNoteInfo notes[16];
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

struct Device;

struct NoteState;
typedef struct NoteState NoteState;

struct PakDirectory;



struct MenuPakRequestTrackBundle;
typedef struct MenuPakRequestTrackBundle MenuPakRequestTrackBundle;

struct PakDirectoryRecAt4;
typedef struct PakDirectoryRecAt4 PakDirectoryRecAt4;


extern void func_80404DDC_de(void);

extern int func_804041E8_de(void);
void Pak_AllocateScratchBuffer(void);
#endif
