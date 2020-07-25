#include <iostream>
#include <math.h>
int main(){
    int i=2147483648; int j=0;
    //std::cin >> i;
    while(((int)(i/pow(2,j)))!=0){
        j++;
    }
    if((i % int(pow(2,j))==0))
        std::cout << j << " is power" << std::endl;

    std::cout << "\n" << j << "   " << j-1 << std::endl;

}
