#include <iostream>
using namespace std;
int main(){
    int case_number = 0;
    cin >> case_number;
    if(case_number>125)
        return 1;
    unsigned int problems[case_number * 2 - 1];
    for(int i = 0; i <= case_number - 1; i++){
        cin >> problems[2*i] >> problems[2*i+1];
    }
    for(int j = 1; j <= case_number; j++){
        cout << "Case " << j << ": " << (problems[2*j-2] + problems[2*j-1]) << endl;
    }
    return 0;
}
