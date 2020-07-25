#include <stdio.h>
#include <calc.h>

int main(){
	int a, b;
	printf("Enter two number : ");
	scanf("%d %d", &a, &b);
	printf("Addition\t%d\n", add_num(a,b));
	printf("Subtraction\t%d\n", sub_num(a,b));
	printf("Multiplication\t%d\n", mul_num(a,b));
	printf("Division\t%.5f\n", div_num(a,b));
	return 0;
}