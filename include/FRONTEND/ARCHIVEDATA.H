#ifndef FRONTEND_ARCHIVEDATA_H
#define FRONTEND_ARCHIVEDATA_H
#include "TYPES.H"
/* Records of the menu resource archive as they sit in memory after the archive header is read. */
/* One entry of the resource map (D_8014D9B4, 12 bytes): the entry's offset in the archive data
   and size, and the buffer it was loaded into (0 while not loaded). */
typedef struct ArchiveMapEntry {
    s32 offset;
    s32 size;
    void *data;
} ArchiveMapEntry;
/* The header block read from the start of the archive file (0x240 bytes); dataOffset is where the
   entry data starts. */
typedef struct ArchiveHeader {
    u8 unk0[0x23C];
    s32 dataOffset;
} ArchiveHeader;
/* The open menu archive (D_801539B0, 0x2A8 bytes): the file handle while it is open, the archive
   header, the resource map with its optional second copy of every loaded entry, the per-entry
   use counts and the cache mode (1 restores entries from the copies). */
typedef struct ArchiveFile {
    s32 handle;
    ArchiveHeader header;
    u8 unk244[0x50];
    ArchiveMapEntry *map;
    ArchiveMapEntry *copies;
    s32 unk29C;
    u16 *useCounts;
    s32 mode;
} ArchiveFile;
/* One entry of the text index (the section table of the string archive, 8 bytes): where the
   section of NUL-separated strings starts, relative to the archive base, and how many strings it holds. */
typedef struct ArchiveTextIndexEntry {
    s32 start;
    s32 count;
} ArchiveTextIndexEntry;
/* One font record of the archive (32 bytes, read at ROM header word 2; three fonts): the glyph cell
   width, the count of bitmaps, and where the font's 0x60 glyph records and the bitmap sizes sit. The
   halfwords at 0xA, 0xC and 0x10 (spacing, line height) are read by func_80411C98_de, func_80411CD0_de and
   func_80411C60_de; bytes 0..7, 0x12 and the word at 0x1C have no reader. */
typedef struct ArchiveFontRecord {
    u8 unused0[8];
    s16 glyphWidth;
    s16 field_A;
    s16 field_C;
    s16 bitmapCount;
    s16 field_10;
    s16 unused12;
    s32 glyphTableOffset;
    s32 field_18;
    s32 unused1C;
} ArchiveFontRecord;
#endif
