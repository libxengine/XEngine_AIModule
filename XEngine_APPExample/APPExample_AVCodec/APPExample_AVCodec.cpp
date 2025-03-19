#ifdef _MSC_BUILD
#include <windows.h>
#include <tchar.h>
#pragma comment(lib,"../../XEngine_Source/x64/Debug/AIModule_AVCodec")
#pragma comment(lib,"Ws2_32")
#endif
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <list>
#include <XEngine_Include/XEngine_CommHdr.h>
#include <XEngine_Include/XEngine_Types.h>
#include <XEngine_Include/XEngine_ProtocolHdr.h>
#include <XEngine_Include/XEngine_BaseLib/BaseLib_Define.h>
#include <XEngine_Include/XEngine_BaseLib/BaseLib_Error.h>
#include <XEngine_Include/XEngine_Core/Cryption_Define.h>
#include <XEngine_Include/XEngine_Core/Cryption_Error.h>
#include <XEngine_Include/XEngine_Client/APIClient_Define.h>
#include <XEngine_Include/XEngine_Client/APIClient_Error.h>
#include "../../XEngine_Source/AIModule_AVCodec/AICodec_Define.h"
#include "../../XEngine_Source/AIModule_AVCodec/AICodec_Error.h"

//需要优先配置XEngine
//WINDOWS使用VS2022 x86 或者 x64 debug 编译
//linux使用下面的命令编译
//g++ -std=c++17 -Wall -g APPClient_RestApi.cpp -o APPClient_RestApi.exe -I ../../XEngine_Source/XEngine_Depend/XEngine_Module/jsoncpp -L ../../XEngine_Release -lXEngine_BaseLib -lXClient_APIHelp -ljsoncpp -Wl,-rpath=../../XEngine_Release

//任务管理
int APPExample_AVCodec_AudioTText()
{
	XHANDLE xhToken = AICodec_AudioTText_Init("D:\\whisper.cpp\\models\\ggml-large-v3-turbo.bin", "auto");
	if (NULL == xhToken)
	{
		_xtprintf("AIModule_AudioTText_Init:%lX\n", AICodec_GetLastError());
		return -1;
	}
	AICodec_AudioTText_ConvertFile(xhToken, "D:\\XEngine_AIModule\\XEngine_Release\\output.pcm");
	AICodec_AudioTText_Close(xhToken);
	return 0;
}

int main()
{
#ifdef _MSC_BUILD
	WSADATA st_WSAData;
	WSAStartup(MAKEWORD(2, 2), &st_WSAData);
#endif

	APPExample_AVCodec_AudioTText();

#ifdef _MSC_BUILD
	WSACleanup();
#endif
	return 0;
}