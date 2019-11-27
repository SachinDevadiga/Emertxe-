/*
     Title:  Bitwise Even or Odd
     Author: Sachin Devadiga
     Date:   04/06/2019 11:32 IST
     Description: Program to check if the given number is an even number or odd
                  Input specifications: num: Variable to hold the entered integer number
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>


int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables here
	int num, status;
	char option;

	do
	{
	//Prompt user to enter a number
	printf("Enter the number: ");

	//Read the number + store in the variable
	status = scanf("%d", &num);
	
	//Validation of the entered number
	if (status != 1 || num <= 0)
	{
		printf("Invalid entry.. Please try again\n");
		exit(1);
	}

	//Logic to check if the last bit of the number is set to 1 and print the respective result
	num & 1 ? printf("Odd number\n") : printf("Even number\n");
	
	//Prompt user if the program is to be repeated
	printf("Do you wish to continue.. Press [Yy | Nn]: ");

	//Read the value + store in the variable
	scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
}

