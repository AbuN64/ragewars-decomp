#include "span_16E000/code_804366C4.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "decomp/argb_color.h"
#include "gfx.h"
#include "shared/func_80421E70_eu_closed.h"
#include "shared/func_804235A8_eu_closed.h"
#include "shared/func_804235A8_eu_layout.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_8022A274.h"
#include "span_1000/code_8023B9A0.h"
#include "span_1000/code_80243A80.h"
#include "span_1000/code_80246E34.h"
#include "span_1000/code_802508E0.h"
#include "span_1000/code_80256220.h"
#include "span_1000/code_8025A3EC.h"
#include "span_1000/code_8025C544.h"
#include "span_1000/code_80265370.h"
#include "span_1000/code_8026AC38.h"
#include "span_1000/code_8027302C.h"
#include "span_1000/code_8028308C.h"
#include "span_1000/code_8028CCB8.h"
#include "span_1000/code_8028DF6C.h"
#include "span_1000/code_8028FC98.h"
#include "span_1000/code_802944E8.h"
#include "span_1000/code_80297CD0.h"
#include "span_1000/code_802A6AC0.h"
#include "span_1000/code_802B0388.h"
#include "span_1000/code_802B243C.h"
#include "span_1000/code_802B4730.h"
#include "span_1000/code_802B53FC.h"
#include "span_1000/code_802B8DD0.h"
#include "span_1000/code_802B9ED8.h"
#include "span_1000/code_802BA23C.h"
#include "span_1000/code_802BBC68.h"
#include "span_1000/code_802BE0D0.h"
#include "span_166000/code_80426310.h"
#include "span_16E000/code_80403BCC.h"
#include "span_16E000/code_8040B45C.h"
#include "span_16E000/code_8040F1E0.h"
#include "span_16E000/code_804143D8.h"
#include "span_16E000/code_8041BEA8.h"
#include "span_16E000/code_8041DF04.h"
#include "span_16E000/code_8041F1FC.h"
#include "span_16E000/code_80420E90.h"
#include "span_16E000/code_804221A0.h"
#include "span_16E000/code_804251F4.h"
#include "span_16E000/code_804264F0.h"
#include "span_16E000/code_8042BD40.h"
#include "span_16E000/code_8043962C.h"
#include "span_16E000/code_8043E9A8.h"
#include "span_16E000/code_8044ACCC.h"
#include "types.h"
#include "common/draft_fields_func_8026DC24_de.h"
#include "common/draft_fields_func_80283278_de.h"
#include "common/draft_fields_func_8028D474_de.h"
#include "common/draft_fields_func_8028D964_de.h"
/* Calls func_8029973C_de; when func_80299A08_de reports 0x1C8, passes the word at offset 0x14 of the
   object D_800E5694 points to to func_804369E8_de, then passes -1 to func_8042E988_de if func_802999A0_de
   reports 0x16 for zero and 0xB otherwise, and calls func_802998A8_de. Returns zero. */
extern struct func_80204468_S3 *D_800E5694;


extern void func_804369E8_de(s32);
extern s32 func_802999A0_de(s32);
extern void func_8042E988_de(s32);

s32 func_8043705C_de(void) {
    func_8029973C_de();
#if defined(VERSION_DE)
    if (func_80299A08_de() == 0x1C4) {
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    if (func_80299A08_de() == 0x1C8) {
#elif defined(VERSION_EU_X)
    if (func_80299A08_de() == 0x1CC) {
#endif
        func_804369E8_de(D_800E5694->unk14);
        func_8042E988_de(func_802999A0_de(0) == 0x16 ? -1 : 0xB);
        func_802998A8_de();
    }
    return 0;
}
