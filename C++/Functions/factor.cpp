#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int __count_divisor(const long long &number){
    int count = 0;
    if(number==1) return 1;
    for(int i = 1; i <= (int)sqrt(number); i++)
        if(number%i==0) count+=(number/i==i)?1:2;
    return count;
}

bool __is_prime(const long long &number){
    if(number < 2) return false;
    else if(number < 4) return true;
    if(number%2==0 || number%3==0) return false;
    for(int i = 1; (6*i+1) <= (int)sqrt(number); i++)
        if(number%(6*i-1) == 0 || number%(6*i+1) == 0) return false;
    return true;
}

vector<long long> __divisors(const long long &number){
    int count = 0; vector<long long> divisors;
    if(number==1){divisors.push_back(1); return divisors;}
    for(int i = 1; i <= (int)sqrt(number); i++)
        if(number%i == 0){
            divisors.push_back(i);
            if(number/i != i) divisors.push_back(number/i);
        }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

vector<long long> __prime_factors(long long number){
    vector<long long> prime_factors;
    while(number%2==0){
        prime_factors.push_back(2); number /= 2;
    }
    for(int i = 3; i <= (int)sqrt(number); i+=2)
        while(number%i==0){
            prime_factors.push_back(i);
            number /= i;
        }
    if(number > 2) prime_factors.push_back(number);
    return prime_factors;
}

int __init(const long long &number);
int main(){
    unsigned long long number;
    while(cin >> number) __init(number);
    return 0;
}

int __init(const long long &number){
    vector<long long> prime_factors = __prime_factors(number);
    if(prime_factors[prime_factors.size() - 1] == number)
        cout << "\t\t" << number << " is a prime number" << endl;
    else
    cout << "\t\t" << number << " is a composite number" << endl;
    cout << "\t\tPrime Factors: ";
    for(int i = 0; i < prime_factors.size(); i++)
        cout << prime_factors[i] << string((i < prime_factors.size() - 1)?", ":"");
    cout << endl;
    cout << "\t\tDivisors: ";
    vector<long long> divisors = __divisors(number);
    for(int i = 0; i < divisors.size(); i++)
        cout << divisors[i] << string((i < divisors.size() - 1)?", ":"");
    cout << endl;
    return 0;
}
