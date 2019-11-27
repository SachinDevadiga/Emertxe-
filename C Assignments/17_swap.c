/*
     Title:  Swapping numbers using pass-by reference mechanism
     Author: Sachin Devadiga
     Date:   17/06/2019 12:25 IST
     Description: Program to swap two numbers using pass-by reference mechanism and display the result. 
                  Input specifications: num1, num2: Variable to hold the entered integer number
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

//Declare the swap function
int swap(int *, int *);

int main()
{
	//Declare the variables here
	int num1, num2;
	char option;

	do
	{
		//Prompt + store the value
		printf("Enter two numbers: ");
		scanf("%d%d", &num1, &num2);

		//Displaying the numbers before swapping
		printf("Value before swapping\nnum1: %d\nnum2: %d\n", num1, num2);

		//Calling the swapping function
		swap(&num1, &num2);

		//Displaying the numbers post swapping
		printf("Value before swapping\nnum1: %d\nnum2: %d\n", num1, num2);

		//Prompt if the program is to be repeated
		printf("Do you wish to continue.. Press [Yy | Nn]:");
		scanf("\n%c", &option);

	}while (option == 'Y' || option == 'y');
}

//Defining the swap function
int swap(int *n1, int *n2)
{
	//Logic to swap values using pointers using pass-by reference 
	*n1 = *n1 ^ *n2;
	*n2 = *n1 ^ *n2;
	*n1 = *n1 ^ *n2;
}
