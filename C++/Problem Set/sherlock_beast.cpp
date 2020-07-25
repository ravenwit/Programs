#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int t; int n[t];
    cin >> t;
    for(int n_i = 0; n_i < t; n_i++){
        cin >> n[n_i];
        int a = 0, b = 0;
        for(a = 0; a < n[n_i]; a++){
            if((n[n_i] - 5*a) < 0) {a=0;break;}
            if((n[n_i] - 5*a) % 3 == 0){
                b = (n[n_i] - 5*a) / 3;
                break;
            }
        }
        if(a == 0 && b == 0 || n[n_i] == 1) {cout << -1 << endl;}
        else {string s1(5*a, '3'); string s2(3*b, '5'); 
            cout << s2 << s1 << endl;}
    }
    
    return 0;
}
