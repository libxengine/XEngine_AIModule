#include "pch.h"
#include "AICodec_AudioTText/AICodec_AudioTText.h"
/********************************************************************
//    Created:     2025/03/19  15:48:01
//    File Name:   D:\XEngine_AIModule\XEngine_Source\AICodec_AVCodec\pch.cpp
//    File Path:   D:\XEngine_AIModule\XEngine_Source\AICodec_AVCodec
//    File Base:   pch
//    File Ext:    cpp
//    Project:     XEngine
//    Author:      qyt
//    Purpose:     导出实现
//    History:
*********************************************************************/
bool AICodec_IsErrorOccur = false;
XLONG AICodec_dwErrorCode = 0;
//////////////////////////////////////////////////////////////////////////
CAICodec_AudioTText m_AIAudioTText;
//////////////////////////////////////////////////////////////////////////
//                               导出实现
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG AICodec_GetLastError(int* pInt_SysError)
{
	if (NULL != pInt_SysError)
	{
		*pInt_SysError = errno;
	}
	return AICodec_dwErrorCode;
}
/************************************************************************/
/*                     AI音频转文字                                     */
/************************************************************************/
extern "C" XHANDLE AICodec_AudioTText_Init(LPCXSTR lpszModel, LPCXSTR lpszLanauage)
{
	return m_AIAudioTText.AICodec_AudioTText_Init(lpszModel, lpszLanauage);
}
extern "C" bool AICodec_AudioTText_ConvertFile(XHANDLE xhToken, LPCXSTR lpszFileName)
{
	return m_AIAudioTText.AICodec_AudioTText_ConvertFile(xhToken, lpszFileName);
}
extern "C" bool AICodec_AudioTText_Close(XHANDLE xhToken)
{
	return m_AIAudioTText.AICodec_AudioTText_Close(xhToken);
}