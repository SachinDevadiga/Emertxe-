/*
     Title:  Pre-increment, Post-increment using Bitwise operators
     Author: Sachin Devadiga
     Date:   14/06/2019 12:25 IST
     Description: Program to perform pre-increment and post-increment and display the result. 
                  Input specifications: num: Variable to hold the entered integer number
                  Output specifications: Display the result
*/
/*-----------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

//Declaring the functions
int pre_increment(int *);
int post_increment(int *);
int isvalid(int);
int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables here
	int num, opr, res, status;
	char option;

	do
	{
		//Prompt + Read the value
		printf("Enter a number: ");
		status = scanf("%d", &num);

		//Caling the Validation function
		if(isvalid(status) || num < 0)
		{
			printf("Invalid entry.. Please enter a positive number\n");
			return 0;
		}

		//Prompt + Read the selected operation
		printf("Select the option\n1. Pre-increment\n2. Post-increment\n");
		scanf("%d", &opr);
		
		//Perform operation based on the selection
		switch(opr)
		{
			case 1:
				//Calling the pre-increment function and storing the result
				res = pre_increment(&num);
				printf("Result after operation\nnum = %d\nres = %d\n", num, res);
				break;

			case 2: 
				//Calling the pre-increment function and storing the result
				res = post_increment(&num);
				printf("Result after operation\nnum = %d\nres = %d\n", num, res);
				break;

			default:
				printf("Invalid entry..Please enter option 1 or option 2\n");
				return 0;

		}

		//Prompt if the program is to be repeated
		printf("Do you wish to continue.. Press [Yy | Nn]: ");
		scanf("\n%c", &option);

	}while(option == 'Y' || option == 'y');
}

//Defining the pre-increment function
int pre_increment(int *num)
{
	unsigned int mask = 1;

	//Toggling the bits from the LSB position until the first 0 bit is reached (Condition satisfies for odd number)
	while(*num & mask)
	{
		*num = *num ^ mask;
		mask <<= 1;
	}
	//Toggling the LSB of the number
	*num = *num ^ mask;
	
	return *num;
}

//Defining the post-increment function
int post_increment(int *num)
{
	unsigned int mask = 1;
	int temp = *num;

	//Toggling the bits from the LSB position until the first 0 bit is reached (Condition satisfies for odd number)
	while(*num & mask)
	{
		*num = *num ^ mask;
		mask <<= 1;
	}
	//Toggling the LSB of the number
	*num = *num ^ mask;
	
	return temp;
}

//Defining Validation function
int isvalid(int status)
{
	if (status != 1)
	{
		return 1;
	}
	return 0;
}
