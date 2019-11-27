/*
Title       : 39_generic_search.c
Author      : Sandeep
Date        : 29 June 2019
Description : Executing binary search for int, char, float, and double data types
Input       : Array of numbers of specified datatype and key to found
Output      : Printing key is found or not
 */

#include <stdio.h>
#include <stdlib.h>

//Declaring search functions
void *my_searchi(const void *key, const void *base, size_t elements, size_t size, int (*funptr1)(const void *p, const void *q));
void *my_searchf(const void *key, const void *base, size_t elements, size_t size, int (*funptr2)(const void *p, const void *q));
void *my_searchc(const void *key, const void *base, size_t elements, size_t size, int (*funptr3)(const void *p, const void *q));
void *my_searchd(const void *key, const void *base, size_t elements, size_t size, double (*funptr4)(const void *p, const void *q));
//Declaring the compare functions for all datatypes
int comparei(const void *p, const void *q);
int comparef(const void *p, const void *q);
int comparec(const void *p, const void *q);
double compared(const void *p, const void *q);
//Declaring the sorting functions
void sorting_int(int *aptr, int elements);
void sorting_float(float *aptr, int elements);
void sorting_char(char *aptr, int elements);
void sorting_double(double *aptr, int elements);

//Starting main
int main()
{
	//Declare variables
	int choice, elements, i, key;
	float float_key;
	char char_key, option;
	double double_key;
	void *index;
	do
	{
		//Clear screen
		system("clear");
		//Prompt to select the data type and store in the variable
		printf("Select data type\n1.Int\n2.Float\n3.Char\n4.Double\n");
		scanf("%d", &choice);
		//Prompt + read the number of elements 
		printf("Enter number of elements to read\n");
		scanf("%d", &elements);
		//Declaring arrays
		int array[elements];
		char char_array[elements];
		float float_array[elements];
		double double_array[elements];
		switch(choice)
		{
			case 1:
				//Enter values in the array
				printf("Enter the %d int values\n", elements);
				for (i = 0; i < elements; i++)
				{
					scanf("%d", array+ i );
				}
				//Enter search key
				printf("Enter key\n");
				scanf("%d", &key);
				//Sorting the given array by calling sorting_int function
				sorting_int(array, elements);
				//Calling my_search function
				index = (int *)my_searchi(&key, array, sizeof(array) / sizeof(array[0]), sizeof(array[0]), comparei);
				//Printing the result
				if(index != NULL)
					printf("Key found\n");
				else
					printf("key not found\n");
				break;
			case 2:
				//Enter values in the array
				printf("Enter the %d float values\n", elements);
				for (i = 0; i < elements; i++)
				{
					scanf("%f", float_array + i);
				}
				//Enter search key
				printf("Enter key\n");
				scanf("%f", &float_key);
				//Calling the sorting_float function
				sorting_float(float_array, elements);
				//Calling my_search function
				index = (float *)my_searchf(&float_key, float_array, sizeof(float_array) / sizeof(float_array[0]), sizeof(float_array[0]), comparef);
				//Printing the result
				if(index != NULL)
					printf("Key found\n");
				else
					printf("key not found\n");
				break;
			case 3:
				//Enter values in the array
				printf("Enter the %d char values\n", elements);
				for (i = 0; i < elements; i++)
				{
					scanf("\n%c", char_array+ i );
				}
				//Enter search key
				printf("Enter key\n");
				scanf("\n%c", &char_key);
				//Calling the sorting_char function
				sorting_char(char_array, elements);
				//Calling my_search function
				index = (char *)my_searchc(&char_key, char_array, sizeof(char_array) / sizeof(char_array[0]), sizeof(char_array[0]), comparec);
				//Printing the result
				if(index != NULL)
					printf("Key found\n");
				else
					printf("key not found\n"); 
				break;
			case 4:
				//Enter values in the array
				printf("Enter the %d double values\n", elements);
				for (i = 0; i < elements; i++)
				{
					scanf("%lf", double_array+ i );
				}
				//Enter search key
				printf("Enter key\n");
				scanf("%lf", &double_key);
				//Sorting the array
				sorting_double(double_array, elements);
				//Calling my_search function
				index = (double *)my_searchd(&double_key, double_array, sizeof(double_array) / sizeof(double_array[0]), sizeof(double_array[0]), compared);
				//Printing the output
				if(index != NULL)
					printf("Key found\n");
				else
					printf("key not found\n");
				break;
			default:
				printf("Invalid choice\n");
		}
		printf("Do you want to continue? (y / n) : ");
		scanf("\n%c", &option);
	}while(option == 'y' || option == 'Y');
}
//Defining linear search function for int data type
void *my_searchi(const void *key, const void *base, size_t elements, size_t size, int (*funptr1)(const void *p, const void *q))
{
	int low = 0, high = elements - 1, mid, count = 0;
	//Applying binary search
	while (high >= low)
	{
		mid = (low + high) / 2;
		if (funptr1((int *)key, (int *)(base + mid * size)) < 0)
			high = mid - 1;
		else if (funptr1((int *)key, (int *)(base + mid * size)) == 0)
		{
			count = 1;
			break;
		}

		else
			low = mid + 1;
	}
	//Returning the address if any element is matching
	if (count == 1)
		return (int *)base + mid * size;
	else
		return NULL;
}
//Defining the compare function for int data type
int comparei(const void *p, const void *q)
{
	return (*(int *)p - *(int *)q);
}
//Sorting the integer array
void sorting_int(int *aptr, int elements)
{
	int temp;
	int i, j;
	for(i = 0; i < elements; i++)
	{
		for(j = 1; j < elements; j++)
		{
			if (aptr[i] > aptr[j])
			{
				temp = aptr[i];
				aptr[i] = aptr[j];
				aptr[j] = temp;
			}
		}
	}
}

