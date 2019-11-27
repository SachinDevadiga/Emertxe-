/*
       Title:  Bitwise LSB
       Author: Sachin Devadiga
       Date:   07/06/2019 12:32 IST
       Description: Program to print the bitwise function outputs
                    Input specifications: num: Variable to hold the entered number
                    Output specifications: Display the result
*/
/*----------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#define INVALID 0
#define VALID 1

//Declare the functions
int bitwise_lsb(int, int, int, int);
int is_valid(int, int);
int is_valid1(int);
void print_bits(int);

int main()
{	
	//Clear the output
	system("clear");

	//Declare the variables
	int num, val, a, b, lsb, status, temp; 
	char option;

	do
	{
		//Prompt + Read the number
		printf("Enter the number: ");
		status = scanf("%d", &num);

		//Valiidation to check if entered value is a number
		if (is_valid1(status) == INVALID)
		{
			return 0;
		}

		//Prompt + Read the number
		printf("Enter the value: ");
		status = scanf("%d", &val);
		
		//Valiidation to check if entered value is a number
		if (is_valid1(status) == INVALID)
		{
			return 0;
		}

		//Prompt + Read the number
		printf("Enter a value (no_of_bits) and b value (position): ");
		scanf("%d%d", &a, &b);
		
		//Valiidation to check if entered value is a number
		if (is_valid(a,b) == INVALID)
		{
			return 0;
		}
		
		//Provided equation
		lsb = b - a + 1;

		//Calling the function + Displaying the output
		printf("Value: %d\n",bitwise_lsb(num, val, a, lsb));
		temp = bitwise_lsb(num, val, a, lsb);
		print_bits(temp);
		
		//Prompt if the program is to be repeated
		printf("Do you wish to continue.. Please press [Yy|Nn]: ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');

}	

//Function to evaluate the given condition
int bitwise_lsb(int num, int val, int a, int lsb)
{
	
	return (num & ~(~0 << a)) << lsb | val & ~(~(~0 << a) << lsb);
	
}

//Function to print the result in binary
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
// Function for validating a and b
int is_valid(int a, int b)
{
	if ((0 <= a && a <=31) && (a <= b && b <= 31))
	{
		return VALID;
	}
	printf("Invalid entry.. Please enter a and  b values in the range 0 - 31 and a < b");
	return INVALID;
}

//Function for validating the entered number
int is_valid1(int stat)
{
	if (stat != 1)
	{
		printf("Invalid entry.. Please enter a number\n");
		return INVALID;
	}
	return VALID;
}
