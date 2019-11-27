/*
	Title:  X format display
	Author: Sachin Devadiga
	Date:   28/05/2019 11:11 IST
	Description: Program to display the word 'Hello' in X format. 
				 Input specifications: num: Variable to hold the value of the limit entered.
				 Output specifications: Display the result
 */
/*-------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	//Clear the output screen
	system("clear");

	//Declaring the variables here
	int i, j, num, status;
	char option;

	do
	{
		//Prompt the user to enter the limit
		printf("Enter the limit:");

		//Read the value + store in the variable
		status = scanf("%d", &num);

		//Validation to check if the entered value is a number
		if (status != 1)
		{
			printf("Invalid entry.. Please enter a number\n");
		}

		//Logic to obtain the rows and columns of the pattern 
		for (i=1; i <= num; i++)
		{
			for (j=1; j <= num + 1; j++)
			{
				if(j == i || j == (num - i + 1))
				{
					printf("Hello");
				
					//Logic to enter Hello when the input number is odd
					if(j == i && j == (num - i + 1))
					{
						printf("Hello");

					}
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
		}

		//Prompt the user if the program is to be repeated
		printf("Do you wish to continue.. Press [Yy | Nn]: ");

		//Read the value + store in the variable
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
}
