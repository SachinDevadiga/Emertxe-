/* 
		Title:  STRTOK
		Author: Sachin Devadiga
		Date:   20/06/2019 11:25 IST
		Description: Program to implement strtok function and display the result. 
			          Input specifications: string1, string2: Variable to hold the entered string values
				      Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declare the function
char *my_strtok(char *, char *);

int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables here
	char *string1 = malloc(50 * sizeof(char));
	char *string2 = malloc(20 * sizeof(char));
	char option;

	do
	{
		//Prompt + read the strings
		printf("Enter string1 content: ");
		scanf("%s", string1);

		printf("Enter string2(De-limiters): ");
		scanf("%s", string2);

		//Calling the strtok function and printing the output for the first element
		char *token = my_strtok(string1, string2);
		printf("%s\n", token);

		//Calling the strtok function to print the other elements of string1
		while (token != NULL)
		{
			printf("%s\n", token);
			token = my_strtok(NULL, string2);
		}

		//Prompt if the program is to be repeated
		printf("Do you wish to continue.. Press [Yy | Nn]: ");
		scanf("\n%c", &option);

	}while (option == 'Y' || option == 'y');

}
char *my_strtok(char *str1, char *str2)
{
	//Declare the variable
	int j = 0;
	static int i;
	static char *temp;
	int length = i;
	if (str1 != NULL)
	{
		temp = str1;
	}
	while (temp[i] != '\0')
	{
		j = 0;
		while (str2[j] != '\0')
		{
			//Checking for delimiter
			if (str2[j] == temp[i])
			{
				temp[i] = '\0';
				i++;
				if (temp[length] != '\0')
				{
					return (&temp[length]);
				}
				else
				{
					length = i;
					i--;
					break;
				}
			}
		j++;
		}
		i++;
	}
	if (temp[length] == '\0')
	{
		i = 0;
		return NULL;
	}
	else
	{
		return (&temp[length]);
	}
}

