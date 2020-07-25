#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string output(bool in){
    if(in) return "YES";
    else return "NO";
}

int main(){
    int t; bool out[t];
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, k, count = 0;
        cin >> n >> k;
        vector <int> a(n); 
        for(int a_i = 0; a_i < n; a_i++){
            cin >> a[a_i];
            if(a[a_i] <= 0) count++;
        }
        if(count >= k) out[i] = false;
        else out[i] = true;
    }
    for(int i = 0; i < t; i++){
        cout << output(out[i]) << endl;
    }
    return 0;
}