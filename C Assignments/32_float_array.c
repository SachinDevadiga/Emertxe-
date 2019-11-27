#include<stdio.h>
#include<stdlib.h>

//Declaring the function
void sort(float *p, int);

int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables
	int i, num, status;
	char option;

	do
	{
		//Prompt the user to enter th size of an array
		printf("Enter the size of array: ");
		scanf("%d", &num);
		float *a = malloc(num * sizeof(float));
		//Prompt + Read the value of array items
		printf("Enter the array items:\n");
		for (i = 0; i < num; i++)
		{
			scanf("%f", (a + i));
		}

		//Display the result
		sort(a, num);

		//Prompt if the program is to be repeated
		printf("\nDo you wish to continue.. Press [Yy | Nn]: ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
}

//Defining the sorting function
void sort(float *p, int num)
{
	float *ptr[num];
	float *temp;
	int i, j;

	for (i = 0; i < num; i++)
	{
		ptr[i] = &p[i];
	}

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (p[j] > p[j + 1])
			{
				temp = ptr[j + 1];
				ptr[j + 1] = ptr[j];
				ptr[j]= temp;
			}
		}
	}

	printf("Sorted values: ");
	for (i = 0; i < num; i++)
	{
		printf("%f ", *(ptr[i]));
	}
}


