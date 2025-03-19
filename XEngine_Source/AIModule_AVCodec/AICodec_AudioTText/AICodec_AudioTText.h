#pragma once
/********************************************************************
//    Created:     2025/03/19  15:39:29
//    File Name:   D:\XEngine_AIModule\XEngine_Source\AICodec_AVCodec\AICodec_AudioTText\AICodec_AudioTText.h
//    File Path:   D:\XEngine_AIModule\XEngine_Source\AICodec_AVCodec\AICodec_AudioTText
//    File Base:   AICodec_AudioTText
//    File Ext:    h
//    Project:     XEngine
//    Author:      qyt
//    Purpose:     AI模块-音频转文字
//    History:
*********************************************************************/
typedef struct  
{
	struct whisper_context* pSt_Whisper;
	struct whisper_context_params st_WhisperCtxParams;
	struct whisper_full_params st_WhisperFullParams;
}AICodec_AUDIOTTEXT;

class CAICodec_AudioTText
{
public:
	CAICodec_AudioTText();
    ~CAICodec_AudioTText();
public:
	XHANDLE AICodec_AudioTText_Init(LPCXSTR lpszModel, LPCXSTR lpszLanauage);
	bool AICodec_AudioTText_ConvertFile(XHANDLE xhToken, LPCXSTR lpszFileName);
	bool AICodec_AudioTText_Close(XHANDLE xhToken);
protected:
	bool AICodec_AudioTText_PCMRead(LPCXSTR lpszFileName, std::vector<float> *pStl_VectorPCMData);
private:
};
