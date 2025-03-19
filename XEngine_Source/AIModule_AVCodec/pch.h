// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H

// 添加要在此处预编译的标头
#include "framework.h"

#endif //PCH_H
#include <iostream>
#include <fstream>
#include <vector>
#include <whisper.h>
#include <XEngine_Include/XEngine_CommHdr.h>
#include <XEngine_Include/XEngine_Types.h>
#include <XEngine_Include/XEngine_BaseLib/BaseLib_Define.h>
#include <XEngine_Include/XEngine_BaseLib/BaseLib_Error.h>
#include <XEngine_Include/XEngine_BaseLib/BaseSafe_Define.h>
#include <XEngine_Include/XEngine_BaseLib/BaseSafe_Error.h>
#include "AICodec_Define.h"
#include "AICodec_Error.h"
/********************************************************************
//    Created:     2025/03/19  15:48:27
//    File Name:   D:\XEngine_AIModule\XEngine_Source\AICodec_AVCodec\pch.h
//    File Path:   D:\XEngine_AIModule\XEngine_Source\AICodec_AVCodec
//    File Base:   pch
//    File Ext:    h
//    Project:     XEngine
//    Author:      qyt
//    Purpose:     公用头文件
//    History:
*********************************************************************/
extern bool AICodec_IsErrorOccur;
extern XLONG AICodec_dwErrorCode;

#pragma comment(lib,"../../XEngine_Release/X86_64/whisper.lib")
#pragma comment(lib,"XEngine_BaseLib/XEngine_BaseLib")
#pragma comment(lib,"XEngine_BaseLib/XEngine_BaseSafe")