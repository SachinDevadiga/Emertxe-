/*
     Title:  Swapping using MACRO
     Author: Sachin Devadiga
     Date:   9/07/2019 23:25 IST
     Description: Program to write a MACRO that performs swapping and display the result. 
                  Input specifications: Predefined in the program with a constant value
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>

//Defining the MACRO
#define GENERIC_SWAP(a, b, type)	{	type temp = a;	\
										a = b;			\
										b = temp;		\
									}

int main()
{	
	//Defining the character variables to hold a char value and implementing swap using the MACRO name
	char c1 = 'A';
	char c2 = 'B';
	printf("Before swapping c1: %c\tc2: %c\n", c1, c2);
	
	GENERIC_SWAP(c1, c2, char);
	
	//Display the result post swapping
	printf("After swapping c1: %c\tc2: %c\n", c1, c2);
	
	putchar('\n');
	//Defining the integer variables to hold a integer value and implementing swap using the MACRO name
	int i1 = 10;
	int i2 = 20;
	printf("Before swapping i1: %d\ti2: %d\n", i1, i2);
	
	GENERIC_SWAP(i1, i2, int);

	//Display the result post swapping
	printf("After swapping i1: %d\ti2: %d\n", i1, i2);

	putchar('\n');
	//Defining the float variables to hold a float value and implementing swap using the MACRO name
	float f1 = 1.2;
	float f2 = 2.4;
	printf("Before swapping f1: %f\tf2: %f\n", f1, f2);
	
	GENERIC_SWAP(f1, f2, float);

	//Display the result post swapping
	printf("After swapping f1: %f\tf2: %f\n", f1, f2);

	putchar('\n');
	//Defining the double variables to hold a double value and implementing swap using the MACRO name
	double d1 = 23.345;
	double d2 = 34.456;
	printf("Before swapping d1: %lf\td2: %lf\n", d1, d2);
	
	GENERIC_SWAP(d1, d2, double);

	//Display the result post swapping
	printf("After swapping d1: %lf\td2: %lf\n", d1, d2);

	putchar('\n');
	//Defining the character pointer variables to hold the address of the string and implementing swap using the MACRO name
	char *p1 = "Good";
	char *p2 = "Bad";
	printf("Before swapping p1: %s\tp2: %s\n", p1, p2);
	
	GENERIC_SWAP(p1, p2, char *);

	//Display the result post swapping
	printf("After swapping p1: %s\tp2: %s\n", p1, p2);

	putchar('\n');
	return 0;
}
