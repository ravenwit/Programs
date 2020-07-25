#include <iostream>

using namespace std;

int __get_digit(const char &letter){
    int letteri = letter;
    if(letteri>64 && letteri<68) return 2;
    else if(letteri>=68 && letteri<71) return 3;
    else if(letteri>=71 && letteri<74) return 4;
    else if(letteri>=74 && letteri<77) return 5;
    else if(letteri>=77 && letteri<80) return 6;
    else if(letteri>=80 && letteri<84) return 7;
    else if(letteri>=84 && letteri<87) return 8;
    else if(letteri>=87 && letteri<91) return 9;
    else letteri;
}

int main(){
    string phone;
    while(getline(cin,phone)){
        for(int i = 0; i < phone.length(); i++){
            if(phone[i]>64) cout << __get_digit(phone[i]);
            else cout << phone[i];
        }
        cout << endl;
    }
    return 0;
}
