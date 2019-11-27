/*
     Title:  Sort Names
     Author: Sachin Devadiga
     Date:   10/06/2019 12:25 IST
     Description: Program to sort names in alphabetical order and display the result. 
                  Input specifications: array: Variable to hold the entered strings
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

//Declaring the functions
void sorting(char (*)[], int);
void my_strcpy(char *str1, char *str2);
int my_strcmp(char *str1, char *str2);

int main()
{
	//Clear the output screen
	system("clear");

	//Declaring the variables 
	int rows, i, status;
	char option;
	do
	{
		//Enter the number of strings and store it in the variable
		printf("Enter number of strings : ");
		status = scanf("%d", &rows);

		//Validating the entered value
		if (status != 1)
		{
			printf("Invalid input\n");
			return 0;
		}
		//Declaring array of strings
		char array[rows][50];

		//Enter the strings one by one
		printf("Enter %d strings\n", rows);
		for(i = 0; i < rows; i++)
		{
			scanf("%s", *(array + i));
		}
		//Calling sorting function
		sorting(array, rows);
	
		//Printing the names after sorting
		printf("\nAfter sorting\n\n");
		for(i = 0; i < rows; i++)
		{
			printf("%s\n", *(array + i));
		}
		printf("Do you wish to continue...Press [Yy | Nn]: ");
		scanf("\n%c", &option);

	}while (option == 'Y' || option == 'y');
	return 0;
}

//Defining sorting function
void sorting(char (*array)[50], int rows)
{
	int i, j;
	char temp[50];
	for (i = 0; i < rows; i++)
	{
		for (j = i + 1; j < rows; j++)
		{
			//Comapring each string
			if (my_strcmp(array[i], array[j]) > 0)
			{
				//Swapping the strings
				my_strcpy(temp,array[i]);
				my_strcpy(array[i], array[j]);
				my_strcpy(array[j], temp);
			}
		}
	}
}
//Defining my_strcpy function 
void my_strcpy(char *str1, char *str2)
{
	char temp[50] = {'\0'};
	int index = 0;
	
	//Copying character by character
	while (str2[index] != '\0')
	{
		str1[index] = str2[index];
		index++;
	}
	str1[index] = '\0';
}
//Defining my_strcmp function
int my_strcmp(char *str1, char *str2)
{
    while( (*str1 != '\0' && *str2 != '\0' ) && *str1 == *str2)
    {
        str1++;
        str2++;
    }

    if(*str1 == *str2)
    {
        return 0; // strings are identical
    }

    else
    {
        return *str1 - *str2;
    }
}
