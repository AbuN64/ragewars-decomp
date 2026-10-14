#include "shared/level_actor.h"
#include "span_1000/code_80245980.h"
/* Resets an object through func_8024DD10_de, then clears its words from 0x1C to 0x38 and at 0x40, 0x44
   and 0x4C, sets the word at 0x3C to -1 and stores D_800C8914 in the float at 0x48. */




void func_80246184_de(void *arg0) {
    float k;

    func_8024DD10_de(arg0);
    k = D_800C8914;
    ((LevelActor *)arg0)->position1.x = 0;
    ((LevelActor *)arg0)->position1.y = 0;
    ((LevelActor *)arg0)->position1.z = 0;
    ((LevelActor *)arg0)->motionAngles.x = 0;
    ((LevelActor *)arg0)->motionAngles.y = 0;
    ((LevelActor *)arg0)->motionAngles.z = 0;
    ((LevelActor *)arg0)->attached = 0;
    ((LevelActor *)arg0)->motionState = 0;
    ((LevelActor *)arg0)->motionIndex = -1;
    ((LevelActor *)arg0)->floorHeight = 0;
    ((LevelActor *)arg0)->floorDirection.x = 0;
    ((LevelActor *)arg0)->floorDirection.z = 0;
    ((LevelActor *)arg0)->floorDirection.y = k;
}
