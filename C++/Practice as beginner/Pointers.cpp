#include <iostream>
using namespace std;

int main()
{
    int a=4;
    int b=7;

    cout << "The address of variable a : " << &a << endl;
    cout << "The address of variable b : " << &b << endl;
    cout << "\n" << endl;
    int *a_add, *b_add;
    a_add=&a;b_add=&b;

    cout << "The address of variable a : " << a_add << endl;
    cout << "The address of variable b : " << b_add << endl;
    cout << "\n" << endl;

    cout << "The value of variable a : " << *a_add << endl;
    cout << "The value of variable b : " << *b_add << endl;
    cout << "\n" << endl;


    int *a1_add=&a;
    int *b1_add=&b;

    cout << "The address of variable a : " << a1_add << endl;
    cout << "The address of variable b : " << b1_add << endl;
    cout << "\n" << endl;

    cout << "The value of variable a : " << *a1_add << endl;
    cout << "The value of variable b : " << *b1_add << endl;
    cout << "\n" << endl;
    //cin.get();
    return 0;
}
