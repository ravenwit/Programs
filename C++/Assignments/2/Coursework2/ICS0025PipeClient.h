#pragma once

#include "Item.h"
#include "Data.h"
#include "Main.h"

#define SERVER_NAME string("ICS0025PipeServer")
#define BUFFER_SIZE 512

class ICS0025PipeClient
{
private:
	Data* ParentDataStructure;
	ofstream LogFile;
	string CommandMessage;
	map<string, int> Months;
	//thread ConnectionStatus;
	enum class log_flag { error, info, exception };
	mutex temp_mutex;
	bool MessageState;
	bool Connected = 0;
	bool stop = 0;
	
public:
	HANDLE PipeHandle;
	thread Listening;
	thread Writing;
	ICS0025PipeClient(Data&);
	~ICS0025PipeClient();
	bool ConnectPipe();
	bool StopPipe();
	bool GetConnectionStatus();

private:
	void PrintLog(log_flag, string);
	Item* ParseItem(string);
	bool ReadFromServer();
	bool WriteToServer();
	void ListeningHandler();
	void WritingHandler();
};



