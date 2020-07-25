#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <unordered_map>
#include <cmath>

using namespace std;

void __assign_digits();
void ___init();

int main(int argc, char const *argv[]){
    cout << "\n\t\tYou can convert number up to base 64.\n\t\tUse alpha-numeric characters.\n\n" << endl;
    __assign_digits();
    while(1) ___init();
    return 0;
}

int min_base = 0;
unordered_map<char, int> digit_to_num;
unordered_map<int, char> num_to_digit;

template <typename A, typename B>
unordered_map<B, A> flip_map(unordered_map<A, B> &__map){
    unordered_map<B, A> out;
    for(auto &i: __map)
        out.insert(pair<B, A>(i.second, i.first));
    return out;
}

template <typename T_a>
T_a GetMax(T_a a, T_a b){
    return (a > b) ? a : b;
}

void __assign_digits(){
	int index, __num=0;
	for(index = 48; index < 58; index++, __num++)
		digit_to_num[(char)index] = __num;
	for(index = 65; index < 91; index++, __num++)
		digit_to_num[(char)index] = __num;
	for(index = 97; index < 123; index++, __num++)
		digit_to_num[(char)index] = __num;
	digit_to_num[(char)43] = __num++;
	digit_to_num[(char)47] = __num++;
	digit_to_num[(char)34] = __num++;
	digit_to_num[(char)33] = __num++;
	for(index = 35; index < 39; index++, __num++)
		digit_to_num[(char)index] = __num;
	for(index = 40; index < 43; index++, __num++)
		digit_to_num[(char)index] = __num;
	for(index = 44; index < 47; index++, __num++)
		digit_to_num[(char)index] = __num;
	for(index = 60; index < 65; index++, __num++)
		digit_to_num[(char)index] = __num;
	digit_to_num[(char)59] = __num++;
	for(index = 91; index < 97; index++, __num++)
		digit_to_num[(char)index] = __num;
	digit_to_num[(char)58] = __num++;
	for(index = 123; index < 127; index++, __num++)
		digit_to_num[(char)index] = __num;
	digit_to_num[(char)39] = __num++;
	
	num_to_digit = flip_map(digit_to_num);
	
}

bool _is_valid(string &number){
	for(int i = 0; i < number.size(); i++){
		if(!(digit_to_num.count(number[i]) > 0)) return false;
		min_base = GetMax(min_base, int(digit_to_num[number[i]] + 1));
	}
	return true;
}

string _get_number(){
    string number;
    cout << "Enter your number: "; cin >> number;
    if(!_is_valid(number)){
        cout << "\n\t\tNumber not valid. \n" << endl;
        number = _get_number();
    }
    return number;
}

int _get_base_from(){
    int from_base; string bk = (min_base < 62) ? "=< ): " : "= ): ";
    cout << "Base of the number ( " << min_base << bk; cin >> from_base;
    while(from_base < min_base){
        cout << "\t\tYour number contains invalid digits for base " << from_base << endl;
        from_base =_get_base_from();
    }
    return from_base;
}

string _to_decimal(string number, int base){
    long deci_out = 0;
    for(int i = number.length() - 1; i >= 0; i--){
        deci_out += (long)(digit_to_num[number[i]] * (int)pow(base, number.length() - 1 - i));
    }
    return deci_out;
}


void ___init(){
    string number = _get_number();
    int from_base = _get_base_from();
    int to_base; cout << "Convert to (base): "; cin >> to_base; cout << endl;
    cout << "\tResult: Number (base) \n" << endl;
    cout << number << " (" << from_base << ") = " << _to_decimal(number, from_base) << " (10) = "<< _base_converter(_to_decimal(number, from_base), to_base) << " (" << to_base << ")\n" << endl;
    cout << endl;
}
