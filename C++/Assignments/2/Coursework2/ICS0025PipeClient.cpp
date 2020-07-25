#include "ICS0025PipeClient.h"

ICS0025PipeClient::ICS0025PipeClient(Data& ds)
{
	this->ParentDataStructure = &ds;
	this->stop = 0;
	this->Connected = 0;
	this->MessageState = 0;
	//this->PipeHandle = CreateFile(
	//	TEXT("\\\\.\\pipe\\ICS0025"),   // pipe name 
	//	GENERIC_READ |  // read and write access 
	//	GENERIC_WRITE,
	//	0,              // no sharing 
	//	NULL,           // default security attributes
	//	OPEN_EXISTING,  // opens existing pipe 
	//	0,              // default attributes 
	//	NULL);          // no template file 
	//if (this->PipeHandle != INVALID_HANDLE_VALUE) this->Connected = 1;

	char full[_MAX_PATH]; string str_path;
	if (_fullpath(full, ".\\", _MAX_PATH) != NULL)
		str_path = string(full);
	str_path = str_path + string("ICS0025PipeClient.log");
	this->LogFile.open(str_path, ios::out | ios::app);

	Months["Jan"] = 1;
	Months["Feb"] = 2;
	Months["Mar"] = 3;
	Months["Apr"] = 4;
	Months["May"] = 5;
	Months["Jun"] = 6;
	Months["Jul"] = 7;
	Months["Aug"] = 8;
	Months["Sep"] = 9;
	Months["Oct"] = 10;
	Months["Nov"] = 11;
	Months["Dec"] = 12;

	this->PrintLog(log_flag::info, "Starting ICS0025PipeClient");
	//this->ConnectionStatus = thread(&ICS0025PipeClient::GetConnectionStatus, this);
	//this->ConnectionStatus.detach();
}


ICS0025PipeClient::~ICS0025PipeClient()
{
	try
	{
		this->LogFile.close();
		CloseHandle(this->PipeHandle);
	}
	catch (const std::exception & err)
	{
		this->PrintLog(log_flag::error, string(err.what()));
	}

}

bool ICS0025PipeClient::ConnectPipe()
{
	//if (this->Connected) return TRUE;
	this->PrintLog(log_flag::info, string("Connecting to " + SERVER_NAME));
	this->PipeHandle = CreateFile(
		TEXT("\\\\.\\pipe\\ICS0025"),   // pipe name 
		GENERIC_READ |  // read and write access 
		GENERIC_WRITE,
		0,              // no sharing 
		NULL,           // default security attributes
		OPEN_EXISTING,  // opens existing pipe 
		0,              // default attributes 
		NULL);          // no template file 
	if (this->PipeHandle == INVALID_HANDLE_VALUE) {
		this->PrintLog(log_flag::exception, string("Connection can not be established with " + SERVER_NAME));
		this->Connected = 0;
		return FALSE;
	}
	else {
		this->PrintLog(log_flag::info, string("Connection is established with " + SERVER_NAME));
		this->stop = 0;
		this->Connected = 1;
		this->MessageState = 0;
		this->CommandMessage = "ready";
		this->Listening = thread(&ICS0025PipeClient::ListeningHandler, this);
		this->Writing = thread(&ICS0025PipeClient::WritingHandler, this);
		//this->Listening.join();
		//this->Writing.join();
		return TRUE;
	}
}

bool ICS0025PipeClient::GetConnectionStatus()
{
	//this->PipeHandle = CreateFile(
	//	TEXT("\\\\.\\pipe\\ICS0025"),   // pipe name 
	//	GENERIC_READ |  // read and write access 
	//	GENERIC_WRITE,
	//	0,              // no sharing 
	//	NULL,           // default security attributes
	//	OPEN_EXISTING,  // opens existing pipe 
	//	0,              // default attributes 
	//	NULL);          // no template file 
	/*if (this->PipeHandle == INVALID_HANDLE_VALUE) this->Connected = 0;
	else this->Connected = 1;*/
	return this->Connected;
}


bool ICS0025PipeClient::StopPipe()
{
	if (!this->Connected) return TRUE;
	this->PrintLog(log_flag::info, "Stopping ICS0025PipeClient");
	this->CommandMessage = "stop";
	this->stop = 1;
	//this->Connected = FALSE;
	return TRUE;
}


void ICS0025PipeClient::PrintLog(log_flag flag, string s)
{
	string sflag;
	if (flag == log_flag::error) sflag = "error";
	else if (flag == log_flag::info) sflag = "info";
	else if (flag == log_flag::exception) sflag = "exception";

	thread::id ThreadId = this_thread::get_id();
	//s = s + "\n";
	lock_guard<mutex> keyboard_lock(temp_mutex);
	this->LogFile << "thread " << ThreadId << ":" << sflag << ":" << s << endl;
}

