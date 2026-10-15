#include "span_16E000/code_8042F988.h"
#include "types.h"

extern PakMenuController *D_800E54A4;
extern void func_8029973C_de(void);
extern void func_804322AC_de(s32 player);

/* Dispatch player-slot events using the current shared menu controller and
 * its measured 0xB68-byte player records. */
s32 func_8042FB48_de(s32 a,s32 b,u32 event,s32 key){
    s32 index=event&65535;
    if((event>>16)==3){
        switch(D_800E54A4->phase){
            case 6:
            if(key==10){
                s32 state;
                state=D_800E54A4->players[index].state;
                if(state==4){
                    func_8029973C_de();
                    D_800E54A4->players[index].back=2;
                    D_800E54A4->players[index].state=2;
                    D_800E54A4->players[index].next=state;
                    func_804322AC_de(index);
                }
            }
            break;
            case 4:
            switch(key){
                case 11:
                case 13:
                if(D_800E54A4->players[index].state==0){
                    func_8029973C_de();
                    D_800E54A4->players[index].back=2;
                    D_800E54A4->players[index].state=2;
                    D_800E54A4->players[index].next=4;
                    func_804322AC_de(index);
                }
                break;
                case 10:
                {
                    s32 state;
                    state=D_800E54A4->players[index].state;
                    if(state==4){
                        func_8029973C_de();
                        D_800E54A4->players[index].back=2;
                        D_800E54A4->players[index].state=2;
                        D_800E54A4->players[index].next=state;
                        func_804322AC_de(index);
                    }
                    break;
                }
            }
            break;
            case 0:
            if(key==11||key==13){
                if(D_800E54A4->players[index].state==0){
                    func_8029973C_de();
                    D_800E54A4->players[index].back=2;
                    D_800E54A4->players[index].state=2;
                    D_800E54A4->players[index].next=12;
                    func_804322AC_de(index);
                }
            }
            break;
            case 3:
            if(key==11||key==13){
                if(D_800E54A4->players[index].state==0){
                    func_8029973C_de();
                    D_800E54A4->players[index].back=2;
                    D_800E54A4->players[index].state=2;
                    D_800E54A4->players[index].next=13;
                    D_800E54A4->players[index].sub=5;
                    func_804322AC_de(index);
                }
            }
            break;
            case 1:
            if(key==11||key==13){
                if(D_800E54A4->players[index].state==0){
                    func_8029973C_de();
                    D_800E54A4->players[index].state=14;
                    if(func_80434750_de()>=0){
                        D_800E54A4->players[index].back=2;
                        D_800E54A4->players[index].state=2;
                        D_800E54A4->players[index].next=13;
                        D_800E54A4->players[index].sub=6;
                    }
                    func_804322AC_de(index);
                }
            }
            break;
            case 2:
            if(key==11||key==13){
                if(D_800E54A4->players[index].state==0){
                    func_8029973C_de();
                    D_800E54A4->players[index].state=14;
                    if(func_80434750_de()>=0){
                        D_800E54A4->players[index].back=2;
                        D_800E54A4->players[index].state=2;
                        D_800E54A4->players[index].next=13;
                        D_800E54A4->players[index].sub=3;
                    }
                    func_804322AC_de(index);
                }
            }
            break;
            case 5:
            case 7:
            break;
        }
    }
    return 0;
}
