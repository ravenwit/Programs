#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, a_i, a_j;
    int sum1 = 0, sum2 = 0;
    cin >> n;
    vector< vector<int> > a(n, vector<int>(n));
    
    for(a_i = 0, a_i < n; a_i++){
        for(a_j = 0; a_j < n; a_j++){
            cin << a[a_i][a_j];
            if(a_i == a_j){
                sum1 += a[a_i][a_j];
            }
        }
    }
    
    a_i = 0; a_j = n-1;
    while(a_i < n){
        sum2 += a[a_i][a_j];
        a_i++; a_j--;
    }
    cout << abs(sum1 - sum2);
    return 0;
}