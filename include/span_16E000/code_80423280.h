#ifndef UNBAKE_SPAN_16E000_CODE_80423280_H
#define UNBAKE_SPAN_16E000_CODE_80423280_H
#include "TYPES.H"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
struct RecRecAt4;
typedef struct RecRecAt4 RecRecAt4;

struct TabOptionsCommitOptions;
typedef struct TabOptionsCommitOptions TabOptionsCommitOptions;

struct RecRecAt4;
struct RecRecAt4 {
    char pad0[2];
    s16 unk2;
    s16 unk4;
    char pad6[0x96 - 6];
};

struct CompactOptionsCommitContext;
typedef struct CompactOptionsCommitContext CompactOptionsCommitContext;

struct State_func_804242D4_de;
struct State_func_804242D4_de {
    void *first;
    char pad4[0x18 - 4];
    s32 value;
};

extern void func_80423080_de();

extern s32 func_80423758_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct OptionsCommitContext;
struct OptionsCommitContext {
    char pad0[0x8];
    void * unk_8;
    void * unk_C;
    void * unk_10;
    void * unk_14;
};

struct OptionsBuildSettings;
typedef struct OptionsBuildSettings OptionsBuildSettings;

extern void func_8042302C_de();

extern s32 func_8042343C_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern s32 func_80424348_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct State_func_80423328_de;
typedef struct State_func_80423328_de State_func_80423328_de;

extern void func_80424B90_de();

struct CellRecAt1A;
struct Menu_func_804241BC_de;
struct State_func_804241BC_de;
struct State_func_804241BC_de {
    struct Menu_func_804241BC_de *menu;
    char pad4[0x8 - 0x4];
    struct CellRecAt1A *list;
    s32 opening;
    char pad10[0x14 - 0x10];
    s32 delay;
    s32 target;
};

extern s32 func_804239B0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct TabOptionsCommitContext;
struct TabOptionsCommitContext {
    char pad0[0x50];
    void * unk_50;
    void * unk_54;
    void * unk_58;
};

struct TabOptionsCommitContext;
typedef struct TabOptionsCommitContext TabOptionsCommitContext;

struct State_func_80423328_de;
struct State_func_80423328_de {
    s32 unk0;
    char pad4[0x1C];
    s32 unk20;
};

struct Screen_func_80423828_de;
struct Screen_func_80423828_de {
    char pad0[0x1C];
    s32 shown;
    char pad20[0x30 - 0x20];
    s32 mode;
    s32 next_mode;
    char pad38[0x44 - 0x38];
    void *window;
    char pad48[0x4C - 0x48];
    void *second_window;
    char pad50[0x60 - 0x50];
    s32 timer;
};

struct TabOptionsCommitOptions;
struct TabOptionsCommitOptions {
    char pad0[0x10];
    s32 position;
    char pad14[0x1B - 0x14];
    u8 first;
    char pad1C[0x580 - 0x1C];
    u8 second;
};

struct CompactOptionsCommitContext;
struct CompactOptionsCommitContext {
    void * unk_0;
    void * unk_4;
    void * unk_8;
};

struct OptionsBuildSettings;
struct OptionsBuildSettings {
    char pad0[0x10];
    s32 position;
    char pad14[0x7];
    u8 first;
    char pad1C[0x3];
    u8 second;
    char pad20[0x560];
    u8 third;
};

struct OptionsCommitContext;
typedef struct OptionsCommitContext OptionsCommitContext;

extern u8 D_8014222C;

extern int D_800E1AFC_de[];
extern int D_800E1B7C[];
extern int D_800E1ACC_de[];

extern s32 func_8041E720_de(void);
extern void func_8041E81C_de(s32, s32);
extern void func_80429654_de(s32);

extern int func_8042B294_de(int index);
extern void func_8042AFC0_de(int);
extern void func_8042AFD0_de(int);

extern void func_8042A7B4_de(int);

extern void func_8042201C_de();

extern s32 func_8042AF28_de();
enum MatchEnd {
    MATCH_END_TIME_UP,
    MATCH_END_SCORE_LIMIT,
    MATCH_END_TAG_LIMIT,
    MATCH_END_POINT_TARGET
};
extern f32 D_800DDB08_de[];
extern f32 D_800DDB10;
extern void func_8042D28C_de();

extern void func_804220A8_de(s32);

extern char D_800DD9BC[];
extern char D_800DD9C8[];
extern char D_800DD9D0_de[];
extern void func_8042E9B4_de(char *, char *, char *);

extern void func_8042C018_de();

extern s32 func_80264614_de(s32);

#endif
