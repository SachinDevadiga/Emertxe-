/*	
		Title:  Calculate Mean
		Author: Sachin Devadiga
		Date:   24/06/2019 19:25 IST
		Description: Program to calculate mean of different datatypes and display the result. 
			          Input specifications: array: Variable to hold the array elements
				      Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

//Declare the mean function
float s_mean(void *, int);
float i_mean(void *, int);
float f_mean(void *, int);
double d_mean(void *, int);

int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables here
	int select, size, i;
	char option;

	do
	{
		//Prompt + read the selection
		printf("Select an option:\n1.short int\n2.int\n3.float\n4.double\n");
		scanf("%d", &select);

		switch(select)
		{
			case 1: 
					//Prompt + read the size of the array
					printf("Enter the size of the array: ");
					scanf("%d", &size);
					//Allocating the array memory
					short *array = malloc(size * sizeof(short));
					float p;
					//Prompt + read the values of the array
					printf("Enter the values of the array: ");
					for (i = 0; i < size; i++)
					{
						scanf("%hd", &array[i]);
					}
					//Calling the mean function
					p = s_mean(array, size);
					//Display the result
					printf("Mean of the array: %f\n", p);
					break;

			case 2: 
					//Prompt + read the size of the array
					printf("Enter the size of the array: ");
					scanf("%d", &size);
					//Allocating the array memory
					int *i_array = malloc(size * sizeof(int));
					float i_p;
					//Prompt + read the values of the array
					printf("Enter the values of the array: ");
					for (i = 0; i < size; i++)
					{
						scanf("%d", &i_array[i]);
					}
					//Calling the mean function
					i_p = i_mean(i_array, size);
					//Display the result
					printf("Mean of the array: %f\n", i_p);
					break;

			case 3: 
					//Prompt + read the size of the array
					printf("Enter the size of the array: ");
					scanf("%d", &size);
					//Allocating the array memory
					float *f_array = malloc(size * sizeof(float));
					float f_p;
					//Prompt + read the values of the array
					printf("Enter the values of the array: ");
					for (i = 0; i < size; i++)
					{
						scanf("%f", &f_array[i]);
					}
					//Calling the mean function
					f_p = f_mean(f_array, size);
					//Display the result
					printf("Mean of the array: %f\n", f_p);
					break;

			case 4: 
					//Prompt + read the size of the array
					printf("Enter the size of the array: ");
					scanf("%d", &size);
					//Allocating the array memory
					double *d_array = malloc(size * sizeof(double));
					double d_p;
					//Prompt + read the values of the array
					printf("Enter the values of the array: ");
					for (i = 0; i < size; i++)
					{
						scanf("%lf", &d_array[i]);
					}
					//Calling the mean function
					d_p = d_mean(d_array, size);
					//Display the result
					printf("Mean of the array: %lf\n", d_p);
					break;

			default:
					printf("Inavlid entry.. Please choose between option 1 and option 4\n");
					return 0;
		}

		//Prompt if the program is to be repeated
		printf("Do you wish to continue.. Press [Yy | Nn]: ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
}

//Defining the short mean function
float s_mean(void *a, int n)
{
	int i;
	short sum = 0;
	float mean;

	for (i = 0; i < n; i++)
	{
		sum += *((short *)a + i);
	}

	mean = (float)sum / n;
	return mean;
}
//Defining the int mean function
float i_mean(void *a, int n)
{
	int i, sum = 0;
	float mean;

	for (i = 0; i < n; i++)
	{
		sum += *((int *)a + i);
	}

	mean = (float)sum / n;
	return mean;
}
//Defining the float mean function
float f_mean(void *a, int n)
{
	int i;
	float mean, sum = 0;

	for (i = 0; i < n; i++)
	{
		sum += *((float *)a + i);
	}

	mean = sum / n;
	return mean;
}
//Defining the double mean function
double d_mean(void *a, int n)
{
	int i;
	double mean, sum = 0;

	for (i = 0; i < n; i++)
	{
		sum += *((double *)a + i);
	}

	mean = sum / n;
	return mean;
}
