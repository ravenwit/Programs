#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int v1=rand()%10 +1;
    int v2 = rand() % 100;         // v1 in the range 0 to 99
    int v3 = rand() % 100 + 1;     // v2 in the range 1 to 100
    int v4 = rand() % 30 + 1985;   // v3 in the range 1985-2014

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << v3 << std::endl;
    std::cout << v4 << std::endl;
    return 0;
}
