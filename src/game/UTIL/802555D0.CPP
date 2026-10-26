#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ENTRYRECAT18V3.H"
#include "COMMON/S1.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/STATERECAT34.H"
#include "TYPES.H"
#include "UTIL/MEASUREDRECAT8V2.H"
#include "stddef.h"
#include "UTIL/802555D0.H"

s32 func_80255630_de(s8 *arena, void *requestedAddress, s32 requestedBytes) {
    s32 alignedBlockBytes;
    s32 leadingFreeBytes;
    u32 followingFreeAddress;
    u32 unlinkSuccessorAddress;
    u32 candidateNextAddress;
    u32 replacementTailAddress;
    void *nextPhysicalBlock;
    void *previousFreeBlock;
    void *allocationEnd;
    void *freeSpanEnd;
    void *freeSpanStart;
    void *firstFreeBlock;
    void *allocationHeader;
    void *containingBlock;
    alignedBlockBytes = (requestedBytes + 0x2F) & ~0xF;
    firstFreeBlock = ((struct MeasuredRecAt8V2 *)(arena))->value;
    if (firstFreeBlock != NULL) {
        containingBlock = firstFreeBlock;
        while (((struct MeasuredRecAt4V4 *)(containingBlock))->value != 0) {
            candidateNextAddress = ((struct MeasuredRecAt4V4 *)(containingBlock))->value;
            if (candidateNextAddress >= (u32) requestedAddress) {
                break;
            }
            containingBlock = (void *) candidateNextAddress;
        }
        freeSpanStart = containingBlock + ((struct MeasuredRecAt10V3 *)(containingBlock))->value;
        freeSpanEnd = freeSpanStart + ((struct MeasuredRecAt14V3 *)(containingBlock))->value;
        allocationHeader = requestedAddress - 0x20;
        allocationEnd = allocationHeader + alignedBlockBytes;
        if ((u32) allocationHeader >= (u32) freeSpanStart) {
            if ((u32) freeSpanEnd >= (u32) allocationEnd) {
                s32 trailingFreeBytes = freeSpanEnd - allocationEnd;
                ((struct MeasuredRecAt10V3 *)(allocationHeader))->value = alignedBlockBytes;
                ((struct MeasuredRecAt14V3 *)(allocationHeader))->value = trailingFreeBytes;
                if (trailingFreeBytes != 0) {
                    ((struct MeasuredRecAt4V3 *)(requestedAddress))[-1].value = containingBlock;
                    followingFreeAddress = ((struct MeasuredRecAt4V4 *)(containingBlock))->value;
                    ((struct MeasuredRecAt4V4 *)(allocationHeader))->value = followingFreeAddress;
                    if (((struct MeasuredRecAt4V4 *)(containingBlock))->value != 0) {
                        *(void **) followingFreeAddress = allocationHeader;
                    }
                    ((struct MeasuredRecAt4V4 *)(containingBlock))->value = (u32) allocationHeader;
                    if (((struct MeasuredRecAtCV2 *)(arena))->value == containingBlock) {
                        ((struct MeasuredRecAtCV2 *)(arena))->value = allocationHeader;
                    }
                } else {
                    ((struct MeasuredRecAt4V3 *)(requestedAddress))[-1].value = NULL;
                    ((struct MeasuredRecAt4V4 *)(allocationHeader))->value = 0U;
                }
                leadingFreeBytes = allocationHeader - (containingBlock + ((struct MeasuredRecAt10V3 *)(containingBlock))->value);
                ((struct MeasuredRecAt14V3 *)(containingBlock))->value = leadingFreeBytes;
                if (leadingFreeBytes == 0) {
                    previousFreeBlock = ((struct MeasuredRecAt0V2 *)(containingBlock))->value;
                    if (previousFreeBlock != NULL) {
                        ((struct MeasuredRecAt4V4 *)(previousFreeBlock))->value = ((struct MeasuredRecAt4V4 *)(containingBlock))->value;
                    }
                    unlinkSuccessorAddress = ((struct MeasuredRecAt4V4 *)(containingBlock))->value;
                    if (unlinkSuccessorAddress != 0) {
                        *(void **) unlinkSuccessorAddress = ((struct MeasuredRecAt0V2 *)(containingBlock))->value;
                    }
                    if (((struct MeasuredRecAt8V2 *)(arena))->value == containingBlock) {
                        ((struct MeasuredRecAt8V2 *)(arena))->value = ((struct MeasuredRecAt4V2 *)(containingBlock))->value;
                    }
                    if (((struct MeasuredRecAtCV2 *)(arena))->value == containingBlock) {
                        replacementTailAddress = ((struct MeasuredRecAt4V4 *)(containingBlock))->value;
                        if (replacementTailAddress == 0) {
                            replacementTailAddress = (u32) ((struct MeasuredRecAt0V2 *)(containingBlock))->value;
                        }
                        ((struct MeasuredRecAtCV2 *)(arena))->value = (void *) replacementTailAddress;
                    }
                    ((struct MeasuredRecAt0V2 *)(containingBlock))->value = NULL;
                    ((struct MeasuredRecAt4V4 *)(containingBlock))->value = 0U;
                }
                ((struct MeasuredRecAt8V2 *)(allocationHeader))->value = containingBlock;
                nextPhysicalBlock = ((struct MeasuredRecAtCV2 *)(containingBlock))->value;
                ((struct MeasuredRecAtCV2 *)(allocationHeader))->value = nextPhysicalBlock;
                if (((struct MeasuredRecAtCV2 *)(containingBlock))->value != NULL) {
                    ((struct MeasuredRecAt8V2 *)(nextPhysicalBlock))->value = allocationHeader;
                }
                ((struct MeasuredRecAtCV2 *)(containingBlock))->value = allocationHeader;
                return (s32) requestedAddress;
            }
        }
    }
    return 0;
}

