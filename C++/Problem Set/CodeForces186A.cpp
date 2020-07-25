#include <iostream>
#include <string>

using namespace std;

template <class T_c>
void __swap(T_c &a, T_c &b){
    a ^= b; b ^= a; a ^= b;
}
int __init(string &a, string &b);
int main(){
    string a,b;
    getline(cin,a);getline(cin,b);
    __init(a,b);
    return 0;
}

void _print_r(bool blu){
    cout << string(blu?"YES":"NO") << endl;
}

int __init(string &a, string &b){
    if(a.length() != b.length()){_print_r(false);return 0;}
    int pos[]={0,0}; bool bla = true;
    for(int i = 0; i < a.length(); i++){
        if(a[i] != b[i]){
            if(bla){pos[0] = i;bla=!bla;}
            else pos[1] = i;
        }
    }
    __swap(a[pos[0]],a[pos[1]]);
    _print_r(a==b);
    return 0;
}
