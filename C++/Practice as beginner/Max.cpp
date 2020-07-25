#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i,n,max;
	char ans;
con:
	printf("\nHow many numbers do you want to calculate: ");
	scanf("%d",&n);
	int number[n-1];
	for(i=0;i<=n-1;i++)
	{
		printf("\nEnter number %d: ",i+1);
		scanf("%d",&number[i]);

	}
	max = number[0];
	for(i=0;i<=n-1;i++)
	{
		if(max<number[i])
		{
			max = number[i];
			continue;
		}
	}
	printf("\n\t\tMaximum Number: %d\n",max);
	printf("\nDo you wnat to calculate again? (y/n): ");
	ans= getch();
	if(ans=='y'||ans=='y')
	{
		goto con;
	}
}
