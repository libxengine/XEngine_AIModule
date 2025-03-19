#include "pch.h"
#include "AICodec_AudioTText.h"
/********************************************************************
//    Created:     2025/03/19  15:40:19
//    File Name:   D:\XEngine_AIModule\XEngine_Source\AICodec_AVCodec\AICodec_AudioTText\AICodec_AudioTText.cpp
//    File Path:   D:\XEngine_AIModule\XEngine_Source\AICodec_AVCodec\AICodec_AudioTText
//    File Base:   AICodec_AudioTText
//    File Ext:    cpp
//    Project:     XEngine
//    Author:      qyt
//    Purpose:     AI模块-音频转文字
//    History:
*********************************************************************/
CAICodec_AudioTText::CAICodec_AudioTText()
{
}
CAICodec_AudioTText::~CAICodec_AudioTText()
{
}
//////////////////////////////////////////////////////////////////////////
//                    公有函数
//////////////////////////////////////////////////////////////////////////
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
XHANDLE CAICodec_AudioTText::AICodec_AudioTText_Init(LPCXSTR lpszModel, LPCXSTR lpszLanauage)
{
	AICodec_IsErrorOccur = false;

	if ((NULL == lpszModel) || (NULL == lpszLanauage))
	{
		AICodec_IsErrorOccur = true;
		AICodec_dwErrorCode = ERROR_XENGINE_AICodec_AVCODEC_AUDIOTTEXT_PARAMENT;
		return NULL;
	}
	//申请句柄内存
	AICodec_AUDIOTTEXT* pSt_AIAudioTText = new AICodec_AUDIOTTEXT;
	if (NULL == pSt_AIAudioTText)
	{
		AICodec_IsErrorOccur = true;
		AICodec_dwErrorCode = ERROR_XENGINE_AICodec_AVCODEC_AUDIOTTEXT_MALLOC;
		return NULL;
	}
	//初始化参数
	*pSt_AIAudioTText = {};
	pSt_AIAudioTText->st_WhisperCtxParams = whisper_context_default_params();
	pSt_AIAudioTText->st_WhisperCtxParams.use_gpu = false;
	pSt_AIAudioTText->pSt_Whisper = whisper_init_from_file_with_params(lpszModel, pSt_AIAudioTText->st_WhisperCtxParams);
	
	if (NULL == pSt_AIAudioTText->pSt_Whisper)
	{
		AICodec_IsErrorOccur = true;
		AICodec_dwErrorCode = ERROR_XENGINE_AICodec_AVCODEC_AUDIOTTEXT_FAILED;
		return NULL;
	}
	pSt_AIAudioTText->st_WhisperFullParams = whisper_full_default_params(WHISPER_SAMPLING_GREEDY);
	pSt_AIAudioTText->st_WhisperFullParams.print_realtime = false;
	pSt_AIAudioTText->st_WhisperFullParams.print_progress = true;
	pSt_AIAudioTText->st_WhisperFullParams.print_timestamps = true;
	pSt_AIAudioTText->st_WhisperFullParams.print_special = false;
	pSt_AIAudioTText->st_WhisperFullParams.single_segment = false;
	pSt_AIAudioTText->st_WhisperFullParams.no_context = true;
	pSt_AIAudioTText->st_WhisperFullParams.split_on_word = true;  // 允许在单词间分割
	pSt_AIAudioTText->st_WhisperFullParams.n_threads = 4;
	pSt_AIAudioTText->st_WhisperFullParams.language = "auto";
	pSt_AIAudioTText->st_WhisperFullParams.translate = false;
	return pSt_AIAudioTText;
}
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
bool CAICodec_AudioTText::AICodec_AudioTText_ConvertFile(XHANDLE xhToken, LPCXSTR lpszFileName)
{
	AICodec_IsErrorOccur = false;

	AICodec_AUDIOTTEXT* pSt_AIAudioTText = (AICodec_AUDIOTTEXT*)xhToken;
	if (NULL == pSt_AIAudioTText)
	{
		AICodec_IsErrorOccur = true;
		AICodec_dwErrorCode = ERROR_XENGINE_AICodec_AVCODEC_AUDIOTTEXT_PARAMENT;
		return NULL;
	}
	std::vector<float> stl_VectorAudio;
	AICodec_AudioTText_PCMRead(lpszFileName, &stl_VectorAudio);

	if (0 != whisper_full(pSt_AIAudioTText->pSt_Whisper, pSt_AIAudioTText->st_WhisperFullParams, stl_VectorAudio.data(), (int)stl_VectorAudio.size()))
	{
		AICodec_IsErrorOccur = true;
		AICodec_dwErrorCode = ERROR_XENGINE_AICodec_AVCODEC_AUDIOTTEXT_PARAMENT;
		return NULL;
	}
	const int nSegments = whisper_full_n_segments(pSt_AIAudioTText->pSt_Whisper);
	for (int i = 0; i < nSegments; ++i)
	{
		const char* text = whisper_full_get_segment_text(pSt_AIAudioTText->pSt_Whisper, i);
		XCHAR tszGBKBuffer[2048] = {};
		BaseLib_Charset_UTFToAnsi(text, tszGBKBuffer);
		printf("%s\n", tszGBKBuffer);
	}

	return true;
}
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
bool CAICodec_AudioTText::AICodec_AudioTText_Close(XHANDLE xhToken)
{
	AICodec_IsErrorOccur = false;

	AICodec_AUDIOTTEXT* pSt_AIAudioTText = (AICodec_AUDIOTTEXT*)xhToken;
	if (NULL != pSt_AIAudioTText)
	{
		whisper_free(pSt_AIAudioTText->pSt_Whisper);
		delete pSt_AIAudioTText;
		pSt_AIAudioTText = NULL;
	}

	return true;
}
//////////////////////////////////////////////////////////////////////////
//                    保护函数
//////////////////////////////////////////////////////////////////////////
bool CAICodec_AudioTText::AICodec_AudioTText_PCMRead(LPCXSTR lpszFileName, std::vector<float>* pStl_VectorPCMData)
{
	AICodec_IsErrorOccur = false;

	FILE* pSt_File = _xfopen(lpszFileName, _X("rb"));
	if (NULL == pSt_File)
	{
		return false;
	}
	fseek(pSt_File, 0, SEEK_END);
	size_t nSize = ftell(pSt_File);
	fseek(pSt_File, 0, SEEK_SET);
	std::vector<int16_t> stl_VectorPCMData(nSize / sizeof(int16_t));
	size_t nRet = fread(stl_VectorPCMData.data(), 1, nSize, pSt_File);
	if (nRet != nSize)
	{
		return false;
	}

	pStl_VectorPCMData->resize(stl_VectorPCMData.size());
	for (size_t i = 0; i < stl_VectorPCMData.size(); i++) {
		(*pStl_VectorPCMData)[i] = stl_VectorPCMData[i] / 32768.0f;  // 归一化到 [-1, 1]
	}

	return true;
}
std::string to_timestamp(int64_t t, bool comma) {
	int64_t msec = t * 10;
	int64_t hr = msec / (1000 * 60 * 60);
	msec = msec - hr * (1000 * 60 * 60);
	int64_t min = msec / (1000 * 60);
	msec = msec - min * (1000 * 60);
	int64_t sec = msec / 1000;
	msec = msec - sec * 1000;

	char buf[32];
	snprintf(buf, sizeof(buf), "%02d:%02d:%02d%s%03d", (int)hr, (int)min, (int)sec, comma ? "," : ".", (int)msec);

	return std::string(buf);
}

static bool output_srt(struct whisper_context* ctx, const char* fname) {
	std::ofstream fout(fname);
	if (!fout.is_open()) {
		fprintf(stderr, "%s: failed to open '%s' for writing\n", __func__, fname);
		return false;
	}

	fprintf(stderr, "%s: saving output to '%s'\n", __func__, fname);

	const int n_segments = whisper_full_n_segments(ctx);
	for (int i = 0; i < n_segments; ++i) {
		const char* text = whisper_full_get_segment_text(ctx, i);
		const int64_t t0 = whisper_full_get_segment_t0(ctx, i);
		const int64_t t1 = whisper_full_get_segment_t1(ctx, i);
		std::string speaker = "";

		fout << i + 1 << "\n";
		fout << to_timestamp(t0, true) << " --> " << to_timestamp(t1, true) << "\n";
		fout << speaker << text << "\n\n";
	}

	return true;
}