#if defined(VERSION_US_REV1)
/* Menu model preview lights (Frontend_DrawModelPreview copies the first 24 bytes as D_800DF520): ambient then light
 * colour bytes (r, g, b, pad) and direction bytes (x, y, z, pad), as bytes so every host reads the same colour and
 * direction. */
struct {
    unsigned char lights[24];
    unsigned int tail[2];
} D_auto_rodata_unresolved_800E351C_unclaimed_E4170 = {
    {
        0x96, 0x96, 0x96, 0x00, 0x96, 0x96, 0x96, 0x00, 0xC8, 0xC8, 0xC8, 0x00,
        0xC8, 0xC8, 0xC8, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    { 0x00000002, 0x0000000B },
};
#endif
