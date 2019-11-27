/*
     Title:  Float Array
     Author: Sachin Devadiga
     Date:   10/06/2019 12:25 IST
     Description: Program to sort the array without modifying the values of the original array and display the result. 
                  Input specifications: limit: Variable to hold the entered size of the array
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

//Declare the function
void print_array(const float *ptr, int limit);

int main()
{
	//Declare the variables
	char option;

	do
	{
		int i, limit;
	
		//prompt the user for the limit of the array
		printf("Enter the Limit for an array: ");
		scanf("%d", &limit);
		
		//declare the array with limit user_entered
		float *array = malloc(limit * sizeof(float));
		
		//prompt the user for the float values of array
		puts("Enter the values of the array");
		for(i = 0; i < limit; i++)
		{
			scanf("%f", array + i);
		}
		//Calling the printing function
		print_array(array, limit);
		
		printf("\nDo you wish to continue... Press [Yy | Nn]: ");
		scanf("\n%c", &option);

	}while (option == 'Y' || option == 'y');

	return 0;
}

//Defining the array printing function
void print_array(const float *ptr, int limit)
{
	float min, max, temp = 0.0;

	//initialize the min and max value with first value of the array
	min = max = *ptr;

	int i, j;
	
	//find-out the maximum number and the minimum number from the array
	for(i = 0; i < limit ; i++)
	{
		if(*(ptr + i) < min)
		{
			min = *(ptr + i);
		}
		if(*(ptr + i) > max)
		{
			max = *(ptr + i);

		}
		
	}

	//Display the sorted floating values
	printf("The sorted values are: ");
	//printf the min value
	printf("%f ", min);

	//move the minimum value into the temp
	temp = max;

	//check for the number greater then temp and lesser then the maximum
	for(i = 0; i < limit - 2; i++)
	{	
		temp = max;
		for(j = 0; j < limit ; j++)
		{
			if ((*(ptr + j) < temp) && (*(ptr + j) > min))
			{
					temp = *(ptr + j);
			}

		}
				printf("%f ",temp);
				min = temp;
	}

	//print the maximum vlaue
	printf("%f ", max);
}
