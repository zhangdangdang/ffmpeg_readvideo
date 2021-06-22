#include <thread>
#include <iostream>
#include "Mmthread.h"

int Mmthread:: Start()
{
	std::thread t(&Mmthread::run, this);
	t.detach();
	return 0;
}