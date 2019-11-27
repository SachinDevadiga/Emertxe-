/*
     Title:  Median of Array
     Author: Sachin Devadiga
     Date:   11/06/2019 12:25 IST
     Description: Program to find the average of medians of given two arrays and display the result. 
                  Input specifications: a_lim: Variable to hold the entered integer number 
										b_lim: Variable to hold the entered integer number
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
	int i, j, a_lim, b_lim, temp, n, status;
	float a_median, b_median, Avg;
	char option;

	do
	{
		//Prompt + Read the size of array a
		printf("Enter size of array a: ");
		status = scanf("%d", &a_lim);

		//Validation to check if entered character is a number
		if (status != 1 || a_lim <= 0)
		{
			printf("Invalid entry.. Please enter a number above 0\n");
			return 0;
		}

		//Declare the array 
		int a[a_lim];

		//Prompt + Read the array a items
		printf("Enter array a items: ");
		for (i = 0; i < a_lim; i++)
		{
			status = scanf("%d", &a[i]);

			//Validation to check if entered character is a number
			if (status != 1)
			{
				printf("Invalid entry.. Please enter a number\n");
				return 0;
			}
		}

		//Logic to arrange the items in ascending order
		for (i = 0; i < a_lim; i++)
		{
			for (j= 0; j < a_lim; j++)
			{
				if (a[j] > a[j+1])
				{
					temp = a[j+1];
					a[j+1] = a[j];
					a[j] = temp;
				}
			}
		}

		//Print the re-arranged array
		printf("Arranged array a: { ");
		for (i = 0; i < a_lim; i++)
		{
			printf("%d ", a[i]);
		}
		printf("}");
		putchar('\n');

		//Logic to find median
		if (a_lim % 2)
		{
			n = (a_lim / 2);
			a_median = a[n];
		}
		else
		{
			n = a_lim / 2;
			a_median = (float)(a[n-1] + a[n]) / 2;
		}
		printf("Median of array a: %f\n", a_median);

		//Prompt + Read the size of array b
		printf("Enter size of array b: ");
		status = scanf("%d", &b_lim);

		//Validation to check if entered character is a number
		if (status != 1 || b_lim <= 0) 
		{
			printf("Invalid entry.. Please enter a number above 0\n");
			return 0;
		}
		//Declare the array 
		int b[b_lim];

		//Prompt + Read the array b items
		printf("Enter array b items: ");
		for (i = 0; i < b_lim; i++)
		{
			status = scanf("%d", &b[i]);

			//Validation to check if entered character is a number
			if (status != 1)
			{
				printf("Invalid entry.. Please enter a number\n");
				return 0;
			}
		}

		//Logic to arrange the items in ascending order
		for (i = 0; i < b_lim; i++)
		{
			for (j= 0; j < b_lim; j++)
			{
				if (b[j] > b[j+1])
				{
					temp = b[j+1];
					b[j + 1] = b[j];
					b[j] = temp;
				}
			}
		}
		//Print the re-arranged array
		printf("Arranged array b: { ");
		for (i = 0; i < b_lim; i++)
		{
			printf("%d ", b[i]);
		}
		printf("}");
		putchar('\n');

		//Logic to find median
		if (b_lim % 2)
		{
			n = (b_lim / 2);
			b_median = b[n];
		}
		else
		{
			n = b_lim / 2;
			b_median = (float)(b[n-1] + b[n]) / 2;
		}
		printf("Median of array b: %f\n", b_median);

		//Logic for average and print the result
		Avg = (a_median + b_median) / 2;
		printf("Average of medians is: %f\n", Avg);

		//Prompt to repeat the program
		printf("Do you wish to repeat.. Press [Yy|Nn]: ");
		scanf("\n%c", &option);
	}while (option == 'Y' | option == 'y');
}
