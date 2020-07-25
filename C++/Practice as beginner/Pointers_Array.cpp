#include <iostream>

using namespace std;

int main()
{
    string b[]={"top","bottom","charm","strage","up","down"};

    int index=0;
    string *c=b;
    bool isFinish=false;

    while(!isFinish)
    {
    char userInput;

    cout << "\nEnter which value you want to see on screen : ";
    cin >> index;
    cout << *(c+(index-1)) << "\n" << endl;

    do
    {
    cout << "Do you want to try again? (y/n): ";
    cin >> userInput;

    if(tolower(userInput)=='y')
    {
        isFinish=false;
    }
    else if(tolower(userInput)=='n')
    {
        isFinish=true;
    }

    }while(tolower(userInput)=='y' && tolower(userInput)=='n');

     }

    return 0;
}