//Defining linear search function for float data type
void *my_searchf(const void *key, const void *base, size_t elements, size_t size, int (*funptr2)(const void *p, const void *q))
{
	int low = 0, high = elements - 1, mid, count = 0;
	//Applying binary search
	while (high >= low)
	{
		mid = (low + high) / 2;
		if (funptr2((float *)key, (float *)(base + mid * size)) < 0)
			high = mid - 1;
		else if (funptr2((float *)key, (float *)(base + mid * size)) == 0)
		{
			count = 1;
			break;
		}
		else
			low = mid + 1;
	}
	//Returning the address if any element is matching
	if (count == 1)
		return (float *)base + mid * size;
	else
		return NULL;
}
//Defining the compare of two values for float data types
int comparef(const void *p, const void *q)
{
	return (*(float *)p - *(float *)q);
}
//Sorting the float array
void sorting_float(float *aptr, int elements)
{
	float temp;
	int i, j;
	for(i = 0; i < elements; i++)
	{
		for(j = 1; j < elements; j++)
		{
			if (aptr[i] > aptr[j])
			{
				temp = aptr[i];
				aptr[i] = aptr[j];
				aptr[j] = temp;
			}
		}
	}
}
//Defining linear search function for char data type
void *my_searchc(const void *key, const void *base, size_t elements, size_t size, int (*funptr3)(const void *p, const void *q))
{
	int low = 0, high = elements - 1, mid, count = 0;
	//Applying binary search
	while (high >= low)
	{
		mid = (low + high) / 2;
		if (funptr3((char *)key, (char *)(base + mid * size)) < 0)
			high = mid - 1;
		else if (funptr3((char *)key, (char *)(base + mid * size)) == 0)
		{
			count = 1;
			break;
		}

		else
			low = mid + 1;
	}
	//Returning the address if any element is matching
	if (count == 1)
		return (char *)base + mid * size;
	else
		return NULL;
}
//Defining the compare of two values for char data types
int comparec(const void *p, const void *q)
{
	return (*(char *)p - *(char *)q);
}
//Sorting the char_array
void sorting_char(char *aptr, int elements)
{
	char temp;
	int i, j;
	for(i = 1; i < elements; i++)
	{
		for(j = 0; j < elements - 1; j++)
		{
			if (aptr[j] > aptr[j+1])
			{
				temp = aptr[j];
				aptr[j] = aptr[j+1];
				aptr[j+1] = temp;
			}
		}
	}
}

//Defining linear search function for double data type
void *my_searchd(const void *key, const void *base, size_t elements, size_t size, double (*funptr4)(const void *p, const void *q))
{
	int low = 0, high = elements - 1, mid, count = 0;
	//Applying binary search
	while (high >= low)
	{
		mid = (low + high) / 2;
		if (funptr4((double *)key, (double *)(base + mid * size)) < 0)
			high = mid - 1;
		else if (funptr4((double *)key, (double *)(base + mid * size)) == 0)
		{
			count = 1;
			break;
		}

		else
			low = mid + 1;
	}
	//Returning the address if any element is matching
	if (count == 1)
		return (double *)base + mid * size;
	else
		return NULL;
}
//Defining the compare of two values for double data types
double compared(const void *p, const void *q)
{
	return (*(double *)p - *(double *)q);
} 
//Sorting the double_array
void sorting_double(double *aptr, int elements)
{
	double temp;
	int i, j;
	for(i = 1; i < elements; i++)
	{
		for(j = 0; j < elements - 1; j++)
		{
			if (aptr[j] > aptr[j+1])
			{
				temp = aptr[j];
				aptr[j] = aptr[j+1];
				aptr[j+1] = temp;
			}
		}
	}
}

