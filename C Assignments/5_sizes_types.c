/*
	Title:  Size of Data Types
    Author: Sachin Devadiga
    Date:   25/05/2019 22:40 IST
    Description: Program to display the sizes/memory space allocated to datatypes used in C. 
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>

int main()
{
	// The 'sizeof' keyword provides the memory allocated to the datatypes and the below statements prints the same to the output screen

	printf("Sizeof(char): %zu\n", sizeof(char)); //Print the size of memory allocated to 'char' data type
	printf("Sizeof(signed char): %zu\n", sizeof(signed char)); //Print the size of memory allocated to 'signed char' data type
	printf("Sizeof(unsigned char): %zu\n", sizeof(unsigned char)); //Print the size of memory allocated to 'unsigned char' data type
    
	printf("Sizeof(int): %zu\n", sizeof(int)); //Print the size of memory allocated to 'int' data type
	printf("Sizeof(signed int): %zu\n", sizeof(signed int)); //Print the size of memory allocated to 'signed int' data type
	printf("Sizeof(unsigned int): %zu\n", sizeof(unsigned int)); //Print the size of memory allocated to 'unsigned int' data type

	printf("Sizeof(short int): %zu\n", sizeof(short int)); //Print the size of memory allocated to 'short int' data type
	printf("Sizeof(long int): %zu\n", sizeof(long int)); //Print the size of memory allocated to 'long int' data type
	printf("Sizeof(long long int): %zu\n", sizeof(long long int)); //Print the size of memory allocated to 'long long int' data type

	printf("Sizeof(short unsigned int): %zu\n", sizeof(short unsigned int)); //Print the size of memory allocated to 'short unsigned int' data type
	printf("Sizeof(long unsigned int): %zu\n", sizeof(long unsigned int)); //Print the size of memory allocated to 'long unsigned int' data type
	printf("Sizeof(long long unsigned int): %zu\n", sizeof(long long unsigned int)); //Print the size of memory allocated to 'long long unsigned int' data type

	printf("Sizeof(float): %zu\n", sizeof(float)); //Print the size of memory allocated to 'float' data type
	printf("Sizeof(double): %zu\n", sizeof(double)); //Print the size of memory allocated to 'double' data type
	printf("Sizeof(long double): %zu\n", sizeof(long double)); //Print the size of memory allocated to 'long double' data type
	
	return 0;
}
