/*
     Title:  Variance
     Author: Sachin Devadiga
     Date:   23/06/2019 12:25 IST
     Description: Program to find variance of the entered array and display the result. 
                  Input specifications: n: Variable to hold the entered integer number
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

//Declare the function
void populate (int *, int);
int sum(int *, int n);
void d(int *p, int n, int mean);
int Variance(int *p, int n);

int main()

{
	//Clear the output screen
	system("clear");

	//Declare the variables
	unsigned int n, avg, choice, total, mean, meanvar;
	char option;

	do
	{
		//Prompt + read the value
		printf("Enter the size: ");
		scanf("%d", &n);

		//Declare the array
		int a[n]; //Static acclocation
		int *b; //Dynamic allocation

		//Prompt to select the choice
		printf("Enter your choice:\n 1.Static\n 2.Dynamic\n");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				//Calling the function for populating the array
				populate(a,n);
				
				//Calling the function to add the elements of the array
				total = sum(a,n);

				//Displaying the total
				printf("%d\n", total);
				
				//Displaying the mean
				mean = total/(sizeof(a)/sizeof(a[0]));
				printf("Your Mean value : \n");
				printf("%d\n", mean);

				//Calling the function for D populating array
				d(a,n,mean);

				//Calling the variance function
				avg = Variance(a,n);
				printf("Your average for variance:\n");

				//Displaying the Variance
				meanvar= avg/(sizeof(a)/sizeof(a[0]));
				printf("%d\n", meanvar);
				break;

			case 2:
				//Dynamically allocating the memory
				b = (int *)malloc(n * sizeof(int));
				//Populating the array
				populate(b, n);

				//Calling the function to add the elements of the array
				total = sum(b,n);
				printf("%d\n", total);
				mean = total/n;
			
				//Displaying the mean value
				printf("Your Mean value : \n");
				printf("%d\n", mean);
				
				//Calling the function for D populating array
				d(b,n,mean);
				//Calling the variance function
				avg = Variance(b,n);
				printf("Your average for variance:\n");
				meanvar= avg/n;
				printf("%d\n", meanvar);
				break;

			default:
				printf("Invalid\n");
		}

		//Displaying for selecting the options whether to continue or not
		printf("Do you wish to continue... Press [Yy | Nn]: ");
		scanf("\n%c", &option);
	}
	//Condition for selecting the options whether to continue or not
	while (option == 'Y' || option == 'y');

}

//Populating the array
void populate(int *p, int n)
{
	int i;
	printf("Enter your values: \n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", p++);
	}
}


//Defining the sum function of the values in the array
int sum(int *p, int n)
{
	int sum = 0;
	int i;
	printf("sum of the arrays: \n");
	for (i = 0; i < n; i++)
	{
		sum += *(p++);
	}
	return sum;
}

//Defining the D function
void d(int *p, int n, int mean)
{
	printf("Array values minus mean:\n");
	int i, value[n];
	for (i = 0; i < n; i++)
	{
		*(p+i) = *(p + i) - mean;
		printf("%d", *(p + i));
		printf("\n");
	}

	//Printing for Summation of d2 
	printf("Summation of d2: \n");
	for (i = 0; i < n; i++)
	{
		*(p + i) = (*(p + i)) * (*(p + i));
		printf("%d\n", *(p + i));
	}
}

//Sum of the variance values
int Variance(int *p, int n)
{
	int i;
	int summation;
	for (i = 0; i < n; i++)
	{
		summation += *(p++);
	}
	return summation;
}

