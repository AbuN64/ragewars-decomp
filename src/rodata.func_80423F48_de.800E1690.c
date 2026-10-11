/* class: switch jump table (8 branch offsets) of the 80423F48 jump switch; feeds landed rw_pool_804243E0_E22B0 row
 * semantic proposal: RwSwitchTableFunc80423F48_de
 * member=rodata/func_80423F48_de/800E1690 rom=0xDE260(de)+32B rom=0xEE8E0(eu)+32B rom=0xDCF10(us)+32B rom=0xE2290(us-rev1)+32B vram=0x800E1690 sect=rodata seg=span_E1720 status=open symbol=D_auto_rodata_func_80423F48_de_800E1690(legacy-src)
 * cart rows: de 0xDE260->0xDE280 = 32 B; eu 0xEE8E0->0xEE900 = 32 B; us 0xDCF10->0xDCF30 = 32 B; us-rev1 0xE2290->0xE22B0 = 32 B. eu-x holds no row (legacy guard set matches exactly: DE/EU/US/US_REV1, no EU_X). us and us-rev1 values are identical in the legacy draft. Values verbatim from src/rodata.func_80423F48_de.800E1690.c with VERSION_US_REV -> VERSION_US_REV1 fixed and guard order normalized to DE/EU/US/US_REV1. */
#if defined(VERSION_DE)
const unsigned int D_auto_rodata_func_80423F48_de_800E1690[8] = {
    0x00423F90, 0x00424020, 0x00424074, 0x0042409C, 0x00423FB0, 0x0042410C, 0x00424060, 0x00424088,
};
#elif defined(VERSION_EU)
const unsigned int D_auto_rodata_func_80423F48_de_800E1690[8] = {
    0x00424730, 0x004247C0, 0x00424814, 0x0042483C, 0x00424750, 0x004248AC, 0x00424800, 0x00424828,
};
#elif defined(VERSION_US)
const unsigned int D_auto_rodata_func_80423F48_de_800E1690[8] = {
    0x00424170, 0x00424200, 0x00424254, 0x0042427C, 0x00424190, 0x004242EC, 0x00424240, 0x00424268,
};
#elif defined(VERSION_US_REV1)
const unsigned int D_auto_rodata_func_80423F48_de_800E1690[8] = {
    0x00424170, 0x00424200, 0x00424254, 0x0042427C, 0x00424190, 0x004242EC, 0x00424240, 0x00424268,
};
#endif