/* Coalesces every block that physically follows a pool's anchor block at 0x10 into its physical
   predecessor: first puts an empty predecessor on the free list (after the next non-empty block, or
   at the head), then grows it by the block's header and size, unlinks the block from the physical
   chain and, when it was free, from the free list. Written like func_80255B2C_de, which absorbs one block. */







void func_80255780_de(Pool80255720 *arena)
{
    Block80255720 *block;
    Block80255720 *header;
    Block80255720 *other;
    Block80255720 *scan;
    Block80255720 *next;

    while (arena->anchor->next_phys != 0) {
        header = arena->anchor->next_phys;
        block = header->prev_phys;
        if (block->size == 0) {
            other = header->prev;
            if (other != 0) {
                block->prev = other;
            } else {
                scan = block;
                while (scan != 0) {
                    if (scan->size != 0) {
                        break;
                    }
                    scan = scan->prev_phys;
                }
                if (scan != 0) {
                    block->prev = scan;
                } else {
                    goto insert_head;
                }
                other = scan;
            }
            next = other->next;
            block->next = next;
            if (other->next != 0) {
                next->prev = block;
            }
            other->next = block;
            if (arena->tail == other) {
                arena->tail = block;
            }
            goto merge;
insert_head:
            block->next = arena->head;
            if (arena->head != 0) {
                arena->head->prev = block;
            } else {
                arena->tail = block;
            }
            arena->head = block;
        }

merge:
        block->size += header->offset + header->size;
        if (header->next_phys != 0) {
            header->next_phys->prev_phys = header->prev_phys;
        }
        header->prev_phys->next_phys = header->next_phys;

        if (header->size != 0) {
            if (header->prev != 0) {
                header->prev->next = header->next;
            }
            if (header->next != 0) {
                header->next->prev = header->prev;
            }
            if (arena->tail == header) {
                arena->tail = header->prev;
            }
        }
    }
}

/* Initialises a heap over a memory range: records its start and unrounded end, places one free block at the
   first 16-byte boundary covering the rest rounded down to 16 bytes, less a 0x20-byte header, and
   points the free list at that block when it has room. */




void func_802558B4_de(struct Heap *heap, char *start, s32 size) {
    struct BlockRecAt20 *block;

    heap->start = start;
    heap->end = start + size;
    block = (struct BlockRecAt20 *) (((u32) start + 15) & ~15);
    size -= (char *) block - start;
    size &= ~15;
    block->nextFree = 0;
    block->prevFree = 0;
    block->next = 0;
    block->prev = 0;
    block->size = 0x20;
    block->free = size - 0x20;
    heap->first = block;
    if (block->free != 0) {
        heap->last = block;
        heap->free = block;
    } else {
        heap->last = 0;
        heap->free = 0;
    }
}

/* Allocates from a heap with a first-fit search of its free list: the request plus the 0x20-byte header is
 * rounded up to 16 bytes, a block after the found block's used part takes that size and inherits the
 * remaining free space in the free list (replacing the found block), the found block leaves the free list,
 * the new block is linked after it in address order, and its data pointer is returned (0 when nothing
 * fits). */








void *func_80255920_de(HeapRecAtC *heap, s32 request) {
    BlockRecAt20 *block;
    BlockRecAt20 *split;
    u32 size;

    size = (request + 0x2F) & ~0xF;
    for (block = heap->head; block != 0; block = block->nextFree) {
        if (block->free >= size) {
            { u8 *cursor = (u8 *)block; cursor += block->size; split = (BlockRecAt20 *)cursor; }
            split->size = size;
            split->free = block->free - size;
            if (split->free != 0) {
                split->prevFree = block;
                split->nextFree = block->nextFree;
                if (block->nextFree != 0) {
                    split->nextFree->prevFree = split;
                }
                block->nextFree = split;
                if (heap->tail == block) {
                    heap->tail = split;
                }
            } else {
                split->prevFree = 0;
                split->nextFree = 0;
            }
            block->free = 0;
            if (block->prevFree != 0) {
                block->prevFree->nextFree = block->nextFree;
            }
            if (block->nextFree != 0) {
                block->nextFree->prevFree = block->prevFree;
            }
            if (heap->head == block) {
                heap->head = block->nextFree;
            }
            if (heap->tail == block) {
                heap->tail = block->nextFree != 0 ? block->nextFree : block->prevFree;
            }
            block->prevFree = 0;
            block->nextFree = 0;
            split->prev = block;
            split->next = block->next;
            if (block->next != 0) {
                split->next->prev = split;
            }
            block->next = split;
            return split->data;
        }
    }
    return 0;
}

