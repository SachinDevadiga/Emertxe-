#include<stdio.h>
#include<stdlib.h>

void populate(float **p, int *len);
void print(float **p, int *len);
void average(float **p, int *len);
void swap(float **p, int *len);

int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables here
	float **p = malloc(3 * sizeof(float*));
	int *len = malloc(3 * sizeof(int));
	int i, size;

	//Prompt + read the size 
	for (i = 0; i < 3; i++)
	{
		printf("Enter the size of p[%d]: ", i);
		scanf("%d", &size);
		*(p + i) =(float *) malloc((size + 1) * sizeof(float));
		*(len + i) = size;
	}

	//Populate the array
	populate(p, len);
	putchar('\n');
	//Display the output
	print(p, len);

	putchar('\n');
	//Obtain the average of the array elements
	average(p, len);
	
	putchar('\n');
	//Display average
	print(p, len);

	putchar('\n');
	//Calling the swap function
	swap(p, len);

	putchar('\n');
	print(p, len);

}

//Defining the populate function
void populate(float **p, int *len)
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		printf("Enter p[%d]items(%d): ", i, *(len + i));
		for (j = 0; j < (*(len + i)); j++)
		{
			scanf("%f", (*(p + i) + j));
		}
	}
}

//Defining the print function
void print(float **p, int *len)
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		printf("Entered p[%d] items(%d): ", i, *(len + i));
		for (j = 0; j <= (*(len + i)); j++)
		{
			printf("%f ", *(*(p + i) + j));
		}
		putchar('\n');
	}

}

//Defining the average function
void average(float **p, int *len)
{
	int i, j;
	float sum;

	for (i = 0; i < 3; i++)
	{
		sum = 0;

		for (j = 0; j < (*(len + i)); j++)
		{
			sum += (*(*(p + i) + j));
		}
		*(*(p + i) + j) = sum / (*(len + i));
	}
}

//Defining the swap function
void swap(float **p, int *len)
{
	int i, j;
	float *temp;

	for (i = 0; i < 3; i++)
	{
		for (j = i + 1; j < 3; j++)
		{
			if ( *(p[i] + (*(len + i))) > *(p[j] + (*(len + j))))
			{
				temp = *(p + i);
				 *(p + j) = *(p + i);
				*(p + i) = temp;
			}
		}
	}
}
