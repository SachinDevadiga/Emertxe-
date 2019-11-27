/*
     Title:  Endianess
     Author: Sachin Devadiga
     Date:   9/07/2019 23:25 IST
     Description: Program to find the endianess of the processor and display the result. 
                  Input specifications: Predefined in the program with a constant value
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

//Defining the type of the datastructure used
typedef union
{
	int a;
	unsigned char b;
}endian_t;

int main()
{	
	//Defining a pointer variable to access the location in the union
	endian_t *x = malloc(1 * sizeof(endian_t));

	//Inserting a four byte value to the integer variable
	x->a = 0x1A2B3C8D;

	//Retreiving the first byte from the memory to check the endianess of the processor
	if (x->b == 0x8D)
	{	
		printf("Little endian\n");
	}
	else
	{
		printf("Big endian\n");
	}
	return 0;
}
