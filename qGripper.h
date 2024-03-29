#include <iostream>
#include <Windows.h>
#include <process.h>	// to use _beginthread

#include "C:\Twincat\AdsApi\TcAdsDll\Include\TcAdsDef.h"
#include "C:\Twincat\AdsApi\TcAdsDll\Include\TcAdsApi.h"

using namespace std;
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
//	// nErr is executed status of functions
//	// nPort is not used, but the line that nPort is used as left-value should be reserved
//	// 
//	// add1 is IOffs shown in TwinCAT manager, which is different for each byte. 
//	// add2 is the Len shown in TwinCAT manager, which is the length of each byte, 1.
//extern long nErr[2];
extern long nPort;

extern AmsAddr Addr;
extern PAmsAddr pAddr;	// pointer of Addr;

extern long Rxadd0;
extern long Txadd0;

extern DWORD dwData;
extern DWORD dwDatab;

extern BYTE GripperMode;		// indicates which mode the gripper is in, only meaningful for 3-fingered gripper
extern bool GoToPosReqFlag;
//extern bool PosReqReachedFlag;

extern int gPos;
extern BYTE Speed;
extern BYTE Force;


///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// util function

// use structIdx to discriminate between 3-fingered and 2-fingered
// 0 = 2-fingered 1 = 3-fingered
// just the same as armIdx
bool initPara_gripper();

bool init_gripper_para();
bool init_gripper_motion();

bool open_gripper();
bool close_gripper();

// en/di function of the gripper
bool setGoToPosReqFlag(bool flag);

//BYTE ranges from 0 to 255
// include set var and send to the gripper
bool setReqPos(BYTE reqPos);
bool setReqSpeed(BYTE reqSpeed);
bool setReqForce(BYTE reqForce);


bool setGripperMode(char mode);