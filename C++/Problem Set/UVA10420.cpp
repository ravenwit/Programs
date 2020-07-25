#include <iostream>
#include <string>
#include <map>

using namespace std;
void __init(const int &test_case);
int main(){
    int t_case; cin >> t_case;
    __init(t_case);
    return 0;
}

void __init(const int &test_case){
    map<string, int> cntry; string cntry_n;
    for(int i = 0; i < test_case; i++){
        cin >> cntry_n; cin.ignore(100,'\n');
        cntry[cntry_n]++;
    }
    for(auto &x: cntry)
        cout << x.first << " " << x.second << endl;
}
