#ifndef SCENE_SHAREDRECAT1B664V1_H
#define SCENE_SHAREDRECAT1B664V1_H
typedef struct SharedRecAt1B664V1 SharedRecAt1B664V1;
struct SharedRecAt1B664V1 {
    char pad0[0x1B664];
    void * unk1B664; /* +0x1B664: src/func_80286A78.c */
};
typedef char Shared_func_80286A78_S15_size_check[(sizeof(SharedRecAt1B664V1) == 0x1B668) ? 1 : -1];
#endif
