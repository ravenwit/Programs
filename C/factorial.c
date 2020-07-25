#include <stdio.h>


int factorial(int number){
int result,i;
result=1;
for(i=1;i<=number;i++){
    result*=i;
}
return result;
}
int main(){
int number1;
printf("Enter a number : ");
scanf("%d", &number1);
printf("Factorial of %d is %d. \n",number1,factorial(number1));
return 0;
}



/*
int  main(){
int i, rsult;
for(i=1;i<=3;i++){
    rsult*=i;
}
printf("Factorial : %d", rsult);
return 0;
}
*/
