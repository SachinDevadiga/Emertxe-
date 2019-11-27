/*
     Title:  Generic Search
     Author: Sachin Devadiga
     Date:   25/06/2019 15:25 IST
     Description: Program to find the entered key in the array and display the result. 
                  Input specifications: array: Array to hold the entered integer numbers
										key: Variable to hold the entered key value
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

//Declare the functions
void c_sort(void *, int);
void c_binary_search(void *, int, char);
void i_sort(void *, int);
void i_binary_search(void *, int, int);
void f_sort(void *, int);
void f_binary_search(void *, int, float);
void d_sort(void *, int);
void d_binary_search(void *, int, double);

int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables
	int i, size, select;
	char key1;
	int key2;
	float key3;
	double key4;
	char *array;
	int *array1;
	float *array2;
	double *array3;

	char option;

	do
	{
		//Prompt + read the selection
		printf("Select the type of array:\n1.Character\n2.Integer\n3.Float\n4.Double\n");
		scanf("%d", &select);
		//Prompt + read the size of the array
		printf("Enter the size of the array: ");
		scanf("%d", &size);

		switch(select)
		{
			
			case 1:
				//Define the allocation of memory to the array during runtime
				array = (char *)malloc(size * sizeof(char));
				//Prompt + read the values of the array
				printf("Enter the array elements: ");
				for (i = 0; i < size; i++)
				{
					scanf("%c", array + i);
				}

				//Calling the sorting funtion
				c_sort(array, size);

				//Display the sorted array
				printf("Sorted array: ");
				for (i = 0; i < size; i++)
				{
					printf("%c ", *((char *)(array + i)));
				}

				//Prompt + read the key value
				printf("\nEnter the key value: ");
				scanf("%c", &key1);

				//Calling the binary search function
				c_binary_search(array, size, key1);
				break;



			case 2:
				//Define the allocation of memory to the array during runtime
				array1 = (int *)malloc(size * sizeof(int));
				//Prompt + read the values of the array
				printf("Enter the array elements: ");
				for (i = 0; i < size; i++)
				{
					scanf("%d", array1 + i);
				}

				//Calling the sorting funtion
				i_sort(array1, size);

				//Display the sorted array
				printf("Sorted array: ");
				for (i = 0; i < size; i++)
				{
					printf("%d ", *(array1 + i));
				}

				//Prompt + read the key value
				printf("\nEnter the key value: ");
				scanf("%d", &key2);

				//Calling the binary search function
				i_binary_search(array1, size, key2);
				break;

			case 3:
				//Define the allocation of memory to the array during runtime
				array2 = (float *)malloc(size * sizeof(float));
				//Prompt + read the values of the array
				printf("Enter the array elements: ");
				for (i = 0; i < size; i++)
				{
					scanf("%f", array2 + i);
				}

				//Calling the sorting funtion
				f_sort(array2, size);

				//Display the sorted array
				printf("Sorted array: ");
				for (i = 0; i < size; i++)
				{
					printf("%f ", *(array2 + i));
				}

				//Prompt + read the key value
				printf("\nEnter the key value: ");
				scanf("%f", &key3);

				//Calling the binary search function
				f_binary_search(array2, size, key3);
				break;

			case 4:
				//Define the allocation of memory to the array during runtime
				array3 = (double *)malloc(size * sizeof(double));
				//Prompt + read the values of the array
				printf("Enter the array elements: ");
				for (i = 0; i < size; i++)
				{
					scanf("%lf", array3 + i);
				}

				//Calling the sorting funtion
				d_sort(array3, size);

				//Display the sorted array
				printf("Sorted array: ");
				for (i = 0; i < size; i++)
				{
					printf("%lf ", *(array3 + i));
				}

				//Prompt + read the key value
				printf("\nEnter the key value: ");
				scanf("%lf", &key4);

				//Calling the binary search function
				d_binary_search(array3, size, key4);
				break;

		default:
				printf("Invalid entry... Please select option between 1 and 4\n");
				return 0;
		}
		//Prompt if the program is to be repeated
		printf("Do you wish to continue... Press [Yy | Nn]: ");
		scanf("\n%c", &option);

	}while (option == 'Y' || option == 'y');
}

//Defining the sort function
void c_sort(void *a, int lim)
{
	int temp, i, j;
	
	for (i = 0; i < lim; i++)
	{
		for (j = 0; j < lim; j++)
		{
			if (*((char *)a + i) < *((char *)a + j))
			{
				temp = *((char *)a + i);
				*((char *)a + i) = *((char *)a + j);
				*((char *)a + j) = temp;
			}
		}
	}
}

//Defining the binary search function
void c_binary_search(void *a, int lim, char key)
{
	int begin = 0;
	int end = lim - 1;
	int mid;

	while (begin <= end)
	{	
		mid = (begin + end) / 2;

		if (key > *((char *)a +mid))
		{
			begin = mid + 1;
		}
		else if (key < *((char *)a + mid))
		{
			end = mid - 1;
		}
		else
		{
			printf("Key found at %d\n", mid + 1);
			return;
		}
	}
}

//Defining the sort function
void i_sort(void *a, int lim)
{
	int temp, i, j;
	
	for (i = 0; i < lim; i++)
	{
		for (j = 0; j < lim; j++)
		{
			if (*((int *)a + i) < *((int *)a + j))
			{
				temp = *((int *)a + i);
				*((int *)a + i) = *((int *)a + j);
				*((int *)a + j) = temp;
			}
		}
	}
}

//Defining the binary search function
void i_binary_search(void *a, int lim, int key)
{
	int begin = 0;
	int end = lim - 1;
	int mid;

	while (begin <= end)
	{	
		mid = (begin + end) / 2;

		if (key > *((int *)a +mid))
		{
			begin = mid + 1;
		}
		else if (key < *((int *)a + mid))
		{
			end = mid - 1;
		}
		else
		{
			printf("Key found at %d\n", mid + 1);
			return;
		}
	}
}
//Defining the sort function
void f_sort(void *a, int lim)
{
	int temp, i, j;
	
	for (i = 0; i < lim; i++)
	{
		for (j = 0; j < lim; j++)
		{
			if (*((float *)a + i) < *((float *)a + j))
			{
				temp = *((float *)a + i);
				*((float *)a + i) = *((float *)a + j);
				*((float *)a + j) = temp;
			}
		}
	}
}

//Defining the binary search function
void f_binary_search(void *a, int lim, float key)
{
	int begin = 0;
	int end = lim - 1;
	int mid;

	while (begin <= end)
	{	
		mid = (begin + end) / 2;

		if (key > *((float *)a +mid))
		{
			begin = mid + 1;
		}
		else if (key < *((float *)a + mid))
		{
			end = mid - 1;
		}
		else
		{
			printf("Key found at %d\n", mid + 1);
			return;
		}
	}
}
//Defining the sort function
void d_sort(void *a, int lim)
{
	int temp, i, j;
	
	for (i = 0; i < lim; i++)
	{
		for (j = 0; j < lim; j++)
		{
			if (*((double *)a + i) < *((double *)a + j))
			{
				temp = *((double *)a + i);
				*((double *)a + i) = *((double *)a + j);
				*((double *)a + j) = temp;
			}
		}
	}
}

//Defining the binary search function
void d_binary_search(void *a, int lim, double key)
{
	int begin = 0;
	int end = lim - 1;
	int mid;

	while (begin <= end)
	{	
		mid = (begin + end) / 2;

		if (key > *((double *)a +mid))
		{
			begin = mid + 1;
		}
		else if (key < *((double *)a + mid))
		{
			end = mid - 1;
		}
		else
		{
			printf("Key found at %d\n", mid + 1);
			return;
		}
	}
}
