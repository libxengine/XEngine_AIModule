#pragma once
/********************************************************************
//    Created:     2025/03/19  16:16:02
//    File Name:   D:\XEngine_AIModule\XEngine_Source\AICodec_AVCodec\AICodec_Define.h
//    File Path:   D:\XEngine_AIModule\XEngine_Source\AICodec_AVCodec
//    File Base:   AICodec_Define
//    File Ext:    h
//    Project:     XEngine
//    Author:      qyt
//    Purpose:     AI模块导出函数
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                     导出的函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG AICodec_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                     AI音频转文字                                     */
/************************************************************************/
/********************************************************************
函数名称：AICodec_AudioTText_Init
函数功能：初始化音频转文本AI
 参数.一：lpszModel
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入MODEL路径
 参数.二：lpszLanauage
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：可以为aotu
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XHANDLE AICodec_AudioTText_Init(LPCXSTR lpszModel, LPCXSTR lpszLanauage);
/********************************************************************
函数名称：AICodec_AudioTText_ConvertFile
函数功能：转换PCM文件
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要转换的PCM文件
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AICodec_AudioTText_ConvertFile(XHANDLE xhToken, LPCXSTR lpszFileName);
/********************************************************************
函数名称：AICodec_AudioTText_Close
函数功能：关闭音频转文本AI
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool AICodec_AudioTText_Close(XHANDLE xhToken);
