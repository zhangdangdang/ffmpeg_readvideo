#pragma once
#define __STDC_CONSTANT_MACROS
//
//extern "C"
//{
//#include <libavformat/avformat.h>//报找不到文件 的错误，cmakelists已经配好环境，问题可能出在，引用者的库没有配好
//}//希望其他调用者看不到这个接口 隐藏掉 创建MmPacketPrivate.h
class MmAVPacketPrivate;
class MmAVPacket
{
public:
	MmAVPacket();
	~MmAVPacket();
	//AVPacket* pkt = nullptr;
	MmAVPacketPrivate* imp = nullptr;

private:

};


class MmAVReaderPrivate;
class MmAVReader
{
public:
	MmAVReader();
	~MmAVReader();
	int Open(const char* path);
	int Close();

	int Read(MmAVPacket* packet);
	//MmAVPacketPrivate* pformatCtx = nullptr;
private:
	/*AVFormatContext* formatCtx = nullptr;*/
	MmAVReaderPrivate* imp = nullptr;
};

