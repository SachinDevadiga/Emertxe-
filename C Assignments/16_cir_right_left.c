/*
         Title:  Bitwise rotate
         Author: Sachin Devadiga
         Date:   07/06/2019 12:32 IST
         Description: Program to print the bitwise function outputs
                      Input specifications: num: Variable to hold the entered number
                      Output specifications: Display the result
*/
/*---------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

//Declaring the functions
int right_rotate(unsigned int, int);
int left_rotate(unsigned int, int);
int is_validnum(int);
void print_bits(int);

int main()
{	
	//Clear the output screen
	system("clear");

	//Declare the variables
	int no_of_bits, circ, temp, status;
	unsigned int num;
	char option;

	do
	{
		//Prompt + Read the number
		printf("Enter the number: ");
		status = scanf("%d", &num);
		
		//Call the validation function
		if (is_validnum(status) == 0)
		{
			return 0;
		}

		//Prompt + Read the number
		printf("Enter the number of times to rotate: ");
		status = scanf("%d", &no_of_bits);
		
		//Call the validation function
		if (is_validnum(status) == 0 || no_of_bits < 0)
		{
			printf("Invalid entry... Please enter a +ve number\n");
			return 0;
		}
			

		//Prompt to select the option
		printf("Enter the operation\n1.Right rotate\n2.Left rotate\n");
		scanf("%d", &circ);

		switch (circ)
		{ 
			//Function call within the switch case
			case 1:
				//Function call to right rotate bits
				temp = right_rotate(num, no_of_bits);
				break;

			case 2:
				//Function call to left rotate bits
				temp = left_rotate(num, no_of_bits);
				break;

			default:
					printf("Invalid entry.. Please select option 1 or option 2\n");
					return 0;
		}

		//Calling function to print bits
		printf("Binary form of %d\n", num);
        print_bits(num);
		
		// Print the result
		printf("Result: %u\n", temp);
		print_bits(temp);

		//Prompt if the program is to be repeated
		printf("Do you wish to continue.. Please press [Yy|Nn]: ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
}

//Defining the functions for rotate operations
int right_rotate(unsigned int num, int bits)
{
	return (num >> bits) | (num << ((sizeof(int) * 8) - bits));
}

int left_rotate(unsigned int num, int bits)
{
	return (num << bits) | (num >> ((sizeof(int) * 8) - bits));
}

//Function to print the value in binary
void print_bits(int val)
{
	unsigned mask = 1 << sizeof(int) * 8 - 1;
	printf("Bits: ");
	for ( ; mask; mask >>= 1)
	{
		val & mask ? putchar ('1') : putchar ('0');
	}
	putchar('\n');
}

//Function to validate the entered number
int is_validnum(int stat)
{
	if (stat != 1)
	{	
		printf("Invalid entry.. Please enter a valid number\n");
		return 0;
	}
	return 1;
}
