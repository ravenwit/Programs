#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T_a>
T_a GetMax(T_a &a, T_a &b){
    return (a > b) ? a : b;
}

template <class T_b>
T_b GetMin(T_b &a, T_b &b){
    return (a > b) ? b : a;
}

template <class T_c>
void __swap(T_c &a, T_c &b){
    a ^= b; b ^= a; a ^= b;
}

template <class T_d>
bool PlaceMax(T_d &a, T_d &b){
    if(a == GetMin(a,b)){__swap(a,b); return true;}
    return false;
}

void c2scomplmnt(vector<bool> &num_b, unsigned int &len){
	bool start = 0;
	for(int i = 0; i < len; i++){
		if(start) num_b[i]=!num_b[i];
		if(num_b[i]) start=1;
	}
}

string add_b(string &num1, string &num2, unsigned int &len1, unsigned int &len2){
	unsigned int ij=GetMax(len1,len2);
	vector<bool> um1(ij, 0), um2(ij, 0), res;
	for(int i = len1 - 1, j = 0; i >= 0; i--, j++)
		um1[j]=(bool)(int(num1[i])%48);
	for(int i = 0; i < ij; i++)
		cout << um1[i];
	cout << endl;
	for(int i = len2 - 1, j = 0; i >= 0; i--, j++)
		um2[j]=(bool)(int(num2[i])%48);
	for(int i = 0; i < ij; i++)
		cout << um2[i];
	cout << endl;
	c2scomplmnt(um2, ij);
	for(int i = 0; i < ij; i++)
		cout << um2[i];
	cout << endl;
	
	for(int i = 0; i < ij; i++){
		static bool cc = 0;
			res.push_back((um1[i] ^ um2[i])^cc);
			cc = (um1[i]&um2[i])|((um1[i] ^ um2[i])&cc);
	}
	string out;
	for(int i = res.size() - 1; i >= 0; i--)
		//out.push_back(res[i]);
		cout << res[i];
	return out;
}

int main(){
	string um1, um2;
	cin >> um1 >> um2;
	//um1="1011"; um2="101110";
	unsigned int l1 = um1.size(), l2 = um2.size();

	cout << add_b(um1, um2, l1, l2) << endl;
	return 0;
}
