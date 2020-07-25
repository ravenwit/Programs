// Coursework1.cpp : This file contains the 'main' function. Program execution begins and ends there.
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


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

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

vector<string> split(const string& str, const string& delim)
{
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

void PrintDataStructure(HEADER_D* data_structure) {

	HEADER_D* p = data_structure;
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


ITEM1* GetItem(HEADER_D* data_structure, char* pItemID) {

	HEADER_D* p = data_structure;
	while (p) {
		HEADER_A* p_A = p->pHeaderA;
		while (p_A) {
			ITEM1* p_A_i = (ITEM1*)p_A->pItems;
			while (p_A_i) {
				if (strcmp(p_A_i->pID, pItemID) == 0) {
					return p_A_i;
				}
				p_A_i = p_A_i->pNext;
			}
			p_A = p_A->pNext;
		}
		p = p->pNext;
	}

	return (ITEM1*)nullptr;

}

HEADER_D* RemoveItem(HEADER_D* data_structure, char* pItemID) {

	ITEM1* ItemOfInterest = GetItem(data_structure, pItemID);

	if (!ItemOfInterest) {
		cout << "Removing failed. Item Does not exist." << endl;
		return (HEADER_D*)nullptr;
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

HEADER_D* InsertItem(HEADER_D* data_structure, char* pNewItemID = 0) {

	int success = 0;

	ITEM1* NewItem = (ITEM1*)GetItem(1, pNewItemID);
	if (!NewItem) return (HEADER_D*)nullptr;

	vector<string> s_ID = split(pNewItemID, " ");
	int cID1 = s_ID[0][0];
	int cID2 = s_ID[1][0];

	HEADER_D* p = data_structure;
	while (p) {

		HEADER_A* p_A = p->pHeaderA;
		while (p_A) {
			ITEM1* p_A_i = (ITEM1*)p_A->pItems;
			while (p_A_i) {
				if (strcmp(p_A_i->pID, NewItem->pID) == 0) {
					cout << "Insertion failed. ID already exists." << endl;
					return (HEADER_D*)nullptr;
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



void CheckInputError() {
	if (cin.fail())
	{
		cout << "Failure getting input \n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

int main()
{
	int ItemNumber = 20;  // Between 2 and 100
	cout << "Creating data structure with " << ItemNumber << " items...\n" << endl;
	HEADER_D* p = GetStruct4(1, ItemNumber);
	//ITEM1* pNewItem = (ITEM1*)GetItem(1);

	cout << "\nPrinting created data structure...\n" << endl;
	PrintDataStructure(p);
	cout << "\n\n" << endl;

	char ID[] = "Z Z";
	ITEM1* NewItem = (ITEM1*)GetItem(1, ID);


	cout << "Inserting item \"" << ID << "\" into data structure...\n" << endl;
	p = InsertItem(p, ID);

	cout << "Printing data structure with inserted (" << ID << ") id...\n" << endl;
	PrintDataStructure(p);
	cout << "\n\n" << endl;

	cout << "Removing item \"" << ID << "\" from data structure...\n" << endl;
	p = RemoveItem(p, ID);

	cout << "Printing data structure with removed (" << ID << ") id...\n" << endl;
	PrintDataStructure(p);
	cout << "\n\n" << endl;



	//while (1) {
	//	string str_tmp, str_path;
	//	CheckInputError();
	//	std::getline(std::cin >> std::ws, str_tmp);
	//	CheckInputError();
	//	char* ID = _strdup(str_tmp.c_str());
	//	////char ID[] = "Shakir Ahmed";
	//	//ITEM1* NewItem = (ITEM1*)GetItem(1, ID);

	//	cout << "Removing item \"" << ID << "\" from data structure...\n" << endl;
	//	p = RemoveItem1(p, ID);

	//	cout << "\nPrinting data structure with inserted (" << ID << ") id...\n" << endl;
	//	PrintDataStructure(p);
	//	cout << "\n\n" << endl;
	//	//break;
	//}

	_CrtDumpMemoryLeaks();
	return 0;
}

