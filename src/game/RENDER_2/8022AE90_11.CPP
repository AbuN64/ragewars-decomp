#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "COMMON/INTEGERSTATE1250.H"
#include "RENDER_2/8022AE90.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"

void func_8022B9C4_de(void *actor) {
    if ((((struct IntegerState1218 *) ((s8 *) actor))->unk_1210) != 0) {
        if ((((struct IntegerState1218 *) ((s8 *) actor))->unk_5E4) != 0) {
            Weapons_SetPlayerState(actor, actor, 2);
        }
        (((struct IntegerState1218 *) ((s8 *) actor))->unk_1210) = 0;
        (((struct IntegerState1218 *) ((s8 *) actor))->unk_1214) = 0;
    }
}

/** Return the linked record with the greatest eight-slot score excluding itself. */
void *func_8022BA0C_de(Context *context) {
    RecordCode8022AE90 *node;
    RecordCode8022AE90 *base;
    RecordCode8022AE90 *bestNode = 0;
    int best = -1;

    node = context->head;
    if (node != 0) {
        base = context->base;
        do {
            unsigned int own = (unsigned int)((u8 *)node - (u8 *)base) / sizeof(RecordCode8022AE90);
            int score = 0;
            int i;
            for (i = 0; i < 8; i++) {
                if (i == own) {
                    continue;
                }
                score += node->scores->value[i];
                if (best < score) {
                    best = score;
                    bestNode = node;
                }
            }
            node = node->next;
        } while (node != 0);
    }
    return bestNode;
}

/** Read the global word at VRAM 0x80145048. */


int func_8022BA90_de(void) {
    return D_80145048;
}
