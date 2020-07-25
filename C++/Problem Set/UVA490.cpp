#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T_a>
T_a __get_max(T_a a, T_a b){
    return (a > b) ? a : b;
}
vector <string> __init(const vector<string> &lines, const int &min);
int main(){
    vector<string> lines; string line; int min_loop = 0;
    while(getline(cin,line)){
        lines.push_back(line);
        min_loop = __get_max(min_loop,(int)line.length());
    }
    vector<string> lines_out = __init(lines, min_loop);
    for(int i = 0; i < min_loop; i++) cout << lines_out[i] << endl;
    return 0;
}

vector <string> __init(const vector<string> &lines, const int &min){
    vector<string> lines_out(min,"");
    for(int i = lines.size() - 1; i >= 0; i--){
        for(int j = 0; j < lines[i].length(); j++) lines_out[j] += lines[i][j];
        for(int j = lines[i].length(); j < min; j++) lines_out[j] += " ";
    }
    return lines_out;
}
