#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool is_prime(int number){
    if(number <= 0) number = -number;
    if(number == 1) return false;
    if(number <= 3) return true;
    if(number % 2 == 0) return false;
    if(number % 3 == 0) return false;
    for(int i = 1; (6*i + 1) < sqrt(number); i++){
        if(number % (6*i + 1) == 0) return false;
        if(number % (6*i - 1) == 0) return false;
    }
    return true;
}

int main(){
    int number; string ch;
    while(1){
        cin >> number;
        ch = is_prime(number) ? "Prime" : "Not Prime";
        cout << ch << endl;        
    } 
    
    return 0;
}