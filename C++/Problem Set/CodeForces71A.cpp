#include <iostream>
#include <string>

using namespace std;
void __init(const int &t);
int main(){
    int t_case=0; cin >> t_case;
    __init(t_case);
    return 0;
}

void __init(const int &t){
    int i = 0;
    while(i < t){
        string word; cin >> word;
        if(word.length() > 10){
            string tmp;
            tmp.push_back(word[0]);
            tmp += to_string(word.length()-2);
            tmp.push_back(word[word.length()-1]);
            word = tmp;
        }
        cout << word << endl;
        i++;
    }
}
