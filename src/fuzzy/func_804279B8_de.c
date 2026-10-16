/* Updates the selected player's appearance and creates its results-screen model. */
#include "TYPES.H"
typedef struct Vec { f32 x,y,z; } Vec;
typedef struct Entry { char pad[0x80]; s8 kind; char tail[0x15]; } Entry;
typedef struct Settings { char pad[13]; u8 mode; char padE[0xC2]; Entry entries[4]; } Settings;
typedef struct Screen { char pad[0x20]; char preview[0xA24]; s32 record; char padA48[0x14]; s32 player; } Screen;
typedef struct Record { char pad[4]; u8 kind; } Record;
extern Screen *D_800E4690;
extern Settings D_801462C8;
extern char D_8011FE88[];
typedef struct Row { s32 pad; f32 scale[4],distance[4]; Vec position[4]; s32 light[4]; char tail[12]; } Row;
extern Row D_800E3A58[];
extern void func_804284C0_de(s32,Settings *);
extern Record *func_8028D474_de(void *,s32);
extern s32 func_8041F140_de(s8);
extern void func_8041CAD8_de(void *,s32,s32,s32,s32,Vec,Vec,f32,s32);
typedef struct func_80427B98_S1 func_80427B98_S1;
struct func_80427B98_S1 {
    char pad0[0x20];
    char unk20;
};

void func_804279B8_de(void) {
 Vec scale; s32 record,index; u8 kind; Entry *entry; Settings *settings=&D_801462C8;
 if(settings->mode==4) {
 record=D_800E4690->record;
 entry = &settings->entries[D_800E4690->player];
 func_804284C0_de(record,settings);
 kind=func_8028D474_de(D_8011FE88,record)->kind;
 entry->kind=kind;
 index=func_8041F140_de((s8)kind);
 scale.x=D_800E3A58[index].scale[0]; scale.y=D_800E3A58[index].scale[0]; scale.z=D_800E3A58[index].scale[0];
 func_8041CAD8_de(D_800E4690->preview,9,entry->kind+0x38F,0x4B,0x5DC0,scale,D_800E3A58[index].position[0],D_800E3A58[index].distance[0],D_800E3A58[index].light[0]);
 }
}

