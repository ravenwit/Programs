#include <iostream>

using namespace std;


extern "C" void print(int number);

int main(){
	int a = 2, b = 3, c = 0;
	c = a + b;
	print(c);
	return 0;
}