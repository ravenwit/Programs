#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int size, sum = 0, target;
	cout << "How many numbers : "; cin >> size; cout << endl;
	int numbers[size];
	cout << "Enter the numbers : ";
	for(int i = 0; i < size; i++){
		cin >> numbers[i];
	} cout << endl; cout << "Target number : "; cin >> target; cout << endl;

	for(int i = 0; i < size; i++){
		sum = numbers[i];
	}
	for(int i = 0; i < size; i++){
		cout << numbers[i] << endl;
	}

	return 0;
}