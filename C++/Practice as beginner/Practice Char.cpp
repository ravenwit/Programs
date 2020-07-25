#include <stdio.h>

/*#include <conio.h>*/
int main()
{
    continuecalc:
    int number, i, result=0;
    char sign='X', con;
    printf("\nEnter a number to calculate: ");
    scanf("%d",&number);
    for(i=1;i<=20;i++)
    {
        result = result + number;// result = number * i
        printf("%d %c %d = %d\n",number, sign, i, result);

        if(i==10)
        {
            printf("\n");
        }
    }
    printf("\nDo you want to continue. (y/n): ");
    con=getchar();
    if(con=='y' || con=='Y')
    {
        goto continuecalc;
    }
    return 0;
}
