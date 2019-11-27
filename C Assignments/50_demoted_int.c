/*
     Title:  Demoted int
     Author: Sachin Devadiga
     Date:   9/07/2019 23:25 IST
     Description: Program to demote float value to int value and display the result. 
                  Input specifications: f : Value to hold the integer variable. 
                  Output specifications: Display the result.
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

//Defining the structure
typedef struct
{
	unsigned int mantissa:23;
	unsigned int exp:8;
	unsigned int sign:1;
}demoted_t;

//Declaring the bit printing function
void print_bits(unsigned int, int);

int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variable
	float f;
	int n, d_value;

	//Prompt + read the value
	printf("Enter a float number: ");
	scanf("%f", &f);
	
	//Defining the structure pointer
	demoted_t *p = (demoted_t *)&f;
	
	//Calling the bit printing function
	print_bits(p->sign, 1);
	print_bits(p->exp, 8);
	print_bits(p->mantissa, 23);
	
	//Demoting float to int
	if (f > 1.0 || f < -1.0)
	{
		n = p->exp - 127;
		d_value = (p->mantissa >> (23 - n)) | (1 << n);
	}
	else
	{
		d_value = 0;
	}

	//Display the result
    printf("Demoted value: %d\n", d_value);

    return 0;

}

//Defining the bit printing funtion
void print_bits(unsigned int num, int n)
{
	unsigned mask = 1 << (n - 1);
	for ( ; mask; mask >>= 1)
	{
		num & mask ? putchar('1') : putchar('0');
	}
	putchar('\n');
}
