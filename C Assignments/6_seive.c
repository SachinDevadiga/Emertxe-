/*
     Title:  Prime number (Seive)
     Author: Sachin Devadiga
     Date:   10/06/2019 12:25 IST
     Description: Program to find prime numbers using Seive method and display the result. 
                  Input specifications: n: Variable to hold the entered integer number
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables
	int i, j, n, size, a[size];
	
	//Prompt + Read the array size
	printf("Enter the array size: ");
	scanf("%d", &n);

	//Incrementing the size by 1 to read upto the entered size 
	size = n + 1;
	
	//Assigning the index value to the array as item value
	for (i=0; i <= size; i++)
	{
		a[i] = i;
	}
	
	//Logic to obtain the prime numbers
	for (i = 2; i <= size / 2; i++)
	{
		for (j = i; j <= size; j++)
		{
			if ((j+1) % i == 0)
			{
				a[j+1] = 0;
			}
		}
	}
	
	//Displaying the result
	printf("Prime numbers are:\n");
	for (i = 2; i <= size; i++)
	{
		if (a[i] != 0)
		{
			printf("%d ", a[i]);
		}
	}
	putchar('\n');
}
