#ifndef COMMON_GROUP_H
#define COMMON_GROUP_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
struct Work80244494;
typedef struct Work80244494 Work80244494;


struct Group;

extern void Cinema_ClearPlaybackFlag(void);

extern void Cinema_RequestSequenceFade(void);


extern void Cinema_ClearPlaybackPauseState(void);

extern int Cinema_HasSequenceResource(void);




struct VectorPair;

struct Group;
typedef struct Group Group;


extern int D_800CB418_de;

extern float D_800C37B0_de;






struct VectorPair;
typedef struct VectorPair VectorPair;



struct Work80244494;






struct CCollisionInfo2_t;

extern s32 Cinema_HasSequenceEnded(void);



struct GameState;
struct GameState {
    s32 busy;
    char pad4[0x18B0];
    s32 paused;
};

extern int Cinema_IsSequenceFlagTwoSet(void);


struct GameState;
typedef struct GameState GameState;


extern int Cinema_IsFadeAllowed(void);

extern void Cinema_EndSequence(void);



extern int D_800CB420_de;


extern void Cinema_SetPlaybackFlag(void);

extern int D_800CB41C_de;

#endif
