#include "TYPES.H"


#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E44A4_unclaimed_E5104 */
extern char g_frontend_HandlePakProfileInputEntry[];
#if defined(VERSION_US_REV1)
struct {
    void * previousHandler;
    s32 event;
    s32 actorKind;
} g_LinktablesEncodedWordsBlock15 __attribute__((aligned(4))) = {
    (void *)&g_frontend_HandlePakProfileInputEntry,
    11,
    19
};
typedef char g_LinktablesEncodedWordsBlock15SizeCheck[(sizeof(g_LinktablesEncodedWordsBlock15) == 12) ? 1 : -1];
#endif
#endif
