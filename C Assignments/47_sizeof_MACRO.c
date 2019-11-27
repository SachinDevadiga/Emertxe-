/*
     Title:  Sizeof using MACRO
     Author: Sachin Devadiga
     Date:   9/07/2019 23:25 IST
     Description: Program to write a MACRO that performs the same operation as sizeof operator and display the result. 
                  Input specifications: Predefined in the program with a constant value
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>

//Defining the MACRO
#define SIZEOF(x) (char *)(&x + 1) - (char *) &x

int main()
{	
	//Declaring the variales that are of the required data type
	int a;
	double d;

	//Displaying the result 
	printf("Sizeof(int): %zu\n", SIZEOF(a));
	printf("Sizeof(double): %zu\n", SIZEOF(d));

	return 0;
}
