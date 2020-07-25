#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum class WritingMode : int {New = 1, Append};
enum class ReadingMode : int {Show = 1, Store};

bool WriteToFile (const string &filepath, const string &filecontent, WritingMode Mode);
bool ReadFromFile (const string &filepath, string &filecontent, ReadingMode Mode);
bool is_exist(const string &filepath);
char GetArg(){
    char arg = cin.get(); cin.ignore(256, '\n'); cout << endl;
    arg = tolower(arg);
    return arg;
}

int main(){
    string str_filepath = ""; string str_filecontent = ""; char ch_arg; bool successful;
    cout << "\nFile operations -> \n\t\t(N)ew file\n\t\t(W)rite into file\n\t\t(R)ead file\n\t\t(S)tore file in memory and read it." << endl;
    cout << "\nWhat do you want to do? : "; ch_arg = GetArg();
    if(ch_arg != 'n' && ch_arg != 'w' && ch_arg != 'r' && ch_arg != 's'){
    cout << "Wrong argument! Quiting program." << endl;
    return 1;
    }
    cout << "File path : ";
    getline(cin, str_filepath);
    switch(ch_arg){
        case 'n':
            {
                if (is_exist(str_filepath)){
                    cout << "\nFile already exists. Do you want to discard all previous changes? (Yes/No): "; char ch_arg2 = GetArg();
                    if (ch_arg2 == 'y')
                        ch_arg = 'n';
                    else
                        ch_arg = 'w';
                }
            }
        case 'w':
                cout << "\nWrite something. \" ` \" (without quote) is the end character, anything after \" ` \" will be discarded : \n" << endl;
                getline(cin, str_filecontent, '`'); cout << endl;
                if(ch_arg == 'n'){
                    successful = WriteToFile (str_filepath, str_filecontent, WritingMode::New);
                }else{
                    successful = WriteToFile (str_filepath, str_filecontent, WritingMode::Append);
                }
                break;
        case 'r':
        case 's':
                if(ch_arg == 's'){
                    successful = ReadFromFile (str_filepath, str_filecontent, ReadingMode::Store);
                    if (str_filecontent != "")
                        cout << str_filecontent << "\n\n\t\t\t------End Of File-------\t\t\t\n" << endl;
                    else
                        cout << "File is empty. " << endl;
                }else{
                    successful = ReadFromFile (str_filepath, str_filecontent, ReadingMode::Show);
                }
                break;
        default:
                successful = false;
    }
    if(successful == true)
        cout << "\n\tOperation was successful. Quiting program. " << endl;
    else
        cout << "\n\tOperation was not successful. Quiting program. " << endl;
    return (int) !successful;
}

bool is_exist (const string &filepath){
        ifstream file(filepath.c_str());
        return file.good();
}

bool WriteToFile (const string &filepath, const string &filecontent, WritingMode Mode){
        ofstream file;
        if (Mode == WritingMode::New){
                file.open (filepath.c_str(), ios::trunc | ios::binary);
        }else{
                file.open (filepath.c_str(), ios::app | ios::binary);
        }

        if (file.is_open()){
                file << filecontent;
            file.close();
            return true;
        }else{
                cout << "\nSorry! Could not open the file for writing." << endl;
        }
        return false;
}

string GetFileName (const string &filepath){
        size_t t = filepath.find_last_of("/\\");
        string str_filename = filepath.substr(t + 1);
        return str_filename;
}

bool ReadFromFile (const string &filepath, string &filecontent, ReadingMode Mode){
        ifstream file(filepath.c_str(), ios::binary);

        if (file){
            switch (Mode){
                case ReadingMode::Store:
                    {
                        streampos file_size; char *mem_filecontent;
                        file.seekg(0, file.end);
                        file_size = file.tellg();
                        file.seekg(0, file.beg);
                        cout << "\n\n\t\t\t-------" << GetFileName(filepath) << "-------\n" << endl;
                        mem_filecontent = new char[file_size];
                        file.read(mem_filecontent, file_size);
                        file.close();
                        filecontent = string(mem_filecontent);
                        delete[] mem_filecontent;
                        break;
                    }
                case ReadingMode::Show:
                    {
                        cout << "\n\n\t\t\t-------" << GetFileName(filepath) << "-------\n" << endl;
                        string line_of_file;
                        while(getline(file, line_of_file)){
                            cout << line_of_file << endl;
                        }
                        cout << "\n\t\t\t-------End Of File-------\t\t\t\n" << endl;
                        break;
                    }
                default:
                    return false;
            }
            return true;
        }else{
            cout << "\nSorry! Could not open the file to read. " << endl;
        }
    return false;
}
