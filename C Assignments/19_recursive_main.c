/*
     Title:  Factorial using recursive main function
     Author: Sachin Devadiga
     Date:   10/06/2019 12:25 IST
     Description: Program to find factorial of a number and display the result. 
                  Input specifications: num: Variable to hold the entered integer number
                  Output specifications: Display the result
*/
/*-----------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

int main()
{	

	//Declare the variables
	static int num, fact = 0;
	int status;
	char option;

	do
	{
		//Condition to read and validate the entered number
		if (fact == 0)
		{
			//Clear the output screen
			system("clear");
			
			printf("Enter the number: ");
			status = scanf("%d", &num);

			//Validation to check if entered number is a positive integer
			if (status != 1 || num < 0)
			{
				printf("Invalid Entry.. Please enter a positive number\n");
				return 0;
			}
			fact = 1;
		}
		//Logic to generate the factorial 
		if (num)
		{
			fact *= num --;
			main();
			return fact;
		}
		//Display the result
		printf("Factorial is %d\n", fact);
		fact = 0;

		//Prompt of the program is to be repeated
		printf("Do you wish to continue.. Press [Yy | Nn]: ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
}
