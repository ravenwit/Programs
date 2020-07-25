#include <stdio.h>
#include <conio.h>

int main(void)
{
    textcolor(GREEN);
    int i, a, prime;
    printf("\n\n\t\t\t\t Prime Number Test Out\n\n");
    printf("\n\t\t\t\t Made by Shakir.\n");
    printf("Enter a Number to Test Out: ");
    scanf("%d",&a);
    prime=1;
    for(i=2;i<=a/2;i++)
    {
        if((a%i)==0)
        {
            prime=0;
        }
    }
    if(prime==1)
    {
        printf("\n\t\t\t\t The Number is Prime.");

    }
    else
    {
        printf("\n\t\t\t\t The Number is not Prime.");
    }
    getch();
}
