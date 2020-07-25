#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    fstream file_out;
    string filepath;
    getline(cin,filepath);
    const char *cstfilepath=filepath.c_str();
    file_out.open(cstfilepath,ios::in | ios::out | ios::app);
    string str;
    str="This is a file";
    file_out << str << endl;

    char * cnet;
    streampos sizet=file_out.tellg();
    cnet=new char[sizet];
    file_out.seekg(0,ios::beg);
    file_out.read(cnet,sizet);
    cout << cnet;
    delete[] cnet;
    file_out.close();

   return 0;
}


