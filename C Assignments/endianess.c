/*
     Title:  Endianess
     Author: Sachin Devadiga
     Date:   9/07/2019 23:25 IST
     Description: Program to write a function to display the endianess. 
                  Input specifications: Predefined in the program with a constant value
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>

//Declaring the function
int check_endianess(unsigned int *location, char value);

int main()
{
	//Defining the variables
	unsigned x = 0x1A2B3C4D;
	char *c = (char *)&x;

	//Calling the endianess function and displaying the result
	if (check_endianess(&x, *c))
	{
		printf("Little endian\n");
	}
	else
	{
		printf("Big Endian\n");
	}

	return 0;
}

//Defining the endianess function
int check_endianess(unsigned int *location, char value)
{	
	if (value == *(char *)location)
	{
		printf("Value: %X\n", value);
		return 1;
	}
	return 0;
}
