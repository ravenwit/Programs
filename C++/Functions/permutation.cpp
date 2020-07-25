#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void Swap(string &str, int first, int second);
void permute(string &str, int start, int length);
string ValidString(const string &str){
    if(str == "")
        return "";
    string out = str;
    size_t foundspace = out.find_first_of(" ");
    if(foundspace != std::string::npos)
        out.erase(out.begin() + foundspace, out.end());
    int i = 0;
    while(out[i]){
        out[i] = toupper(out[i]);
        i++;
    }
    return out;
}
int main(){
    string str; ofstream file("permutation.txt", ios::app | ios::binary);
    cout << "Enter some string: "; getline(cin,str);
    str = ValidString(str);
    cout << "\n\t\t\t" << str << "\n" << endl; file << "\n\t\t\t" << str << "\n" << endl;
    permute(str, 0, str.length() - 1);
    cout << endl;
    file << "\n\t\t\t--------------\n" << endl;
    return 0;
}

void Swap(string &str, int first, int second){
    char tmp = str[first];
    str[first] = str[second];
    str[second] = tmp;
}

void permute(string &str, int start, int length){
    static int c = 0; ofstream file("permutation.txt", ios::app | ios::binary);
    if(start == length){
        cout << ++c << ":\t" << str << endl;
        file << c << ":\t" << str << endl;
    }else{
        for(int j = start; j <= length; j++){
            Swap(str, start, j);
            permute(str, start + 1, length);
            Swap(str, start, j);
        }
    }
}
