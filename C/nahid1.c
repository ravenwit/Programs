#include <stdio.h>
int cyclicShift(int *a, int *b, int *c);
int main()
{
int x,y,z,size;
x=5;y=8;z=10;size=256;
char *ans; ans = (char*) malloc (size);
printf("x = %d , y = %d , z = %d\n",x,y,z);
do{
    cyclicShift(&x,&y,&z);
   printf("\nAfter  Shift: x = %d , y = %d , z = %d",x,y,z);
   printf("\n\nDo you want to shift again?(y/n): ");getline(&ans,&size,stdin);
}while(ans[0]=='y');
return 0;
}

int cyclicShift(int *a, int *b, int *c)
{
    int values[]={*a,*b,*c};
    *a=values[2];*b=values[0];*c=values[1];
}
