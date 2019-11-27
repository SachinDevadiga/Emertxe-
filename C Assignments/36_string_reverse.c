/*
     Title:  String Reverse
     Author: Sachin Devadiga
     Date:   20/06/2019 09:25 IST
     Description: Program to find the reverse of a string and display the result. 
                  Input specifications: str: Variable to hold the string
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declare the function
void reverse(char *, int, int);

int main()
{
	char str[10];
	int len;
	//char *str = malloc(sizeof(char));
	char option;

	do 
	{
		//Prompt + read the value
		printf("Enter a string: ");
		scanf("%[^\n]s", str);
		
		len = strlen(str) - 1;

		//Calling the reverse function
		reverse(str, 0, len);
		
		//Display the result
		printf("Reverse of string: %s", str);
		
		//Prompt if the program is to be repeated
		printf("\nDo you wish to continue..Press [Yy | Nn]: ");
		scanf("\n%c", &option);
		getchar();

	}while (option == 'Y' || option == 'y');
	
}

//Defining the reverse function
void reverse(char *str, int i, int len)
{
	char temp;

	if (i < len)
	{
	temp = *(str + i);
	*(str + i) = *(str + len);
	*(str + len) = temp;
	reverse(str, ++i, --len);
	}
	return;


}
