#include <iostream>
using namespace std;

int addition(int num1, int num2)
{
    return  num1+num2;
}

int subtraction(int num1, int num2)
{
    return num1-num2;
}

int operation(int num1, int num2, int (*function)(int,int))
{
    return (*function)(num1,num2);
}

int main()
{
    int num1,num2;
    cout << "Number 1 : ";cin >> num1;cout << endl; cout << "Number 2 : ";cin >> num2; cout << endl;
    cout << "Operation result : " << operation(num1,num2,addition) << endl;
    cout << "Operation result : " << operation(num1,num2,subtraction) << endl;

    return 0;
}
