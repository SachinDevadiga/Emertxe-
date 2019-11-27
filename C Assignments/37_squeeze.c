/*
     Title:  String Squeeze
     Author: Sachin Devadiga
     Date:   21/06/2019 15:25 IST
     Description: Program to perform squeeze operation on a string and display the result. 
                  Input specifications: string1, string2: Pointer variables to hold the entered string values
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declare the function
void squeeze(char *, char *);

int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables 
	char *string1 = malloc(10 * sizeof(char));
	char *string2 = malloc(10 * sizeof(char));
	char option;

	do
	{
		//Prompt + Read string 1
		printf("Enter String 1: ");
		scanf("%[^\n]s", string1);
		getchar();

		//Prompt + Read string 2
		printf("Enter String 2: ");
		scanf("%[^\n]s", string2);

		//Calling the squeeze function
		squeeze(string1, string2);

		//Display the output post squeeze operation
		printf("String 1 post squeeze: %s\n", string1);

		//Prompt if the program is to be repeated
		printf("Do you wish to continue.. Press [Yy | Nn]: ");
		scanf("\n%c", &option);
		getchar();

	}while (option == 'Y' || option == 'y');
	return 0;
}

//Defining the squeeze function
void squeeze(char *str1,char *str2)
{
	int i, j, k = 0;

	for (i = 0; *(str1 + i) != '\0'; i++)
	{
		//Logic where any matched position characters will be skipped, thereby removing the charaters in string 1
		for (j= 0; (*(str1 + i) != *(str2 + j)) && (*(str2 + j) != '\0'); j++);
		if (*(str2 + j) == '\0')
		{
			*(str1 + (k++)) = *(str1 + i);
		}
	}
	*(str1 + k) = '\0';
}
