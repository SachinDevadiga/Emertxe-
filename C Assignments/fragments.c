
#include <stdio.h>
#include <stdlib.h>
//Declaring functions
void populate(float **aptr, int rows, int *num);
void mean_array(float **aptr, int rows, int *num, float **address, int *elements);
void print_array(float **aptr, int rows, int *num);
//Starting main
int main()
{

	//Declaring the variables 
	char option;
	int rows, i, status;
	float **array;
	do
	{
		//Clear the screen
		system("clear");
		//Enter the number of rows or 1d arrays and store it in the variable
		printf("Enter number of arrays : ");
		status = scanf("%d", &rows);
		if (status != 1)
		{
			printf("Invalid input\n");
			return 0;
		}
		array = malloc(rows * sizeof(float *)); 
		int num[rows], row_elements[rows];
		//Enter number of elements in each row and allocating memory dynamically
		for(i = 0; i < rows; i++)
		{
			printf("Enter number of elements in %d array : ", i + 1);
			scanf("%d", num + i);
			//Allocate memory for num[i] + 1 elements
			array[i] = malloc((num[i] + 1) * sizeof(float));
		}
		float **address = calloc(rows, sizeof(float *)); 
		for(i = 0; i < rows; i++)
		{
			address[i] = NULL;
		}
		for(i = 0; i < rows; i++)
		{
			row_elements[i] = num[i];
		}
		for(i = 0; i < rows; i++)
		{
			address[i] = *(array + i);
		}
		//Calling populating function to read elements in array
		populate(array, rows, num);
		//Finding the mean of elements in each row and store in the last block
		//Sorting the each row according to the mean of each row elements
		//Calling the function mean_array
		mean_array(array, rows, num, address, row_elements);
		//Printing original array
		printf("\nOriginal array\n");
		print_array(array, rows, num);
		//Printing the output according to ascending order of mean
		printf("\nAfter sorting\n");
		print_array(address, rows, row_elements);
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
//Defining the print_array function
void print_array(float **aptr, int rows, int *num)
{
	int i, j;
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < *(num + i); j++)
		{
			printf("%f\t", *(*(aptr + i) + j));
		}
		printf("\n");
	}
}
//Defining the populate function
void populate(float **aptr, int rows, int *num)
{
	int i, j;
	for(i = 0; i < rows; i++)
	{
		printf("Enter elements in ARRAY %d\n", i + 1);
		for (j = 0; j < *(num + i) - 1; j++)
		{
			scanf("%f", (*(aptr + i) + j));
		}
	}
}
//Defining mean_array function to fing mean in each row and sorting the each rows
void mean_array(float **aptr, int rows, int *num, float **address, int *elements)
{
	int i, j, temp_num, flag;
	float sum, *temp = NULL;
	for(i = 0; i < rows; i++)
	{
		sum = 0;
		for (j = 0; j < *(num + i) - 1; j++)
		{
			sum += *(*(aptr + i) + j);
		}
		//Finding the mean of each row
		*(*(aptr + i) + (*(num + i) - 1)) = sum / (*(num + i) - 1);
		//	printf("%f\n", *(*(aptr + i) + (*(num + i) - 1)));
	}
	//Sorting the array 
	for(i = 0; i < rows; i++)
	{
		for (j = 0; j < rows - i - 1; j++)
		{
			//Swapping the addresses
			if(*(*(address + j) + (*(elements + j)-1)) > *(*(address + j + 1) + (*(elements + j + 1)-1))) 
			{
				temp = (*(address + j));
				(*(address + j)) = (*(address + j + 1));
				(*(address + j + 1)) = temp;
				flag = *(elements + j);
				//Swapping the number of elements in each row
				*(elements + j) = *(elements + j + 1);
				*(elements + j + 1) = flag;
			}
		}
	}
}
