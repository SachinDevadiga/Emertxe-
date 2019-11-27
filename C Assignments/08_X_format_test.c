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
	int i, j, num, col, status;
	int flag = 1;
	char option;

	do
	{	
		//Prompt the user to enter the limit
		printf("Enter the limit:");
		
		//Read the value + store in the variable
		status=	scanf("%d", &num);
		
		//Validation to check if the entered value is a number
		if (status != 1)
		{
			printf("Invalid entry.. Please enter a number\n");
		}

		col = num;

		//Flagging when the entered number is even or odd
		if(num % 2)
		{
			flag = 0;
			col++;
		}

		//Logic to obtain the rows and columns of the pattern
		for (i=1; i <= num; i++)
		{
			for (j=1; j <= col; j++)
			{	
				//Logic to print when input is even
				if(flag)
				{
					if(j == i || j == col - i + 1 )
					{
						printf("Hello");
					}
					else
					{
						printf(" ");
					}
				}

				//Logic to print when input is odd
				else
				{
					if(i <= num / 2 + 1)
					{
						if(j == i || j == col - i + 1)
						{
							printf("Hello");
						}
						else
						{
							printf(" ");
						}

					}
					else
					{
						if(j == i+1 || j == col - i)
						{
							printf("Hello");
						}
						else
						{
							printf(" ");
						}
					}

				}
			}
			printf("\n");
		}

		//Prompt the user if the program is to be repeated
		printf("Do you wish to continue... Press [Yy | Nn]");
		
		//Read the value + store in the variable
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
}
