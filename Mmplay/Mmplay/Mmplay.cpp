// Mmplay.cpp: 定义应用程序的入口点。
//

#include "Mmplay.h"
#include<thread>
#include<chrono>
#include "Mmthread/Mmthread.h"
#include<mutex>
using namespace std;
mutex smutex;

void threadFunction() {
	printf("id %p\n",this_thread::get_id);

}
class MyMMThread :public Mmthread
{
private:
	int a;

public:
	MyMMThread(int _a) :a(_a) {}

	virtual void run()
	{
		lock_guard<mutex> guard(smutex);
		printf("id %p\n", this_thread::get_id); 
		printf("mmplay %d\n",a);
	}

};
int sdamain()
{	
	
	MyMMThread s(3);
	s.Start();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "Hello CMake." << endl;
	return 0;
}
#include"MmAV/MmAV.h"

int main()
{
	MmAVReader reader;
	int ret = reader.Open("E://ffmpegcode//qiao//3 chapter3//Mmplay//Mmplay//girls.mp4");
	if (ret)
	{
		printf("open error\n");
		return -1;
	}
	while (1) {
		MmAVPacket pkt;
		ret = reader.Read(&pkt);
		if (ret)
		{
			break;
		}
		printf("success\n");

	}
	reader.Close();
}