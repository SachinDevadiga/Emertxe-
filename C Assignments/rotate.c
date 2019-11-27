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
unsigned char right_rotate(unsigned char, int);
unsigned char left_rotate(unsigned char, int);
int is_validnum(int);
int is_validbits(int);
void print_bits(int);

int main()
{	
	//Clear the output screen
	system("clear");

	//Declare the variables
	int no_of_bits, circ;
	unsigned char num, temp, option;

	do
	{
		//Prompt + Read the number
		printf("Enter the number: ");
		scanf("%hhd", &num);
		

		//Prompt + Read the number
		printf("Enter the number of times to rotate: ");
		scanf("%d", &no_of_bits);

		//Prompt to select the option
		printf("Enter the operation\n1.Right rotate\n2.Left rotate\n");
		scanf("%d", &circ);

		switch (circ)
		{ //Function call within the switch case
			case 1:
				temp = right_rotate(num, no_of_bits);
				break;

			case 2:
				temp = left_rotate(num, no_of_bits);
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
unsigned char right_rotate(unsigned char num, int bits)
{
	return (num >> bits) | (num << ((sizeof(char) * 8) - bits));
	
}

unsigned char left_rotate(unsigned char num, int bits)
{
	return (num << bits) | (num >> ((sizeof(char) * 8) - bits));

}

//Function to print the value in binary
void print_bits(int val)
{
	unsigned mask = 1 << sizeof(char) * 8;
	printf("Bits: ");
	for ( ; mask; mask >>= 1)
	{
		val & mask ? putchar ('1') : putchar ('0');
	}
	putchar('\n');

}

