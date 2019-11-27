/*
      Title:  Binary Bit Display
      Author: Sachin Devadiga
      Date:   04/06/2019 12:32 IST
      Description: Program to print the binary bits of an entered integer number
                   Input specifications: num: Variable to hold the entered integer number
                   Output specifications: Display the result
*/
/*-----------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables here
	unsigned num1, num2, mask;
	int status;
	char option;

	do
	{
		//Prompt + Read the number
		printf("Enter the number: ");
		status = scanf("%d", &num1);

		//Validation to check if entered  number is an integer
		if (status != 1)
		{
			printf("Inalid entry.. Please enter an integer number\n");
			exit(1);
		}

		//Initialising negative limit of the entered number
		num2 = -1 * num1;

		//Logic to find the SET bits in the memory
		mask = 1 << (sizeof(int) << 3) - 1;

		//Print the result
		printf("%d: ", num1);
		for ( ;mask; mask >>=1)
		{
			num1 & mask ? putchar('1') : putchar('0');
		}

		//Logic to find the SET bits in the memory
		mask = 1 << (sizeof(int) << 3) - 1;
		printf("\n%d: ", num2);
		for ( ;mask; mask >>=1)
		{
			num2 & mask ? putchar('1') : putchar('0');
		}

		//Prompt user if the program is to be repeated + store the value
		printf("\nDo you wish to continue... Press [Yy | Nn]: ");
		scanf("\n%c", &option);

	}while (option == 'Y' || option == 'y');
}
