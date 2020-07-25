#include<stdio.h>
int calc(int x,int y, char op);
int main()
{
    int a=0;int b;char operate;
    printf("Enter a number: ");scanf("%d",&a);
    printf("Enter an operation:");
    getchar();operate=getchar();
    printf("Enter another numbner: ");scanf("%d",&b);
    printf("\nResult: %d",calc(a,b,operate));
    return 0;
}

int calc(int x,int y, char op)
{
    int result=0;
    switch(op)
    {
        case '+':
            result=x+y;
            break;
        case '-':
            result=x-y;
            break;
        case '*':
            result=x*y;
            break;
        case '/':
            result=x/y;
            break;
        default:
            printf("Invalid operation");
    }
    return result;
}
