#include <stdio.h>
#include <conio.h>

int main(void)
{
    int i, num, s;
    char answer;
    continuecalc:
    s=0;
    printf("Please enter a number to calculate summation: ");
    scanf("%d",&num);
    for(i=0;i<=num;i++)
    {
        s=s+i;
    }
    printf("Result: %d",s);
    printf("Do you want to calculate again ? (y/n): ");
    answer = getch();
    if(answer=='y' || answer=='Y')
    {
        goto continuecalc;
    }

}
