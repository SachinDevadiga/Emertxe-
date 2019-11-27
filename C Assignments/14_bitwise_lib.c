/*
      Title:  Bitwise Functions
      Author: Sachin Devadiga
      Date:   04/06/2019 12:32 IST
      Description: Program to print the bitwise function outputs
                   Input specifications: num: Variable to hold the entered number
                   Output specifications: Display the result
*/
/*----------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#define INVALID 0
#define VALID	1

//Declaring the functions
int get_nbits(int, int);
int replace_nbits(int, int, int);
int get_nbits_from_position(int, int, int);
int replace_nbits_from_position(int, int, int, int);
int toggle_bits_from_position(int, int, int);
int print_bits(unsigned int, int);
int is_valid2(int, int);
void printbits(int);


int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables
	int num, no_of_bits, func, pos, val, temp, status, status1, res;
	char option;

	do
	{

		//Prompt + store the entered number
		printf("Enter a number: ");
		status = scanf("%d", &num);

		if(is_valid2(status, num) == INVALID)
		{
			return 0;
		}

		//Prompt + store the entered bit value
		printf("Enter the number of bits: ");
		status = scanf("%d", &no_of_bits);

		if (is_valid2(status, no_of_bits) == INVALID)
		{
			return 0;
		}
		
		//Prompt to select the case + read the value
		printf("Select the bitwise function:\n1. int get_nbits\n2. int replace_nbits\n3. int get_nbits_from_position\n4. int replace_nbits_from_position\n5. int toggle_nbits_from_position\n6. print_nbits\n");
		scanf("%d", &func);
	
		switch (func)
		{
			case 1:
				//Calling get_nbits function
				temp = get_nbits(num, no_of_bits);
				break;

			case 2: 
				//Prompt + Read the value
				printf("Enter the value: ");
				status = scanf("%d", &val);
				//Call validation function
				if (is_valid2(status, val) == INVALID)
				{
					return 0;
				}
				//Call replace_nbits function
				temp = replace_nbits(num, no_of_bits, val);
				break;

			case 3:
				//Prompt + Read the value
				printf("Enter the position: ");
				status = scanf("%d", &pos);
				//Call validation function
				if (is_valid2(status, pos) == INVALID)
				{
					return 0;
				}
				//Call get_nbits_from_position function
				temp = get_nbits_from_position(num, no_of_bits, pos);
				break;

			case 4:
				//Prompt + Read the value
				printf("Enter the value: ");
				status = scanf("%d", &val);
				//Call validation function
				if (is_valid2(status, val) == INVALID)
				{
					return 0;
				}
				//Prompt + Read the value
				printf("Enter the position: ");
				status = scanf("%d", &pos);
				//Call validation function
				if (is_valid2(status, pos) == INVALID)
				{
					return 0;
				}
				//Call replace_nbits_from_position function
				temp = replace_nbits_from_position(num, no_of_bits, val, pos);
				break;

			case 5: 
				//Prompt + Read the value
				printf("Enter the position: ");
				status = scanf("%d", &pos);
				//Call validation function
				if (is_valid2(status, pos) == INVALID)
				{
					return 0;
				}
				//Call toggle_bits_from_position function
				temp = toggle_bits_from_position(num, no_of_bits, pos);
				break;

			case 6: 
				//Call print_bits
				temp = print_bits(num, no_of_bits);
				break;

			default: 
					printf("Invalid entry.. Please enter a number between 1 - 6\n");
					return 0;
		}
		//Display the result
		printf("Value: %d\n", temp);
		printbits(temp);

		//Prompt if the program is to be repeated
		printf("Do you wish to continue.. Please press [Yy|Nn]: ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');

}

//Defining the functions as per the case operation
int get_nbits(int num, int no_of_bits)
{
	return num & ~(0xFF << no_of_bits);
}

int replace_nbits(int num, int no_of_bits, int val)
{
	return ((num & 0xFF << no_of_bits) | (val & ~(0xFF << no_of_bits)));
}

int get_nbits_from_position(int num, int no_of_bits, int pos)
{
	return (num & (~(0xFF << no_of_bits) << pos - no_of_bits + 1)) >> pos - no_of_bits + 1;
}

int replace_nbits_from_position(int num, int no_of_bits, int val, int pos)
{
	return num & ~(~(0xFF << no_of_bits) << pos - no_of_bits + 1) | (val & ~(0xFF << no_of_bits)) << pos - no_of_bits + 1;	
}

int toggle_bits_from_position(int num, int no_of_bits, int pos)
{
	return num ^ (~(~0 << no_of_bits)) << pos - no_of_bits + 1;
}

int print_bits(unsigned int num, int no_of_bits)
{
	return num & ~(0xFF << no_of_bits);
}

//Defining the validating function
int is_valid2(int stat, int var)
{
	if (stat != 1 || var <=0)
	{
		printf("Invalid entry.. Please enter a number\n");
		return INVALID;
	}
	return VALID;
}

//Defining function to print bits
void printbits(int temp)
{
	unsigned mask = 1 << sizeof(int) * 8 - 1;
	printf("Bits: ");
	for ( ; mask; mask >>= 1)
	{
		temp & mask ? putchar ('1') : putchar ('0');
	}
	putchar('\n');
}
