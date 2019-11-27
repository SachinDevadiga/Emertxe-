/*
     Title:  IEEE output of float and double datatype
     Author: Sachin Devadiga
     Date:   13/06/2019 13:25 IST
     Description: Program to convert float and double values into IEEE format and display the result. 
                  Input specifications: num1. num2: Variable to hold the entered value
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

//Declare the functions
void float_binary(int *);
void double_binary(long int *);

int main()
{
	//Clear the output screen
	system("clear");

	//Define the variables
	int select;
	float num1;
	double num2;
	char option;

	do
	{
		//Prompt to select the option
		printf("Select the option:\n1.Float\n2.Double\n");
		scanf("%d", &select);

		switch(select)
		{
			case 1:
				//Prompt + Read the value
				printf("Enter a float number: ");
				scanf("%f", &num1);

				//Display the output
				printf("Sign\tExponent\tMantissa\n");
				//Calling the float funtion
				float_binary((int *)&num1);
				break;

			case 2: 
				//Prompt + Read the value
				printf("Enter a double number: ");
				scanf("%lf", &num2);

				//Display the output
				printf("Sign\tExponent\tMantissa\n");
				//Calling the double funtion
				double_binary((long int *)&num2);
				break;

			default:
				printf("Invalid entry.. Please select option 1 or option 2\n");
				return 0;
		}

		//prompt of the program is to be repeated
		printf("Do you wish to continue.. Press [Yy | Nn]: ");
		scanf("\n%c", &option);
	
	}while (option == 'Y' || option == 'y');
}

//Defining the IEEE float format function
void float_binary(int *temp)
{	
	int count = 0;
	unsigned mask = 1 << (sizeof(int) << 3) - 1;

	for ( ; mask; mask >>= 1)
	{
		if (count == 1 || count == 9)
		{
			printf("\t");
		}
		*temp & mask ? putchar ('1') : putchar ('0');
		count++;
	}
	putchar('\n');
}

//Defining the IEEE double format function
void double_binary(long int *temp)
{	
	int count = 0;
	unsigned long mask = 1UL << (sizeof(long int) << 3) - 1;

	for ( ; mask; mask >>= 1)
	{
		if (count ==  1 || count == 12)
		{
			printf("\t");
		}
		*temp & mask ? putchar ('1') : putchar ('0');
		count++;
	}
	putchar('\n');
}
