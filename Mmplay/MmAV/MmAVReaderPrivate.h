#pragma once

extern "C"
{
#include <libavformat/avformat.h>//���Ҳ����ļ� �Ĵ���cmakelists�Ѿ���û�����������ܳ��ڣ������ߵĿ�û�����
}//ϣ�����������߿���������ӿ� ���ص� ����MmPacketPrivate.h
class MmAVReaderPrivate
{
public:

	
	AVFormatContext* formatCtx = nullptr;


};

