/*
	Title:  Perfect number validation
	Author: Sachin Devadiga
	Date:   29/05/2019 12:25 IST
	Description: Program to check if the given number is a perfect number or not and display the result. 
				 Input specifications: num: Variable to hold the entered integer number
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
	int sum, i, num, status;
	char option;

	do
	{
		//Prompt the user to enter the number
		printf("Enter a number: ");

		//Read the value + store in the variable and assign the value to the status variable for validation
		status = scanf("%d", &num);

		//Validation to check if entered value is a positive number. If any other characters are entered, the condition becomes true and exits out
		if(status != 1 || num <= 0)
		{
			printf("Invalid entry.. Please try again\n ");
			exit(1);
		}

		//Initialising the variable before the logic operation
		sum = 0;

		//Iterating the loop upto the entered number
		for(i = 1; i < num; i++)
		{
			if(num % i == 0) //Logic to find the factors of the entered number
			{
				sum = sum + i; // Addition of the factorials of the entered number
			}
		}

		//Condition to check if the result is the same as the entered number and display the output
		if(sum == num)
		{
			printf("%d is a perfect number\n", num);
		}
		else
		{
			printf("%d is not a perfect number\n", num);
		}

		//Prompt the user to enter [Yn | Nn] to repeat the program
		printf("Do you wish to continue...Press [Yy | Nn]: ");

		//Read the value + store in the variable
		scanf("\n%c", &option);

	}while (option == 'Y' || option == 'y');
}
