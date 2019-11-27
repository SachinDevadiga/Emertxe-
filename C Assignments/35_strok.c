
#include <stdio.h>
#include <string.h>

//Declare the function
char *my_strtok(char *, char *);
//Start of main function
int main()
{
	//Declare the variable
	char option;
	do
	{
		char str1[80], str2[80];

		//Prompt the user to Enter the strings
		printf("Enter the 1st string: ");
		scanf("%[^\n]%*c", str1);
		printf("Enter the 2nd string: ");
		scanf("%[^\n]%*c", str2);

		//Call the function
		char *token = my_strtok(str1, str2);

		while (token != NULL)
		{
			//Print the result
			printf("%s\n", token);
			token = my_strtok(NULL, str2);
		}
		printf("Want to try again...Press[Yy | Nn]: ");
		scanf("\n%c", &option);
		getchar();
	} while (option == 'Y' || option == 'y');
}

//Define the function
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
