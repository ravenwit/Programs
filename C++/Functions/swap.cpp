#include <iostream>
#include <string>

using namespace std;

template <class T_a>
T_a GetMax(T_a a, T_a b){
    return (a > b) ? a : b;
}

template <class T_b>
T_b GetMin(T_b a, T_b b){
    return (a > b) ? b : a;
}

template <class T_c>
void __swap(T_c &a, T_c &b){
    a ^= b; b ^= a; a ^= b;
}

template <class T_d>
bool PlaceMax(T_d &a, T_d &b){
    if(a == GetMin(a,b)){__swap(a,b); return true;}
    return false;
}

template <class T_e>
bool PlaceMin(T_e &a, T_e &b){
    if(a == GetMax(a,b)){__swap(a,b); return true;}
    return false;
}

template <class T_f>
void __reverse(T_f &in_a){
    for(int i = 0, j = in_a.size() - 1; i < in_a.size()/2; i++, j--)
        __swap(in_a[i], in_a[j]);
}

int main(){
    char a, b; bool r = false; string in_a;
    cin >> a >> b; r = PlaceMin(a,b);
    for(int i = (int)a; i <= (int)b; i++)
        in_a.push_back(char(i));
    if(r) __reverse(in_a);
    cout << in_a << endl;
    return 0;
}
