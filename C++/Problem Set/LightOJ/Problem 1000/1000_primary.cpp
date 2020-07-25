#include <iostream>
using namespace std;
int main(){
    int case_number = 5;
    unsigned int problems[] = {4,5,7,6,4,7,6,2,1,8};

    for(int i = 1; i <= case_number; i++){
        cout << "Case " << i << ": " << (problems[2*i-2] + problems[2*i-1]) << endl;
    }
    return 0;
}
