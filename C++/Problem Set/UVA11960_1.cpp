#include <iostream>
#include <cmath>

using namespace std;

int hcn[] = {1, 2, 4, 6, 12, 24, 36, 48, 60,
            120, 180, 240, 360, 720, 840, 1260, 1680,
            2520, 5040, 7560, 10080, 15120, 20160, 25200,
            27720, 45360, 50400, 55440, 83160, 110880, 166320,
            221760, 277200, 332640, 498960, 554400, 665280, 720720, 997920};

int __count_divisor(const int &number){
    int count = 0;
    if(number==1) return 1;
    for(int i = 1; i <= (int)sqrt(number); i++)
        if(number%i==0) count+=(number/i==i)?1:2;
    return count;
}
int __find_hcn(const int &number){
    for(int i = 38; i >= 0; i--)
        if(hcn[i]<=number) return hcn[i];
}

void __init();

int main(){
    int t_case; cin >> t_case;
    for(int i = 0; i <  t_case; i++) __init();
    return 0;
}
bool blu = false;
void __init(){
	if(!blu) blu=1; else cout << endl;
    int number; cin >> number;
    int limit = __find_hcn(number);
    int max_num = limit;
    int max_div = __count_divisor(limit);
    for(int i = number; i >= limit; i--){
    	if(__count_divisor(i) == max_div){
    		max_num = i; break;
    	}
    }
    cout << max_num;
}
