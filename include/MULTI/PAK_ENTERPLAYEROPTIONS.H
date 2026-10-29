#ifndef MULTI_PAK_ENTERPLAYEROPTIONS_H
#define MULTI_PAK_ENTERPLAYEROPTIONS_H
#include "COMMON/MENURECAT20V1.H"
#include "MULTI/SETUP_SETUPNAMESPINNER.H"
extern void Pak_EnterPlayerOptions(PlayerOptionsEntry *player);
extern void Pak_RestoreControllerSetup(void);
extern void Pak_RenderMenuEntryCallback(struct MenuStyle *menu, s8 *member);
#endif
