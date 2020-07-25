#include <iostream>
#include <string>

using namespace std;
string decode(string &str);
int main(){
    string line;
    while(getline(cin,line)) cout << decode(line) << endl;
    return 0;
}

string decode(string &str){
    for(int i = 0; i < str.length(); i++)
        str[i] = char((int)str[i]-7);
    return str;
}
