#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int LIMIT = 1000000;
int fact_num[LIMIT+1], max_num[LIMIT+1];

void __init();
int main(){
    __init();
    int t_case; cin >> t_case;
    for(int i = 0; i <  t_case; i++){
        int number; cin >> number;
        cout << max_num[number] << endl;
    }
    return 0;
}

void __init(){
    int max_fact = 0, max_fact_num = 0;
    fact_num[0] = 0;
	for(int i = 1; i <= LIMIT; i++)
        for(int j = i; j <= LIMIT; j += i)
            fact_num[j]++;
    for(int i = 1; i <= LIMIT; i++){
        max_fact = (max_fact < fact_num[i]) ? fact_num[i] : max_fact;
        if(max_fact == fact_num[i]) max_fact_num = i;
        max_num[i] = max_fact_num;
    }
}
