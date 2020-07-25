#include <stdio.h>
#include <conio.h>

int main()
{
	con:
	int i, num, check;
	char ans;
	printf("\n\nPlease Enter Your Number to Check : ");
	scanf("%d",&num);
	check=1;
	for(i=2;i<num;i++)
	{
		if(num%i==0)
		{
			check=0;
			break;
		}

	}
	if(check==1)
	{
		printf("\n\n\t\t\t\t The Number %d is Prime.",num);

	}
	else if (check==0)
	{
		printf("\n\n\t\t\t\t The Number %d is not Prime.",num);
	}
	printf("\nDo you want to check again? (y/n)");
	ans=getch();
	if(ans=='y'||ans=='Y')
	{
		goto con;
	}
}
