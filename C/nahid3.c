#include<stdio.h>
float calc(float x,float y, char op);
int main()
{
    float a, b;char operate;
    puts("Write something like 4+8\n");
    scanf("%f",&a);operate=getchar();scanf("%f",&b);
    printf("\nResult: %f\n\n",calc(a,b,operate));
    return 0;
}

float calc(float x,float y, char op)
{
    float result=0.0;
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
            result= (float) x/ (float)y;
            break;
        default:
            printf("Invalid operation");
    }
    return result;
}
