/*
     Title:  NRPS
     Author: Sachin Devadiga
     Date:   04/07/2019 21:25 IST
     Description: Program to find non repeatative progressive sequence of entered characters and display the result. 
                  Input specifications: limit, length: Variable to hold the entered limit and length values.
										string: Variable to hold the enteered character string
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

//Declare the function
void NRPS(char *, int, int);

int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables
	int i, j, length, limit;
	char *string = (char *)malloc(50 * sizeof(char));
	char option;
	do
	{
		//Prompt + read the limit value
		printf("Enter the value of n: ");
		scanf("%d",&limit);

		//Prompt + read the distinct character length value
		printf("Enter the length: ");
		scanf("%d", &length);

		//Prompt + read the characters
		printf("Enter non-repeatative characters: ");
		for (i = 0; i < length ; i++)
		{
			scanf("\n%c", string + i);
		}

		//Validation to check if the entered characters are not repeatative
		for (i = 0; i < length; i++)
		{
			for (j = i + 1; j < length; j++)
			{
				if (string[j] == string[i])
				{
					printf("Characters are not distinct\n");
					return 0;
				}
			}
		}

		//Display the result
		printf("The NRPS sequence: ");

		//Calling the NRPS function
		NRPS(string, limit, length);

		//Prompt if the program is to be repeated
		printf("\nDo you wish to continue.. Press [Yy | Nn]: ");
		scanf("\n%c", &option);

	}while (option == 'Y' || option == 'y');
}

void NRPS(char *string, int lim, int len)
{
	int i, val = 0, count = 0;

	for (i = 0; i < lim; i++)
	{
		if (i % len == 0 && i != 0)
		{
			val++;
		}
		printf("%c", *(string + ((i + val) % len)));
	}
}
