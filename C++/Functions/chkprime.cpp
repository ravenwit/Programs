#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool __is_prime(const long long &number){
    if(number < 2) return false;
    else if(number < 4) return true;
    if(number%2==0 || number%3==0) return false;
    for(int i = 1; (6*i+1) <= (int)sqrt(number); i++)
        if(number%(6*i-1) == 0 || number%(6*i+1) == 0) return false;
    return true;
}

int main(){
    unsigned long long number;
    while(cin >> number)
        cout << string (__is_prime(number)?"YES":"NO") << endl;
    return 0;
}
