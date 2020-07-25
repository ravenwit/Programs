 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <ctype.h>
 #include <math.h>

 #define FNumber printf("Please Enter First Number : ")
 #define scanFNumber scanf("%lf",&Number1)
 #define SNumber printf("Please Enter Second Number : ")
 #define scanSNumber scanf("%lf",&Number2)
 #define Number printf("Please Enter Number : ")

 double Number1;
 double Number2;
 double Result;
 int Action, c, i, j;
 char a;

 int Addition()
	       {
		FNumber;

		  scanFNumber;

		SNumber;

		 scanSNumber;

			Result = Number1 + Number2;

		  printf("Addition Result : %.20lf \n ",Result);




			}

 int Subtraction()
		  {

			FNumber;

			 scanFNumber;

			SNumber;

			 scanSNumber;

			Result = Number1 - Number2;

		  printf("Subtraction Result : %.20lf \n ",Result);




		  }

 int Multiplication()
			  {

				FNumber;

				 scanFNumber;

				SNumber;

				 scanSNumber;

				 Result = Number1 * Number2;

				printf("Multiplication Result : %.20lf \n ",Result);





			 }

 int Divition()
			 {

		FNumber;

		  scanFNumber;

		SNumber;

		 scanSNumber;

			Result = Number1 / Number2;

		  printf("Divition Result : %.20lf \n ",Result);




		  }

 int Square()
		  {

			 Number;

		scanFNumber;

		 Result = Number1 * Number1;

		  printf("Square of %.5lf  : %.20lf \n",Number1,Result);
		  }

 int Qube()
		{

		  Number;

			scanFNumber;

			 Result = Number1 * Number1 * Number1;

		printf("Qube of %.5lf  : %.20lf \n",Number1,Result);

		  }

 int Power()
		 {

			Number;
			scanFNumber;
		  printf("Please Enter Power : ");
		  scanSNumber;
				 int k = Number2;
			Result = 1;

		 for(j=1;j<=k;j++)
			{

			 Result = Result * Number1;

			 }


			printf("%.5lfth Power of %.5lf  : %.20lf \n",Number2,Number1,Result);

		  }

 int loge()
			  {
				 Number;
				  scanFNumber;

					Result = log(Number1);

					 printf("Natural log of %.5lf  : %.20lf \n",Number1,Result);

					}
 int log10b()
				 {
					Number;
					 scanFNumber;

					  Result = log10(Number1);

						printf("10 base log of %.5lf  : %.20lf \n",Number1,Result);

					 }

 int sqrtcalc()
					 {
						Number;
						 scanFNumber;

							Result = sqrt(Number1);

							 printf("Square Root of %.5lf  :  %.20lf \n ",Number1,Result);
					 }

/*

int Modulus()
			{

			 FNumber;

		scanFNumber;

			 SNumber;

		scanSNumber;

		 Result=Number%Number2;

		  printf("Modulus Result : %lf \n ",Result);

	       }

*/

 int switchAction()
		  {

		   printf("\nAction Submit : ");

		    scanf("%d",&Action);

		   switch(Action)
				 {

				  case 1:
					Addition();

				    break;

				  case 2:
					 Subtraction();

				    break;

				  case 3:
					 Multiplication();

				    break;

				  case 4:

					 Divition();

				    break;

				  case 5:
					 Square();

				    break;

				  case 6:
					 Qube();

				    break;

				  case 7:
					 Power();

					 break;

				  case 8:
					 loge();

					  break;

				  case 9:
					 log10b();

						break;

				  case 10:
					  sqrtcalc();

					  break;


				  default:
					  printf("\nEnter a valid Action : ");

					 break;
				 }

			}




	int main(void)
			{


		printf("Action List : \n Press 1 for Addition. \n Press 2 for Subtraction.\n Press 3 for Multiplication.\n Press 4 for Divition. \n Press 5 for Square. \n Press 6 for Qube.\n Press 7 for Calculating Power.\n Press 8 for Natural Logarithm. \n Press 9 for 10 base Logarithm. \n Press 10 for Square Root. \n");



       con:
       switchAction();
	printf("Do you want to continue... (y/n):");
	a = getch();

	if(a=='y')
	{
	goto con;
	}


	     }