Item* ICS0025PipeClient::ParseItem(string s)
{
	size_t bracket_position1 = s.find("<");
	size_t bracket_position2 = s.find(">");
	string ItemName = s.substr(bracket_position1 + 1, bracket_position2 - bracket_position1 - 1);
	s.erase(bracket_position1 - 1, bracket_position2 - bracket_position1 + 2);
	vector<string> components = split(s, " ");
	char cGroup = components[0][0];
	int iSubgroup = stoi(components[1]);
	int dDay = stoi(components[2]);
	int dYear = stoi(components[4]);
	int dMonth = Months[components[3]];
	Date dDate(dDay, dMonth, dYear);
	try
	{
		Item* item = new Item(cGroup, iSubgroup, ItemName, dDate);
		return item;
	}
	catch (const std::exception & err)
	{
		this->PrintLog(log_flag::error, "Item is not created\n");
		this->PrintLog(log_flag::exception, string(err.what()));
		return nullptr;
	}
}

bool ICS0025PipeClient::WriteToServer()
{
	//if (this->PipeHandle == INVALID_HANDLE_VALUE) return 0;
	char szBUFFER[BUFFER_SIZE];
	DWORD bBytes;
	string s = this->CommandMessage;
	const char* message = s.c_str();
	strcpy_s(szBUFFER, sizeof(szBUFFER), message);
	bool Success = WriteFile(
		this->PipeHandle,		// handle to pipe
		szBUFFER,				// buffer to write from
		strlen(szBUFFER) + 1,	// number of bytes to write
		&bBytes,				// number of bytes written
		NULL					// not overlapped I/O
	);
	string log_message = string("Sent ") + to_string(int(bBytes)) + string(" bytes to server");
	if (Success) this->PrintLog(log_flag::info, log_message);
	else this->PrintLog(log_flag::error, "Message sending failed");
	if (bBytes != (strlen(szBUFFER) + 1))
		this->PrintLog(log_flag::exception, string(s + " message not properly sent to server"));
	else if (Success && bBytes == (strlen(szBUFFER) + 1))
		this->PrintLog(log_flag::info, "Sent " + s + string(" message to server"));
	this->MessageState = 1;
	return Success;
}

bool ICS0025PipeClient::ReadFromServer()
{

	char szBUFFER[BUFFER_SIZE];
	DWORD bBytes;
	bool Success = ReadFile(
		this->PipeHandle,
		szBUFFER,
		sizeof(szBUFFER),
		&bBytes,
		NULL
	);
	string log_message = string("Received ") + to_string(int(bBytes)) + string(" bytes from server");
	if (Success) this->PrintLog(log_flag::info, log_message);
	else this->PrintLog(log_flag::error, "Receiving is failed from server");
	if (bBytes == 0)
		this->PrintLog(log_flag::exception, string("No item received from server"));
	else if (Success && bBytes != 0) {
		//szBUFFER[strlen(szBUFFER)] = '\0';
		this->PrintLog(log_flag::info, string("Received text: " + string(szBUFFER)));
		Item* item = this->ParseItem(string(szBUFFER));
		if (item != nullptr) {
			Item* inserted = this->ParentDataStructure->InsertItem(
				item->GetGroup(),
				item->GetSubgroup(),
				item->GetName(),
				item->GetDate()
			);
			if (inserted == nullptr)
				this->PrintLog(log_flag::exception, "Failed to insert received item to data structure");
			else this->PrintLog(log_flag::info, "Received item is successfully inserted to data structure");
			this->MessageState = 0;
			delete item;
		}
	}
	return (Success && bBytes != 0);
}

void ICS0025PipeClient::ListeningHandler()
{
	this->PrintLog(log_flag::info, "Listening thread started");
	while (1) {
		if (stop) break;
		if (!this->Connected) break;
		if (this->MessageState == 1)
			if (!this->ReadFromServer()) break;
		//pause(500);
	}
	this->PrintLog(log_flag::info, "Listening thread stopped");
	this->PrintLog(log_flag::exception, "Connection stopped");
	this->Connected = 0;
}

void ICS0025PipeClient::WritingHandler()
{
	this->PrintLog(log_flag::info, "Writing thread started");
	while (1) {
		if (!this->Connected) break;
		if (this->MessageState == 0)
			if (!this->WriteToServer()) break;
		//pause(500);
	}
	this->PrintLog(log_flag::info, "Writing thread stopped");
	this->PrintLog(log_flag::exception, "Connection stopped");
	this->Connected = FALSE;
}



