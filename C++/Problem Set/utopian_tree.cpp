#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int  main(){
    int t; int n[10];
    cin >> t;
    for(int n_i = 0; n_i < t; n_i++){
        cin >> n[n_i];
    }  
    for(int i = 0; i < t; i++){
        int h, exp;
        if(n[i] % 2 == 0) {exp = (n[i] / 2) + 1; h = (pow(2, exp) - 1);}
        else {exp = ((n[i] - 1) / 2) + 1; h = 2 * ((pow(2, exp)) - 1);}
        cout << h << endl;
    }
    return 0;
}