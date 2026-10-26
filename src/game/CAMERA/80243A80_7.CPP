#include "COMMON/GROUP.H"
#include "COMMON/OBJECTLINKSC_2.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/EXTERNS_7.H"
#include "COMMON/OBJRECAT4V6.H"

void func_802453D4_de(void)
{
  f32 messageScaleY;
  f32 screenScaleX;
  int new_var2;
  f32 messageLineAdvance;
  f32 followingMessageScale;
  f32 messageDrawScale;
  f32 resolutionScale;
  f32 messageScaleX;
  s32 messageIndex;
  s32 messageY;
  s32 new_var;
  s32 screenHeight;
  void *sequenceContext;
  if ((D_800E2830->messageCount) > 0)
  {
    s32 messageLineHeight;
    s32 messageCenterX;
    messageLineHeight = 0x1A;
    messageCenterX = D_800E28D0 / 2;
    OnScreen_SetupTextRendering();
    screenScaleX = (f32) (D_800E28D0 / 284);
    messageScaleY = (f32) (D_800E28D4 / 222);
    screenHeight = D_800E28D4;
    if (screenHeight >= 0xDF)
    {
      messageY = 0xB4;
      resolutionScale = D_800C37C0_de;
      messageScaleX = screenScaleX * resolutionScale;
      messageScaleY *= resolutionScale;
    }
    else
    {
      messageY = 0x6E;
      resolutionScale = D_800C37C4_de;
      messageScaleX = screenScaleX * resolutionScale;
      messageScaleY *= resolutionScale;
    }
    new_var = 0;
    func_802AAB68_de(messageScaleX, messageScaleY);
    sequenceContext = D_800E2830;
    D_801376F8.shadowX = 1;
    D_801376F8.shadowY = 1;
    messageIndex = new_var;
    if ((((Shared_MenuContext *)(sequenceContext))->messageCount) > new_var)
    {
      new_var2 = 0;
      messageDrawScale = D_800C37C8_de;
      followingMessageScale = D_800C37CC_de;
      do
      {
        func_802A8F28_de(((Shared_MenuContext *)sequenceContext)->messages[messageIndex], messageCenterX, messageY, 0xFF, 1, 1, messageDrawScale, messageDrawScale);
        messageLineAdvance = ((f32) messageLineHeight) * messageScaleY;
        screenScaleX = (f32) (D_800E28D0 / 284);
        messageScaleY = ((f32) (D_800E28D4 / 222)) * followingMessageScale;
        messageY = (s32) (((f32) messageY) + messageLineAdvance);
        func_802AAB68_de(screenScaleX * followingMessageScale, messageScaleY);
        messageIndex += 1;
      }
      while (messageIndex < ((Shared_MenuContext *)(sequenceContext = D_800E2830))->messageCount);
    }
  }
}

s32 func_80245618_de(s32 requestId, ContextCallback requestContextCallback, VoidCallback completionCallback) {
    s32 result;

    result = func_804030E0_de(requestId);
    if (D_800E2830->requestE0 == requestId) {
        D_800E2830->callbackE4 = requestContextCallback;
        D_800E2830->callbackE8 = completionCallback;
    } else {
        if (requestContextCallback != 0) {
            requestContextCallback(D_800E2830);
        }
        if (completionCallback != 0) {
            completionCallback();
        }
    }
    return result;
}