/* Allocates from the top of a heap's free space with a first-fit search of its free list: the request plus the 0x20-byte header is rounded up to 16 bytes and carved from the end of the found block's free space; the found block leaves the free list once its free space is used up, the new block is linked after it in address order, and its data pointer is returned (0 when nothing fits). */








void *func_80255A34_de(HeapRecAtC *heap, s32 request)
{
    BlockRecAt20 *block;
    BlockRecAt20 *split;
    u32 size;

    size = (request + 0x2F) & ~0xF;
    for (block = heap->tail; block != 0; block = block->prevFree) {
        if (block->free >= size) {
            { u8 *cursor = (u8 *)block; cursor += block->size; cursor += block->free; cursor -= size; split = (BlockRecAt20 *)cursor; }
            split->size = size;
            split->free = 0;
            block->free -= size;
            split->nextFree = 0;
            split->prevFree = 0;
            if (block->free == 0) {
                if (block->prevFree != 0) {
                    block->prevFree->nextFree = block->nextFree;
                }
                if (block->nextFree != 0) {
                    block->nextFree->prevFree = block->prevFree;
                }
                if (heap->head == block) {
                    heap->head = block->nextFree;
                }
                if (heap->tail == block) {
                    heap->tail = block->nextFree != 0 ? block->nextFree : block->prevFree;
                }
                block->prevFree = 0;
                block->nextFree = 0;
            }
            split->prev = block;
            split->next = block->next;
            if (block->next != 0) {
                split->next->prev = split;
            }
            block->next = split;
            return split->data;
        }
    }
    return 0;
}

s32 func_80255B2C_de(Pool80255ACC *arena, char *dataToFree) {
    Block80255720 *block;
    Block80255720 *header;
    Block80255720 *other;
    Block80255720 *scan;
    u32 next;

    header = (Block80255720 *)(dataToFree - 0x20);
    block = header->prev_phys;
    if (block->size == 0) {
        other = header->prev;
        if (other != 0) {
            block->prev = other;
        } else {
            scan = block;
            while (scan != 0) {
                if (scan->size != 0) {
                    break;
                }
                scan = scan->prev_phys;
            }
            if (scan != 0) {
                block->prev = scan;
            } else {
                goto insert_head;
            }
            other = scan;
        }
        next = (u32)other->next;
        block->next = (Block80255720 *)next;
        if (other->next != 0) {
            *(Block80255720 **)next = block;
        }
        other->next = block;
        if (arena->tail == other) {
            arena->tail = block;
        }
        goto merge;
insert_head:
        block->next = arena->head;
        if (arena->head != 0) {
            arena->head->prev = block;
        } else {
            arena->tail = block;
        }
        arena->head = block;
    }

merge:
    block->size += header->offset + header->size;
    if (header->next_phys != 0) {
        header->next_phys->prev_phys = header->prev_phys;
    }
    header->prev_phys->next_phys = header->next_phys;

    if (header->size != 0) {
        if (header->prev != 0) {
            header->prev->next = header->next;
        }
        if (header->next != 0) {
            header->next->prev = header->prev;
        }
        if (arena->tail == header) {
            arena->tail = header->prev;
        }
    }
    return block->size - 0x20;
}

void func_80255C4C_de(Pool80255ACC *arena, s32 *totalBytesOut, u32 *largestBlockBytesOut) {
    u32 previousLargestBytes;
    u32 largestBytes;
    void *freeBlockCursor;

    *totalBytesOut = 0;
    *largestBlockBytesOut = 0;
    freeBlockCursor = arena->head;
    if (freeBlockCursor != 0) {
        do {
            *totalBytesOut += (u32)((Block80255720 *)freeBlockCursor)->size;
            largestBytes = (u32)((Block80255720 *)freeBlockCursor)->size;
            previousLargestBytes = *largestBlockBytesOut;
            if (largestBytes < previousLargestBytes) {
                largestBytes = previousLargestBytes;
            }
            *largestBlockBytesOut = largestBytes;
            freeBlockCursor = ((Block80255720 *)freeBlockCursor)->next;
        } while (freeBlockCursor != 0);
    }
}
