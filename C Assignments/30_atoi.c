/*
     Title:  ASCII to Integer 
     Author: Sachin Devadiga
     Date:   19/06/2019 18:25 IST
     Description: Program to perform atoi and itoa operations and display the result. 
                  Input specifications: Enter strings or Integer values
                  Output specifications: Display the result
*/
/*-----------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declare the functions
int my_atoi(const char*);
char *itoa(int);
size_t getword(const char*);
void reverse(char *p, int n);
int digit(int ch);

int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variable here
	int num, choice, status;
	char string[100];
	char option;

	do
	{
		//Prompt + read the seleted option
		printf("Select the option:\n1.atoi\n2.itoa\n3.getword\n");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
					//Prompt + read the value
					printf("Enter a numeric string: ");
					scanf("%s", string);
					num = my_atoi(string);
					printf("Result is %d\n", num);
					break;

			case 2:
					//Prompt + read the value
					printf("Enter a numeric string: ");
					status = scanf("%d", &num);
					if (status != 1)
					{
						printf("Enter a number\n");
						return 0;
					}
					char *ch = itoa(num);
					printf("Result is %s\n", ch);
					break;

			case 3:
					//Prompt + read the value
					printf("Enter a numeric string: ");
					getchar();
					scanf("%[^\n]s", string);
					size_t length = getword(string);
					printf("String Length is %zu\n", length);
					break;

			default:
					printf("Invalid entry.. Please select between 1 - 3\n");
					return 0;
		}
		//Prompt if the program is to be repeated
		printf("Do you wish to continue..Press[Yy | Nn]: ");
		scanf("\n%c", &option);

	}while (option == 'Y' || option == 'y');
}

//Defining the atoi function
int my_atoi(const char *str)
{
	int flag = 0;
	int num = 0;

	if (*(str + 0) == '-')
	{
		flag = 1;
		str++;
	}

	while (*str)
	{
		if (digit(*str))
		{
			num = num * 10 + (*str - '0');
		}
		else
		{
			num = 0;
		}
		str++;
	}
	
	if (flag)
	{
		num = num * (-1);
		return num;
	}
	return num;
}

//Defining the itoa function
 char *itoa(int num)
{
	static char a[10] = {'\0'};
	int i = 0;
	while (num)
	{
		a[i] = (num % 10) + '0';
		i++;
		num = num / 10;
	}
	size_t len = strlen(a);
	reverse(a, len);
	return a;
}
size_t getword(const char *str)
{
	//const char *p = str;
	size_t count = 0;
	while (*str++)
	{
		count++;
	}
	return count;
}
void reverse(char *p, int n)
{
	char *q = p + (n - 1);
	char temp;

	while (p <= q)
	{
		temp = *p;
		*p++ = *q;
		*q-- = temp;
	}
}
//Defining the digit function
int digit(int ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return 1;
	}
	return 0;
}

