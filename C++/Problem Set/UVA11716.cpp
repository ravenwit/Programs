#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool __is_square(int number){
    int root = sqrt(number);
    return (root*root==number);
}

int main(){
    int t_case; cin >> t_case; cin.ignore();
    for(int i = 0; i < t_case; i++){
        string line; getline(cin,line); int len = line.length();
        if(!__is_square(len)){cout << "INVALID" << endl;continue;}
        int shift = sqrt(len);
        for(int j = 0; j < len - 1; j++)
            cout << line[(shift*j)%(len-1)];
        cout << line[len-1] << endl;
    }
    return 0;
}
