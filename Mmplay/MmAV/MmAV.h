#pragma once
#define __STDC_CONSTANT_MACROS
//
//extern "C"
//{
//#include <libavformat/avformat.h>//���Ҳ����ļ� �Ĵ���cmakelists�Ѿ���û�����������ܳ��ڣ������ߵĿ�û�����
//}//ϣ�����������߿���������ӿ� ���ص� ����MmPacketPrivate.h
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

