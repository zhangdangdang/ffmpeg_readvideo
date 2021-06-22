#include <iostream>
#include"MmAV.h"
#include "MmAVPacketPrivate.h"
#include "MmAVReaderPrivate.h"
//这里不要加 ffmpeg的include
//这里不要加 ffmpeg的include
MmAVReader::MmAVReader()
{
	imp = new MmAVReaderPrivate();
	imp->formatCtx= avformat_alloc_context();
}
MmAVReader::~MmAVReader()
{
	if (imp->formatCtx != nullptr) {
		avformat_free_context(imp->formatCtx);
		imp->formatCtx = nullptr;
	}
	if (imp != nullptr)
	{
		delete imp;
		imp = nullptr;
	}
}
//return 0 on success, a negative AVERROR on failure.
int MmAVReader::Open(const char* path)
{
	if (imp->formatCtx == nullptr) {
		return -1;
	}
	if (path == nullptr) {
		return -1;
	}
	int ret=avformat_open_input(&imp->formatCtx,path,nullptr, nullptr);

	if (!ret) {
		avformat_find_stream_info(imp->formatCtx,nullptr);
		av_dump_format(imp->formatCtx, 0, path, 0);
		return ret;
	}

	return ret;
}
int MmAVReader::Close()
{
	if (imp == nullptr) {
		return -1;
	}
	avformat_close_input(&imp->formatCtx);
	return 0;
}
int MmAVReader::Read(MmAVPacket* packet)
{
	if (imp == nullptr) {
		return -1;
	}
	int ret = av_read_frame(imp->formatCtx, packet->imp->pkt);
	return ret;
}