#include <iostream>
#include <fstream>
#include <string>

using namespace std;
enum class WritingMode : int {New, Append};
enum class ReadingMode : int {Show, Store};
int main(){

}

void WriteToFile(char *filepath, string content, WritingMode Mode=WritingMode::Append){
        ofstream file;
        if (Mode==WritingMode::New){
                file.open(filepath, ios::trunc | ios::binary);
        }else{
                file.open(filepath, ios::app | ios::binary);
        }

        if (file.is_open()){
                file << content;
        }else{
                cout << "Could not open the file for writing."
        }
        file.close();
}

string ReadFromFile(char *filepath, ReadingMode Mode=ReadingMode::Show){
        ifstream file;
        file.open(filepath, ios::binary);
        if (Mode==ReadingMode::Store){
                string line_of_file;
                while(getline(file,line_of_file)){
                    cout << line_of_file << endl;
                }
                return "";
        }else{
                char *whole_file;

        }

}
