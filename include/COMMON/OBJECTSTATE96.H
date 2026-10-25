#ifndef COMMON_OBJECTSTATE96_H
#define COMMON_OBJECTSTATE96_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"

struct ObjectState96;

struct __OSInodeCache;
struct __OSInodeCache {
    __OSInode inode;
    u8 bank;
    u8 map[256];
};

typedef struct CPlayerPool_t CPlayerPool;
/* func_80449DB0_de clears0x44 and initializes lists+C,+20. */
struct CPlayerPool_t {
    void *m_pmePlayers;
    char *m_Players;
    s32 count;
    IntrusiveList m_FreeList;
    IntrusiveList m_ActiveList;
    s32 m_bEnteredAdonSaveLocation, m_bAdonSaveLocationMenuEnabled, m_TeamTriangleTimer, m_TriangleSpin;
};


extern void func_80447A38_de(u8 *valid, EntryRecAt3 *data);

struct IntegerState88;
typedef struct IntegerState88 IntegerState88;


struct __OSPackId;
struct __OSPackId {
    u32 repaired;
    u32 random;
    u64 serial_mid;
    u64 serial_low;
    u16 deviceid;
    u8 banks;
    u8 version;
    u16 checksum;
    u16 inverted_checksum;
};


struct __OSInodeCache;
typedef struct __OSInodeCache __OSInodeCache;



struct Body;
struct Character;
struct Controller;
struct Controls;
struct Ctrl;
struct Held;
struct Mode;
struct Model;
struct Mount;
struct Profile;
struct Rider;
struct Settings;
struct Shared_Body;
struct Shared_Hud;
struct Shared_Model;
struct Shared_Profile;
struct Shared_StateInfo;
struct Shared_Voice;
struct StateInfo;
struct TeamInfo;
struct View;
struct ObjRecAt80;

extern u16 func_80448B84_de(u8 *bytes, s32 count);

struct RecordCode80447BB080449EE4;
typedef struct RecordCode80447BB080449EE4 RecordCode80447BB080449EE4;

struct __OSPackId;
typedef struct __OSPackId __OSPackId;

struct RecordCode80447BB080449EE4;
struct RecordCode80447BB080449EE4 {
    char pad0[0x7F];
    signed char slot;
    char pad80;
    u8 team;
    char pad82[0xF];
    u8 computer;
};



struct Body;
struct Character;
struct Controller;
struct Controls;
struct Ctrl;
struct Held;
struct Mode;
struct Model;
struct Mount;
struct Profile;
struct RecordCode80447BB080449EE4;
struct Rider;
struct Settings;
struct Shared_Body;
struct Shared_Hud;
struct Shared_Model;
struct Shared_Profile;
struct Shared_StateInfo;
struct Shared_Voice;
struct StateInfo;
struct TeamInfo;
struct View;


struct IntegerState88;

struct CPlayerPool_t;


struct IntPair;

struct ActorCode80447BB0;
struct Part;



struct ObjectState96;
typedef struct ObjectState96 ObjectState96;

struct RecordCode80447BB0;

extern short D_800CF198[];

s32 Render_IsSnapshotActive(void);

extern s32 func_80448BB4_de(u16 *ptr, u16 *csum, u16 *icsum);
extern s32 func_80447130_de(OSPfs *pfs);
extern s32 func_804486B8_de(OSPfs *pfs);
#endif
