// Coursework2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file



#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "DateTime.h"
#include "Items.h"
#include "Headers.h"
#include "ICS0017DataSource.h"

using namespace std;

void CheckInputError();

inline bool file_exists(const char* path) {
	ifstream f(path);
	return f.good();
}


inline char* get_string(int i) {
	string str_tmp, str_path;
	std::getline(std::cin >> std::ws, str_tmp);
	CheckInputError();
	if (i == 2) {
		char full[_MAX_PATH];
		if (_fullpath(full, ".\\", _MAX_PATH) != NULL)
			str_path = string(full);
		str_path = str_path + str_tmp;
		//size_t str_len = str_path.length();
		char _out[2000];
		strcpy_s(_out, (size_t)str_path.length(), str_path.c_str());
		return _out;
	}
	char _out[500];
	strcpy_s(_out, 500, str_tmp.c_str());
	return _out;
}


vector<string> split(const string& str, const string& delim) {
	vector<string> tokens;
	size_t prev = 0, pos = 0;
	do
	{
		pos = str.find(delim, prev);
		if (pos == string::npos) pos = str.length();
		string token = str.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
	return tokens;
}

void CheckInputError() {
	if (cin.fail())
	{
		cout << "Failure getting input \n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}


class DataStructure {

	HEADER_D* DS;

private:
	HEADER_D* InsertItem(HEADER_D* data_structure, ITEM1* item, int act) {

		int success = 0;

		ITEM1* NewItem = item;
		if (!NewItem) return data_structure;

		vector<string> s_ID = split(item->pID, " ");
		int cID1 = s_ID[0][0];
		int cID2 = s_ID[1][0];

		HEADER_D* p = data_structure;

		while (p) {
			HEADER_A* p_A = p->pHeaderA;
			if (act == 1) {
				p->cBegin = (char)cID1;
				p_A->cBegin = (int)cID2;
				p_A->pItems = item;
				return p;
			}
			while (p_A) {
				ITEM1* p_A_i = (ITEM1*)p_A->pItems;
				while (p_A_i) {
					if (strcmp(p_A_i->pID, NewItem->pID) == 0) {
						this->err = 1;
						cout << "Insertion failed. ID already exists." << endl;
						return data_structure;
					}
					p_A_i = p_A_i->pNext;
				}
				p_A = p_A->pNext;
			}
			p = p->pNext;
		}

		HEADER_D* headerD_head = data_structure;
		HEADER_D* headerD_pre = data_structure;
		HEADER_D* headerD_cur = data_structure;

		while (headerD_cur) {
			HEADER_A* headerA_head = headerD_cur->pHeaderA;
			HEADER_A* headerA_cur = headerD_cur->pHeaderA;
			HEADER_A* headerA_pre = headerD_cur->pHeaderA;


			int c_header = headerD_cur->cBegin;
			if (cID1 == c_header) {
				while (headerA_cur) {
					ITEM1* item_cur = (ITEM1*)headerA_cur->pItems;
					ITEM1* item_pre = (ITEM1*)headerA_cur->pItems;

					vector<string> item_ID = split(item_cur->pID, " ");
					int citem_ID = item_ID[1][0];

					int cBegin_A = headerA_cur->cBegin;

					if (cID2 == cBegin_A) {
						while (item_cur) {
							item_pre = item_cur;
							item_cur = item_cur->pNext;
						}
						item_pre->pNext = NewItem;

						success = 1;
						return headerD_head;////////////////////////
					}
					else if (cID2 > cBegin_A) {
						if (headerA_cur->pNext) {
							headerA_pre = headerA_cur;
							headerA_cur = headerA_cur->pNext;
							continue;
						}
						else {
							HEADER_A** newHeader_A = GetStruct3(1, 1);
							int i = 0;
							while (!newHeader_A[i]) i++;
							newHeader_A[i]->pItems = NewItem;
							newHeader_A[i]->cBegin = (char)cID2;

							headerA_cur->pNext = newHeader_A[i];

							success = 1;
							return headerD_head; //////////////////////
						}

					}
					else if (cID2 < cBegin_A) {
						HEADER_A** newHeader_A = GetStruct3(1, 1);
						int i = 0;
						while (!newHeader_A[i]) i++;
						newHeader_A[i]->pItems = NewItem;
						newHeader_A[i]->cBegin = (char)cID2;

						newHeader_A[i]->pNext = headerA_cur;

						if (headerA_cur == headerA_head)
							headerD_cur->pHeaderA = newHeader_A[i];

						else
							headerA_pre->pNext = newHeader_A[i];

						success = 1;
						return headerD_head;
					}

					headerA_pre = headerA_cur;
					headerA_cur = headerA_cur->pNext;
				}
			}
			else if (cID1 > c_header) {
				if (headerD_cur->pNext) {
					headerD_pre = headerD_cur;
					headerD_cur = headerD_cur->pNext;
					continue;
				}
				else {
					HEADER_D* newHeaderD = GetStruct4(1, 1);
					newHeaderD->cBegin = (char)cID1;
					HEADER_A* newHeaderD_A = newHeaderD->pHeaderA;
					newHeaderD_A->cBegin = (char)cID2;
					newHeaderD_A->pItems = NewItem;

					headerD_cur->pNext = newHeaderD;

					success = 1;
					return headerD_head;
				}
			}
			else if (cID1 < c_header) {
				HEADER_D* newHeaderD = GetStruct4(1, 1);
				newHeaderD->cBegin = (char)cID1;
				HEADER_A* newHeaderD_A = newHeaderD->pHeaderA;
				newHeaderD_A->cBegin = (char)cID2;
				newHeaderD_A->pItems = NewItem;

				newHeaderD->pNext = headerD_cur;

				if (headerD_cur == headerD_head) {
					success = 1;
					return newHeaderD;
				}
				else {
					headerD_pre->pNext = newHeaderD;
					success = 1;
					return headerD_head;
				}
			}

			headerD_pre = headerD_cur;
			headerD_cur = headerD_cur->pNext;
		}
		//return (HEADER_D*)nullptr;
	}



	HEADER_D* RemoveItem(HEADER_D* data_structure, char* pItemID) {

		ITEM1* ItemOfInterest = GetItem(pItemID);

		if (!ItemOfInterest) {
			this->err = 1;
			cout << "Removing failed. Item Does not exist." << endl;
			return data_structure;
		}

		HEADER_D* headerD_head = data_structure;
		HEADER_D* headerD_cur = data_structure;
		HEADER_D* headerD_pre = data_structure;

		while (headerD_cur) {
			HEADER_A* headerA_head = headerD_cur->pHeaderA;
			HEADER_A* headerA_cur = headerD_cur->pHeaderA;
			HEADER_A* headerA_pre = headerD_cur->pHeaderA;

			while (headerA_cur) {
				ITEM1* item_head = (ITEM1*)headerA_cur->pItems;
				ITEM1* item_cur = (ITEM1*)headerA_cur->pItems;
				ITEM1* item_pre = (ITEM1*)headerA_cur->pItems;

				while (item_cur) {
					if (item_cur == ItemOfInterest) {
						if (item_cur == item_head) {
							if (item_cur->pNext) {
								item_cur = item_cur->pNext;
								return headerD_head;
							}
							else {
								if (headerA_cur == headerA_head) {
									if (headerA_cur->pNext) {
										headerD_cur->pHeaderA = headerA_cur->pNext;
										return headerD_head;
									}
									else {
										if (headerD_cur == headerD_head) {
											return headerD_head->pNext;
										}
										else {
											headerD_pre->pNext = headerD_cur->pNext;
											return headerD_head;
										}
									}
								}
								else {
									if (headerA_cur->pNext) {
										headerA_pre->pNext = headerA_cur->pNext;
										return headerD_head;
									}
									else {
										headerA_pre->pNext = nullptr;
										return headerD_head;
									}
								}
							}
						}
						else {
							if (item_cur->pNext) {
								item_pre->pNext = item_cur->pNext;
								return headerD_head;
							}
							else {
								item_pre->pNext = nullptr;
								return headerD_head;
							}
						}
					}
					item_pre = item_cur;
					item_cur = item_cur->pNext;
				}
				headerA_pre = headerA_cur;
				headerA_cur = headerA_cur->pNext;
			}
			headerD_pre = headerD_cur;
			headerD_cur = headerD_cur->pNext;
		}
	}



public:

	DataStructure() {}
	DataStructure(const DataStructure& Original) {
		this->DS = Original.DS;
	}

	int err = 0;

	DataStructure(char* pFilename) {
		ifstream binary_file(pFilename, ios::binary | ios::in);
		string line, str;

		DataStructure* newDS = new DataStructure();
		newDS->DS = ::GetStruct4(1, 1);

		try
		{
			if (!binary_file.good()) {
				this->err = 1;
				throw exception("File does not exist");
			}
			if (binary_file.is_open()) {
				int i = 0;
				while (getline(binary_file, line)) {
					if (line == "") {
						throw exception("Empty file"); this->err = 1;
					}
					str.assign(line, 1, int(line.length() - 2));
					vector<string> s_str = split(str, ",");
					std::string::size_type sz;
					unsigned long int code = stoul(s_str[1], &sz);
					char ID[1000]; strcpy_s(ID, 1000, s_str[0].c_str());

					ITEM1* item = (ITEM1*)::GetItem(1, ID);
					if (!item) {
						throw exception("Failure creating item"); this->err = 1;
					}
					item->Code = code;
					char iTime[20]; strcpy_s(iTime, 20, s_str[2].c_str());
					item->pTime = iTime;
					if (i == 0) {
						newDS->InsertItem(newDS->DS, item, 1);
						i++;
					}
					else newDS->InsertItem(newDS->DS, item, 0);
				}

			}
			else {
				throw exception("Error reading file"); this->err = 1;
			}

			this->DS = newDS->DS;
			this->err = 0;
		}
		catch (const std::exception & err)
		{
			this->err = 1;
			cout << "File handling error" << endl;
			cout << err.what() << endl;
		}

		binary_file.close();
	}

	~DataStructure() {
		delete this->DS;
	}

	bool is_empty() {
		DataStructure tmpds;
		return (tmpds == *this);
	}

	//reinterpret_cast<char*>
	void Write(char* pFilename) {
		if (file_exists(pFilename)) {
			throw exception("File already exists.");
		}

		ofstream binary_file(pFilename, ios::out | ios::binary | ios::app);
		try
		{
			binary_file << *this;
		}
		catch (const std::exception & err)
		{
			cout << "File handling error" << endl;
			cout << err.what() << endl;
			this->err = 1;
		}

		binary_file.close();
	}


	int GetItemsNumber() {
		HEADER_D* p = this->DS;
		int i = 0;
		while (p) {
			HEADER_A* p_A = p->pHeaderA;
			while (p_A) {
				ITEM1* p_A_i = (ITEM1*)p_A->pItems;
				while (p_A_i) {
					i++;
					p_A_i = p_A_i->pNext;
				}
				p_A = p_A->pNext;
			}
			p = p->pNext;
		}

		return i;
	}

	ITEM1* GetItem(char* pID) {

		HEADER_D* p = this->DS;
		while (p) {
			HEADER_A* p_A = p->pHeaderA;
			while (p_A) {
				ITEM1* p_A_i = (ITEM1*)p_A->pItems;
				while (p_A_i) {
					if (strcmp(p_A_i->pID, pID) == 0) {
						return p_A_i;
					}
					p_A_i = p_A_i->pNext;
				}
				p_A = p_A->pNext;
			}
			p = p->pNext;
		}

		return 0;
	}

	ITEM1* GetItem(long int code) {

		HEADER_D* p = this->DS;
		while (p) {
			HEADER_A* p_A = p->pHeaderA;
			while (p_A) {
				ITEM1* p_A_i = (ITEM1*)p_A->pItems;
				while (p_A_i) {
					if (p_A_i->Code == code) {
						return p_A_i;
					}
					p_A_i = p_A_i->pNext;
				}
				p_A = p_A->pNext;
			}
			p = p->pNext;
		}

		return 0;
	}


	ITEM1* GetItemByTimestamp(char* time) {

		HEADER_D* p = this->DS;
		while (p) {
			HEADER_A* p_A = p->pHeaderA;
			while (p_A) {
				ITEM1* p_A_i = (ITEM1*)p_A->pItems;
				while (p_A_i) {
					if (strcmp(p_A_i->pTime, time) == 0) {
						return p_A_i;
					}
					p_A_i = p_A_i->pNext;
				}
				p_A = p_A->pNext;
			}
			p = p->pNext;
		}

		return 0;
	}

	void PrintDataStructure() {

		HEADER_D* p = this->DS;
		int i = 1;
		while (p) {
			HEADER_A* p_A = p->pHeaderA;
			while (p_A) {
				ITEM1* p_A_i = (ITEM1*)p_A->pItems;
				while (p_A_i) {
					cout << i << ") " << p_A_i->pID << " " << p_A_i->Code << " " << p_A_i->pTime << endl;
					i++;
					p_A_i = p_A_i->pNext;
				}
				p_A = p_A->pNext;
			}
			p = p->pNext;
		}
	}

	void MakeDataStructure(int ItemNumber) {
		this->DS = GetStruct4(1, ItemNumber);
	}

	void operator+=(ITEM1* ITEM) {
		if (this->is_empty()) {
			throw exception("Data structure is empty"); this->err = 0;
		}
		this->DS = this->InsertItem(this->DS, ITEM, 0);
	}

	void operator-=(char* pID) {
		if (this->is_empty()) {
			throw exception("Data structure is empty"); this->err = 0;
		}
		this->DS = this->RemoveItem(this->DS, pID);
	}

	DataStructure& operator=(const DataStructure& Right) {
		this->DS = {};
		this->DS = Right.DS;
		return *this;
	}

	int operator==(DataStructure& Other) {
		return (this->DS == Other.DS);
	}

	friend std::ostream& operator<<(std::ostream& ostr, const DataStructure& str);
	friend std::ofstream& operator<<(std::ofstream& ofsrt, const DataStructure& str);
};

std::ostream& operator<<(std::ostream& ostr, const DataStructure& str) {
	HEADER_D* p = str.DS;
	int i = 1;
	while (p) {
		HEADER_A* p_A = p->pHeaderA;
		while (p_A) {
			ITEM1* p_A_i = (ITEM1*)p_A->pItems;
			while (p_A_i) {
				ostr << i << ") " << p_A_i->pID << " " << p_A_i->Code << " " << p_A_i->pTime << endl;
				i++;
				p_A_i = p_A_i->pNext;
			}
			p_A = p_A->pNext;
		}
		p = p->pNext;
	}
	return ostr;
}

std::ofstream& operator<<(std::ofstream& ofstr, const DataStructure& str) {
	HEADER_D* p = str.DS;
	int i = 1;
	while (p) {
		HEADER_A* p_A = p->pHeaderA;
		while (p_A) {
			ITEM1* p_A_i = (ITEM1*)p_A->pItems;
			while (p_A_i) {
				ofstr << "[" << p_A_i->pID << "," << p_A_i->Code << "," << p_A_i->pTime << "]" << endl;
				i++;
				p_A_i = p_A_i->pNext;
			}
			p_A = p_A->pNext;
		}
		p = p->pNext;
	}
	return ofstr;
}


int main() {

	DataStructure* ds = new DataStructure;
	int command = 0, sec_command = 0;

	while (1) {
		ds->err = 0;
		cout << "\n(1) Create Data Structure" << endl;
		cout << "(2) Print Data Structure" << endl;
		cout << "(3) Count Item in Data Structure" << endl;
		cout << "(4) Insert an Item" << endl;
		cout << "(5) Remove an Item" << endl;
		cout << "(6) Search in Data Structure" << endl;
		cout << "(7) Save Data Structure" << endl;
		cout << "(8) Load Data Structure" << endl;
		cout << "(9) Additional Test" << endl;
		cout << "(10) Exit" << endl;

		command = 0;
		cout << "Enter task number: ";
		cin >> command;
		CheckInputError();

		if (command == 1) {
			int ItemNumber;
			cout << "Enter item number: ";
			cin >> ItemNumber;
			CheckInputError();

			ds->MakeDataStructure(ItemNumber);
			cout << "Data structure is created with " << ItemNumber << " items" << endl;
		}
		else if (command == 3) {
			if (!ds->is_empty()) {
				cout << "There are " << ds->GetItemsNumber() << " item(s) in the data structure" << endl;
			}
			else {
				cout << "Data structure is empty" << endl;
			}
		}
		else if (command == 2) {
			if (ds->is_empty()) {
				cout << "Data structure is empty" << endl;
				continue;
			}
			cout << "Printing existing data structure\n" << endl;
			cout << *ds << endl;
		}
		else if (command == 6) {
			cout << "(1) Search by ID" << endl;
			cout << "(2) Search by code" << endl;
			cout << "(3) Search by time" << endl;
			sec_command = 0;
			cout << "Enter task number: ";
			cin >> sec_command;
			CheckInputError();

			if (sec_command == 1) {

				cout << "Enter ID: ";
				char* ID = get_string(1);

				ITEM1* item = ds->GetItem(ID);

				if (item) {
					cout << "\nFound item: ";
					cout << item->pID << " " << item->Code << " " << item->pTime << endl;
					//delete[] ID;
				}
				else {
					cout << "Item not found" << endl;
				}

			}
			else if (sec_command == 2) {
				unsigned long int code = 0;
				cout << "Enter code: ";
				cin >> code;
				CheckInputError();

				ITEM1* item = ds->GetItem(code);

				if (item) {
					cout << "\nFound item: ";
					cout << item->pID << " " << item->Code << " " << item->pTime << endl;
				}
				else {
					cout << "Item not found" << endl;
				}
			}
			else if (sec_command == 3) {

				cout << "Enter time: ";
				char* time = get_string(1);

				ITEM1* item = ds->GetItemByTimestamp(time);

				if (item) {
					cout << "\nFound item: ";
					cout << item->pID << " " << item->Code << " " << item->pTime << endl;
				}
				else {
					cout << "Item not found" << endl;
				}
				//delete[] time;
			}
			else {
				cout << "Try a valid command" << endl;
			}
		}
		else if (command == 4) {

			cout << "Enter ID: ";
			char* ID = get_string(1);
			ITEM1* item = (ITEM1*)GetItem(1, ID);

			if (!item) {
				cout << "Failure creating item with ID " << ID << endl;
				continue;
			}
			try
			{
				*ds += item;
				//delete[] ID;
				if (ds->err == 0) {
					cout << "Successfully inserted item with ID " << ID << endl;
				}
				else {
					cout << "Failure inserting item with ID " << ID << endl;
				}
			}
			catch (const std::exception & err)
			{
				cout << err.what() << endl;
			}
		}
		else if (command == 5) {

			cout << "Enter ID: ";
			char* ID = get_string(1);

			try
			{
				*ds -= ID;
				//delete[] ID;
				if (ds->err == 0) {
					cout << "Successfully removed item with ID " << ID << endl;
				}
				else {
					throw exception("Failure removing item with ID ");
				}
			}
			catch (const std::exception & err)
			{
				cout << err.what() << endl;
			}
		}
		else if (command == 7) {
			cout << "File will be saved in the current directory" << endl;
			cout << "Enter filename: ";
			char* path = get_string(2);

			if (ds->is_empty()) {
				cout << "Data structure is empty. Nothing to save" << endl;
				continue;
			}
			try
			{
				ds->Write(path);
				ifstream pfile(path, ios::binary | ios::in);
				string line, str;
				if (pfile.is_open()) {
					while (getline(pfile, line)) {
						str.assign(line, 1, int(line.length() - 2));
						vector<string> s_str = split(str, ",");
						std::string::size_type sz;
						unsigned long int l_str = stoul(s_str[1], &sz);
					}
				}
				pfile.close();

				if (ds->err == 0) {
					cout << "Successfully saved data structure to " << path << endl;
				}
				else {
					throw exception("Failure writing file");
				}
			}
			catch (const std::exception & err)
			{
				cout << err.what() << endl;
			}

		}
		else if (command == 8) {
			cout << "Please first put the file in the current directory" << endl;
			cout << "Enter filename: ";
			char* path = get_string(2);
			try
			{
				DataStructure* s_ds = new DataStructure(path);
				ds = s_ds;

				if (ds->err == 0) {
					cout << "Data successfully loaded from " << path << endl;
				}
				else {
					cout << "Failure loading data from file" << endl;
				}
			}
			catch (const std::exception & err)
			{
				cout << err.what() << endl;
			}

		}
		else if (command == 9) {
			DataStructure* pds = new DataStructure();
			pds = ds;
			cout << (*pds == *ds) << endl;
			DataStructure* sds = new DataStructure(*pds);
			cout << (*sds == *ds) << endl;
		}
		else if (command == 10) {
			ds->~DataStructure();
			return 0;
		}
		else {
			cout << "Try a valid command" << endl;
		}
	}
	//**************************************************************************************/

	return 0;
}



