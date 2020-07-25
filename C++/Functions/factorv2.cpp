#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

int __init(const long long &number);

int main(){
    unsigned long long number;
    while(cin >> number) __init(number);
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////

//      Check if a number is square and return output as a tuple
//      first part contains a binary value whether the given number is square
//      second part contains the floor of root which equals to the root if the number is square
tuple<bool, long long> __square_data(const long long &number){
    long long root = sqrt(number);
    return make_tuple((root*root == number), root);
}

//      Count Divisors using no dependency.
int __count_divisor(const long long &number){
    int count = 0;
    if(number==1) return 1;
    for(int i = 1; i <= (int)sqrt(number); i++)
        if(number%i==0) count+=(number/i==i)?1:2;
    return count;
}

//      Output a boolean based on whether the given number is prime.
bool __is_prime(const long long &number){
    if(number < 2) return false;
    else if(number < 4) return true;
    if(number%2==0 || number%3==0) return false;
    for(int i = 1; (6*i+1) <= (int)sqrt(number); i++)
        if(number%(6*i-1) == 0 || number%(6*i+1) == 0) return false;
    return true;
}

//      Find all divisors using no dependency. Inefficient for big number.
vector<long long> __divisors(const long long &number){
    vector<long long> divisors;
    if(number==1){divisors.push_back(1); return divisors;}
    for(int i = 1; i <= (int)sqrt(number); i++)
        if(number%i == 0){
            divisors.push_back(i);
            if(number/i != i) divisors.push_back(number/i);
        }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

//      Find all prime factors using no dependency. Efficient!
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

tuple<bool, long long> square_data;

//      Find all divisors of a number given its prime factors. Efficient!

long long __multiply(const vector<long long> &_set_){
    long long multiple = 1;
    for(int i = 0; i < _set_.size(); i++)
        multiple *= _set_[i];
    return multiple;
}

void __find_divisors(const vector<long long> &prime_factors, map<long long, int> &divisors, int offset, int amount){
    static vector<long long> prime_combination;
    if(amount == 0){divisors[__multiply(prime_combination)]++;return;}
    for(int i = offset; i <= prime_factors.size() - amount; ++i){
        prime_combination.push_back(prime_factors[i]);
        __find_divisors(prime_factors, divisors, i+1, amount-1);
        prime_combination.pop_back();
    }
}

map<long long, int> __divisors_from_primes(const vector<long long> &prime_factors){
    map<long long, int> divisors; divisors[1]++;
    for(int i = 1; i <= prime_factors.size(); i++)
        __find_divisors(prime_factors, divisors, 0, i);
    return divisors;
}

////////////////////////////////////////////////////////////////////////////////////////

//Highly composite number 5145645646486464

////////////////// Initializer ///////////////////////////////////////

int __init(const long long &number){
    square_data = __square_data(number);
    vector<long long> prime_factors = __prime_factors(number);
    map<long long, int> divisors = __divisors_from_primes(prime_factors);
    if(prime_factors[prime_factors.size() - 1] == number)
        cout << "\n\t\t" << number << " is a prime number" << endl;
    else
    cout << "\n\t\t" << number << " is a composite number" << endl;
    cout << "\n\t\tPrime Factors " << "(" << prime_factors.size() << "): ";
    for(int i = 0; i < prime_factors.size(); i++)
        cout << prime_factors[i] << string((i < prime_factors.size() - 1)?", ":"");
    cout << endl;
    cout << "\t\tDivisors " << "(" << divisors.size() << "): ";
    int fucking_comma_handler = 1;
    for(map<long long, int>::const_iterator it = divisors.begin(); it != divisors.end(); ++it){
        cout << it->first << string((fucking_comma_handler < divisors.size())?", ":"");
        fucking_comma_handler++;
    }

    cout << "\n" << endl;
    return 0;
}
