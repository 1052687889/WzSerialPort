
#include <iostream>
#include "WzSerialPort.h"

using namespace std;

void sendDemo()
{
	WzSerialPort w;
	if (w.open("COM1", 9600, 0, 8, 1))
	{
		for (int i = 0;i < 10;i++)
		{
			w.send("helloworld", 10);
		}
		cout << "send demo finished...";
	}
	else
	{
		cout << "open serial port failed...";
	}
}

void receiveDemo()
{
	WzSerialPort w;
	if (w.open("COM1", 9600, 0, 8, 1))
	{
		char buf[1024];
		while (true)
		{
			memset(buf, 0,1024);
			w.receive(buf, 1024);
			cout << buf;
		}
	}
}

int main(int argumentCount, const char* argumentValues[]) 
{
	// ����COM1�Ѿ�������һ���������Ӻ���

	// ���� demo
	sendDemo();

	// ���� demo
	//receiveDemo();

	getchar();
	return 0;
}