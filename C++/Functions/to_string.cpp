#include <iostream>
#include <string>

using namespace std;

template <class T_c>
void __swap(T_c &a, T_c &b){
    a ^= b; b ^= a; a ^= b;
}

template <class T_f>
void __reverse(T_f &in_a){
    for(int i = 0, j = in_a.size() - 1; i < in_a.size()/2; i++, j--)
        __swap(in_a[i], in_a[j]);
}

template <class T_v>
string __to_string(T_v val){
    string out;
    while(val>0)
        {out.push_back(char((val%10)+48)); val=(int)val/10;}
    __reverse(out);
    return out;
}

int main(){
    while(1){
        int val; cin >> val;
        cout << __to_string(val) << endl;
    }
    return 0;
}
