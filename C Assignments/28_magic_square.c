/*
		Title:  Magic Square
		Author: Sachin Devadiga
		Date:   22/06/2019 12:25 IST
		Description: Program to display magic square for an entered input. 
			          Input specifications: n: Variable to hold the entered integer number
				      Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

//Declare the function
void magic_square(int **a, int);
int isvalid(int);

int main()
{
	//Clear the screen
	system("clear");

	//Declare the variables here
	int n, status;
	char option;

	do
	{
		//Prompt + read the matrix size
		printf("Enter the n value: ");
		status = scanf("%d", &n);

		if (isvalid(status) == 1 || (n % 2) != 1)
		{
			printf("Invalid entry.. Please enter an odd number\n");
			return 0;
		}

		//Allocating the memory for the matrix
		int **a = malloc(n * sizeof(int *));
		int i;
		for (i = 0; i < n; i++)
	{
			*(a + i) = malloc(n * sizeof(int));
		}

		//Calling the magic square function
		magic_square(a, n);

		//Prompt if the program is to be repeated
		printf("Do you wish to continue.. Press [Yy | Nn]: ");
		scanf("\n%c", &option);

	}while (option == 'Y' || option == 'y');

	return 0;
}

//Defining the magic square function
void magic_square(int **a, int n)
{
	int i, j, num;
	
	//Initialising the variables to point to the 1st row and centre column
	i = 0;
	j = (n - 1) / 2;
	
	//Logic to poplate the matrix
	for (num = 1; num <= (n * n); num++)
	{
		a[i][j] = num;
		i--;	/* move up */
		j++;	/* move right */
		if ((num % n) == 0)
		{
			i += 2; /* move to the bottom row from topmost row */
			j--;    /* move to the same column */
		}
		if (i == -1)
		{
			i = n - 1; /* move to the bottom row */
		}
		if (j == n)
		{
			j = 0;    /* move to the leftmost column */
		}
	}

	//Printing the matrix
	printf("Magic square matrix:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t", *(*(a + i) + j));
		}
		putchar('\n');
	}
}

//Defining the validation function
int isvalid(int status)
{
	if (status != 1)
	{
		return 1;
	}
	return 0;
}
