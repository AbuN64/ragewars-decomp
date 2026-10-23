
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/80154018 */
struct {
    unsigned char b0[4];
    unsigned int w1;
} D_blob_1422fe91830125957e86 = {
    {
        0x00, 0x00, 0xFF, 0x01,
    },
    0x800D771C,
};

extern char rw_menu_paged_func_80407748_de[];
extern char rw_menu_paged_func_80407F6C_de[];
extern char rw_menu_paged_func_80442064_de[];
struct {
    unsigned int w0[5];
    unsigned char b1[12];
    unsigned int w2[4];
} D_auto_rodata_writable_80154020 = {
    {
        (unsigned int)rw_menu_paged_func_80442064_de, (unsigned int)rw_menu_paged_func_80407F6C_de,
        (unsigned int)rw_menu_paged_func_80407748_de, 0x00000000, 0x00000000,
    },
    {
        0x00, 0x01, 0x10, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x01,
    },
    {
        0x800D7720, (unsigned int)rw_menu_paged_func_80442064_de,
        (unsigned int)rw_menu_paged_func_80407F6C_de, (unsigned int)rw_menu_paged_func_80407748_de,
    },
};
#endif
