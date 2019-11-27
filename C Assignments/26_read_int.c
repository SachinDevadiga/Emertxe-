/* 
		Title:  Read_int
		Author: Sachin Devadiga
		Date:   02/07/2019 11:25 IST
		Description: Program to read integer value and display the result as a string. 
                  Input specifications: array: Variable to hold the entered integer number
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

//Declare the read_int function
int read_int(int *);
int digit(int ch);

int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables here
	int num;
	char option;

	do
	{

		//Prompt to enter the number
		printf("Enter a number: ");

		//Calling the read_int function
		read_int(&num);

		//Displaying the string of numbers
		printf("Number: %d\n", num);

		//Prompt if the program is to be repeated
		printf("Do you wish to continue... Press [Yy | Nn]: ");
		scanf("\n%c", &option);
		getchar();

	}while (option == 'Y' || option == 'y');
}

//Defining the read_int function
int read_int(int *num)
{
	int ch, flag = 0;
	*num = 0;

	while ((ch = getchar()) != '\n')
	{
		if (ch == '-')
		{
			flag = 1;
			ch = getchar();
		}
		//Calling the digit function to insert only numbers
		if (digit(ch))
		{
			*num = *num * 10 + (ch - '0');
		
		}
	}
	if (flag)
	{
		*num = *num * (-1);
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
