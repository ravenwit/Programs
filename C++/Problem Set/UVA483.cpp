#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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
void __init(string &str);
int main(){
    string line;
    while(getline(cin,line)) __init(line);
    return 0;
}

void __init(string &str){
    stringstream s_line; s_line.str(str);
    vector<string> words; string word;
    while(getline(s_line,word,' '))
        words.push_back(word);
    for(int i = 0; i < words.size(); i++){
        __reverse(words[i]);
        if(i==words.size()-1) cout << words[i];
        else cout << words[i] << " ";
    }
    cout << endl;
}
