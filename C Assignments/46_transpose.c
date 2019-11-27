/*
     Title:  Transpose
     Author: Sachin Devadiga
     Date:   10/06/2019 19:25 IST
     Description: Program to find the transpose of the matrix and display the product of entered matrix and transpose matrix. 
                  Input specifications: row, col: Variable to hold the entered row and column
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

//Declare the functions
void populate(int **, int, int);
void display(int **, int, int);
void transpose(int **, int **, int, int);
void multiply(int **, int **, int **, int, int, int);

int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables here
	int i, j, row, col, row1, col1;
	char option;

	do
	{
		//Prompt + read the row and column values
		printf("Enter the row and column size: ");
		scanf("%d%d", &row, &col);

		//Defining and allocating memory for the first matrix
		int **matrix1 = malloc(row * (sizeof(int *)));
		for (i = 0; i < row; i++)
		{
			*(matrix1 + i) = malloc(col * (sizeof(int)));
		}

		//Populate the matrix
		printf("Enter the array values:\n");
		populate(matrix1, row, col);

		//Display the matrix
		printf("Entered matrix:\n");
		display(matrix1, row, col);

		//Defining the row and column size of transpose matrix
		row1 = col;
		col1 = row;

		//Defining and allocating memory for the tranposed matrix
		int **matrix2 = malloc(row * sizeof(int *));
		for (i = 0; i < row1; i++)
		{
			*(matrix2 + i) = malloc (col1 * sizeof(int));
		}

		//Calling the transpose function
		transpose(matrix1, matrix2, row1, col1);

		//Display the matrix
		printf("Transposed matrix:\n");	
		display(matrix2, row1, col1);

		//Defining and allocating memory for the tranposed matrix
		int **result = malloc(row * sizeof(int *));
		for (i = 0; i < row; i++)
		{
			*(result + i) = malloc (col1 * sizeof(int));
		}
		//Calling the multiply function
		multiply(matrix1, matrix2, result, row, col1, col);

		//Display the matrix
		printf("Product matrix:\n");
		display(result, row, col1);

		//Prompt if the program is to be repeated
		printf("Do you wish to continue.. Press [Yy | Nn]: ");
		scanf("\n%c", &option);

	}while (option == 'Y' || option == 'y');
}

//Defining the populate function
void populate(int **array, int row, int col)
{
	int i, j;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			scanf("%d", (*(array + i) + j));
		}
	}

}

//Defining the display function
void display(int **matrix, int row, int col)
{
	int i, j;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d ", *(*(matrix + i) + j));
		}
		putchar('\n');
	}
}

//Defining the transpose function
void transpose(int **array, int **transpose, int row, int col)
{	
	int i, j;


	//Populating the elements of the transpose array
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			*(*(transpose + i) + j) = *(*(array + j) + i);
		}
	}
}

//Defining the matrix multiplication
void multiply(int **array, int **transpose, int **multiply, int row, int col1, int col)
{
	int i, j, k;


	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col1; j++)
		{
			*(*(multiply + i) + j) = 0;
			for (k = 0; k < col; k++)
			{
				*(*(multiply + i) + j) += (*(*(array + i) + k)) * (*(*(transpose + k) + j));
			}
		}
	}
}
