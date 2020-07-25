#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>

using namespace std;

void ___init();

int main(int argc, char const *argv[]){
    cout << "\n\t\tYou can convert number up to base 61.\n\t\tUse alpha-numeric characters.\n\n" << endl;
    while(1) ___init();
    return 0;
}

int min_base = 0;

int __get_number(char digit){
    if((int)digit < 58) return (int)digit - 48;
    else if((int)digit > 96) return (int)digit - 61;
    else return (int)digit - 55;
}

char __get_digit(int digit){
  if(digit < 10) return char(digit + 48);
  else if(digit > 35) return char(digit + 61);
  else return char(digit + 55);
}

bool _is_valid(string &number){
    for(int i = 0; i < number.length(); i++){
        int number_i = (int)number[i];
        if(!(number_i > 47 && number_i < 58 ||
             number_i > 64 && number_i < 91 ||
             number_i > 96 && number_i < 123)) return false;
        if(number_i > min_base) min_base = number_i;
    }
    min_base = __get_number(char(min_base)) + 1;
    return true;
}

long _to_decimal(string number, int base){
    long deci_out = 0;
    for(int i = number.length() - 1; i >= 0; i--){
        deci_out += (long)(__get_number(number[i]) * (int)pow(base, number.length() - 1 - i));
    }
    return deci_out;
}

string _base_converter(long number, int base){
    string out;
    while(number > 0){
        out.push_back(__get_digit(number%base));
        number /= base;
    }
    reverse(out.begin(), out.end());
    return out;
}

string _get_number(){
    string number;
    cout << "Enter your number: "; cin >> number;
    if(!_is_valid(number)){
        cout << "\n\t\tNumber not valid. Use alpha-numeric characters. \n" << endl;
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


void ___init(){
    string number = _get_number();
    int from_base = _get_base_from();
    int to_base; cout << "Convert to (base): "; cin >> to_base; cout << endl;
    cout << "\tResult: Number (base) \n" << endl;
    cout << number << " (" << from_base << ") = " << _to_decimal(number, from_base) << " (10) = "<< _base_converter(_to_decimal(number, from_base), to_base) << " (" << to_base << ")\n" << endl;
    cout << endl;
}
