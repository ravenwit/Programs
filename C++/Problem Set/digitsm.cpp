#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n,s=0; 
    do{
        cin >> n;
        s=(n==0)?0:((n%9==0)?9:(n%9));
        cout << s << endl;
    } while(n!=0);
    return 0;
}