#ifndef SDK_PFS_PFS_DECODECHANNELSTATUS_H
#define SDK_PFS_PFS_DECODECHANNELSTATUS_H
#include "sdk/OSCONTREQUESFORMATSHORT.H"
extern void __osPfsRequestOneChannel(int channel);
extern void Pfs_DecodeChannelStatus(int channel, ControllerInitStatusBytes *data);
#endif
