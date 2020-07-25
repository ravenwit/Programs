
#include <iostream>
#include <vector>

using namespace std;

int MAX;
vector<long long int> fibo_list={1,1};

int __init();

int main(){
	MAX = 0;
	while(1) if(!__init()) return 0;
}

void fibonacci(int limit){
	int f_size = fibo_list.size();
	if(f_size < limit)
		for(int i = f_size - 1; i < limit; i++)
			fibo_list.push_back(fibo_list[i]+fibo_list[i-1]);
}

void __get_argv();
void show_out(char arg, int number){
	switch(arg){
		case 'n':
			for(int i = 0; i < number; i++)
				cout << "[" << i+1 << "]\t" << fibo_list[i] << endl;
			break;
		case 'i': 
			cout << "[" << number << "]\t" << fibo_list[number-1] << endl;
			break;
	}
	__get_argv();
	return;
}

void __get_argv(){
	char arg; int number;
	cout << "\n> "; cin >> arg;
	switch(arg){
		case 'n':
			cout << "\nn > ";
			break;
		case 'i':
			cout << "\ni > ";
			break;
		case 'q':
			return;
		default:
			cout << "Wrong argument... " << endl;
			__get_argv();
			break;
	}
	cin >> number;
	if(MAX < number) MAX = number;
	fibonacci(MAX);
	show_out(arg, number);
}

int __init(){
	cout << "\t Show fibonacci list    (n)  " << endl;
	cout << "\t Show fibonacci number  (i)  " << endl;
	cout << "\t Quit program           (q)  " << endl;
	__get_argv();
	return 0;
}