/*
	Title:  Fibonacci series
	Author: Sachin Devadiga
	Date:   28/05/2019 21:36 IST
	Description: Program to print the Fibonacci series upto the entered limit 
				 Input specifications: limit: Variable to hold the limit value from the user
				 Output specifications: Display the result
 */
/*-------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	//Declaring the variables here
	int limit, num1, num2, res, status;
	char option;

	//Loop is used to repeat the program as long as the user inputs [Yy]
	do
	{
		//Clear the output screen
		system("clear");

		//Prompt the user to enter the limit
		printf("Enter the limit: ");

		//Read the value and store in the variable
		status = scanf("%d", &limit);
	
		//Validation to check if the 
		if (status != 1)
		{
			printf("Invalid input.. Please try again\n");
			exit(1);
		}
		
		//Display the statement in the output screen
		printf("Fibonacci series till %d:\n", limit);
	
		//Initialising the variable used as a temporary variable during logic operation. 
		res = 0;
		num1 = 0;
		num2 = 1;
		
		//Condition to check if entered limit vaule is a positive integer and execute the internal logic
		if(limit > 0)
		{
			//Loop is used to re-interate the addition of the current number with the next number till the condition is true
			while(num1 <= limit)
			{
				printf("%d\t", num1); //Print the output
				res = num1 + num2;
				num1 = num2;
				num2 = res;
			}
		}
		//If the entered limit is a negative integer the internal logic is executed
		else
		{
			//Loop is used to re-interate the addition of the current number with the next number till the condition is true
			while(num1 >= limit && num1 <= -limit)
			{
				printf("%d\t", num1); //Print the output
				res = num1 - num2;
				num1 = num2;
				num2 = res;
			}
		}
		//Prompting the user if the program requires to be repeated once more
		printf("\nDo you wish to continue... Press [Yy | Nn]:");

		//Read the character + store in the variable
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y' );
}

