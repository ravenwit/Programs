#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void ___init();

int main(int argc, char *argv[]) {
    ___init();
    return 0;
}

void __init(){

}

char __get_digit(int digit){
  if(digit < 10) return char(digit + 48);
  else return char(digit + 55);
}

string __hex_full(string hex, int ds = 0){
    string out; string zeros(ds,'0');
    out = "0x" + zeros + hex;
    return out;
}

string _base_converter(int number, int base){
    string out;
    while(number > 0){
        out.push_back(__get_digit(number%base));
        number /= base;
    }
    reverse(out.begin(), out.end());
    return out;
}

string _hex_encode(string &content){
    string out;
    for(int i = 0; i < content.length() - 1; i++){
        if(out != "") out += " ";
        out += __hex_full(_base_converter((int)content[i], 16));
    }
    return out;
}

void ___init(){
    string str, line;
    while(line!="`"){
        getline(cin, line); str+=line;
    }
    str[str.length() - 1] = '\0';
    cout << str << endl;
    cout << _hex_encode(str) << endl;
}
