#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <locale>
using namespace std;

string nospace(string content){
    if(content.empty()) return "";
    for(size_t i = 0; i < content.size(); i++){
        if(content[i] == ' ') content.erase(i,1);
    }
    return content;
}


int main(){
    string time, r, hour_str; size_t size; int hour;
    getline(cin, time);
    time = nospace(time);
    hour = std::stoi(time, &size);
    r = time.substr(time.length()-2);
    transform(r.begin(), r.end(), r.begin(), ::tolower);
    //if(r != "am" || r != "pm") return -1;
    if(r == "pm"){
        if(hour != 12) hour += 12;
    } if( r == "am" && hour == 12){
        hour = 0;
    }
    hour_str = to_string(hour);
    if(hour<10) hour_str.insert(0,"0");
    size = time.find(":");
    time.replace(0,size,hour_str);
    time.erase(time.length() - 2);
    cout << time << endl;
     return 0;
}