#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool is_exist(const string &filepath);
void loopchceck();
int main(){
    loopchceck();
    return 0;
}

bool is_exist(const string &filepath){
        ifstream file(filepath.c_str());
        return file.good();
}

void loopchceck()
{
    string strfilepath;
    cout << "Filepath : ";
    getline(cin,strfilepath);
    if(is_exist(strfilepath.c_str())){
        cout << "Exists" << endl;
    }else{
        cout << "Not Exists" << endl;
    }
    strfilepath.clear();
    loopchceck();
}



