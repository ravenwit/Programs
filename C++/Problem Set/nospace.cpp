#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string nospace(string content){
    if(content.empty()) return "";
    for(size_t i = 0; i < content.size(); i++){
        if(content[i] == ' ') content.erase(i,1);
    }
    return content;
}

int main(){
    string input;
    getline(cin, input);
    cout << input << endl;
    cout << nospace(input) << endl;
    return 0;
}