#pragma once

extern "C"
{
#include <libavformat/avformat.h>//���Ҳ����ļ� �Ĵ���cmakelists�Ѿ���û�����������ܳ��ڣ������ߵĿ�û�����
}//ϣ�����������߿���������ӿ� ���ص� ����MmPacketPrivate.h
class MmAVPacketPrivate
{
public:
	//MmAVPacketPrivate();
	//~MmAVPacketPrivate();//���ܼӹ������������
	AVPacket* pkt = nullptr;
	//AVFormatContext* formatCtx = nullptr;
private:

};

