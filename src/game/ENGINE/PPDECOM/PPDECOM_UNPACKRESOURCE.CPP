#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PACKEDMESHMATERIAL.H"
#include "RENDER/8028469C.H"
#include "TYPES.H"
#include "stddef.h"
#include "sdk/libgultra_inferred/RNC_UNPACKMETHOD2.H"
#include "sdk/libgultra/part_800C7F20/RNC_UNPACKMETHOD1.H"

void Cache_ReplaceResourceBlock(s32, void **, void *);
void * Cache_AllocResourceBlock(s32, void *, s32);
void * func_80254600_de(s32, s32, s32);
extern void *func_802BD3A0_de(void *destination, const void *source, int count);
 /* extern */
/* extern */
/* Unpack or copy a resource into an allocated buffer and install it. */
s32 Ppdecom_UnpackResource(void **handle, s32 retainUncompressed) {
    s32 succeeded;
    u8 compressionMethod;
    void **block;
    ObjRecAt4V2 *sourceBlock;
    ObjRecAt12 *packedHeader;
    ObjRecAt4V2 *copySourceBlock;
    sourceBlock = *handle;
    packedHeader = sourceBlock->unk0;
    if ((packedHeader->unk0 & ~0xFF) == 0x524E4300) {
        if (retainUncompressed != 0) {
            block = func_80254600_de(0, (s32) handle, packedHeader->unk4);
        } else {
            block = Cache_AllocResourceBlock(0, handle, packedHeader->unk4);
        }
        if (block != NULL) {
            compressionMethod = packedHeader->unk0; /* the method: low byte of the RNC magic word */
            switch (compressionMethod) {
            case 1:
                Rnc_UnpackMethod1(&packedHeader->unk12, *block, packedHeader->unk8, packedHeader->unk4);
                break;
            case 2:
                Rnc_UnpackMethod2(packedHeader, *block, packedHeader->unk8, packedHeader->unk4);
                break;
            default:
                break;
            }
            succeeded = 1;
        } else {
            succeeded = 0;
        }
    } else if (retainUncompressed == 0) {
        block = Cache_AllocResourceBlock(0, handle, sourceBlock->unk4);
        if (block != NULL) {
            copySourceBlock = *handle;
            succeeded = 1;
            func_802BD3A0_de(*block, copySourceBlock->unk0, copySourceBlock->unk4);
        } else {
            succeeded = 0;
        }
    } else {
        succeeded = 1;
        goto done;
    }
    Cache_ReplaceResourceBlock(0, handle, block);
done:
    return succeeded;
}

#if defined(VERSION_US)
char rodata_unresolved_80285208[8] =
    "Channels";
#endif
