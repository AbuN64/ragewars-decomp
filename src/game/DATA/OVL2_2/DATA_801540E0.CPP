
#if defined(VERSION_US_REV1)
extern char rw_menu_paged_func_80407748_de[];
extern char rw_menu_paged_func_80407F6C_de[];
extern char rw_menu_paged_func_80442064_de[];
struct {
    unsigned int w0[2];
    unsigned char b1[12];
    unsigned int w2[4];
} D_auto_rodata_writable_801540E0 = {
    {
        0x00000000, 0x00000000,
    },
    {
        0x00, 0x01, 0x10, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x01,
    },
    {
        0x800D7734, (unsigned int)rw_menu_paged_func_80442064_de,
        (unsigned int)rw_menu_paged_func_80407F6C_de, (unsigned int)rw_menu_paged_func_80407748_de,
    },
};
#endif
