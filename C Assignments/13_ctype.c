/*
     Title:  CType Library
     Author: Sachin Devadiga
     Date:   12/06/2019 12:25 IST
     Description: Program to check the entered character and display the result. 
                 Input specifications: ch: Variable to hold the entered character
                 Output specifications: Display the result
*/
/*----------------------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

//Declaring the functions
int Isalnum(int);
int Isalpha(int);
int Isascii(int);
int Isblank(int);

int main()
{
	//Declare the variables
	char ch, option;
	int num;

	do
	{
		//Prompt + Read the value
		printf("Enter a charater: ");
		scanf("%c", &ch);
		
		//Prompt to select an option
		printf("Please select an option\n1. Isalnum\n2. Isalpha\n3. Isascii\n4. Isblank\n");
		scanf("%d", &num);

		switch (num)
		{
			case 1:
					//Call Isalnum function and check the condition
					if (Isalnum(ch) == 0)
					{
						printf("Entered character is an Alphabet\n");
					}
					else if (Isalnum(ch) == 1) 
					{
						printf("Entered character is a Digit\n");
					}
					else
					{
						printf("Entered character is neither Alphabet or Digit\n");
					}
					break;

			case 2:
					//Call Isalpha function and check the condition
					if (Isalpha(ch) == 0)
					{
						printf("Entered character is an Alphabet in Upper case\n");
					}
					else if (Isalpha(ch) == 1) 
					{
						printf("Entered character is an Alphabet in Lower case\n");
					}
					else
					{
						printf("Entered character is not an Alphabet\n");
					}
					break;
			
			case 3:
					//Call Isascii function and check the condition
					if (Isascii(ch) == 0)
					{
						printf("Entered character is an Ascii character\n");
					}
					else 
					{
						printf("Entered character is not an Ascii character\n");
					}
					break;
			
			case 4:
					//Call Isblank function and check the condition
					if (Isblank(ch) == 0)
					{
						printf("Entered character is a Blank character\n");
					}
					else
					{
						printf("Entered character is not a blank character\n");
					}
					break;

			default:
					printf("Invalid entry.. Please select an option between 1 - 4\n");
					return 0;

		}
	//Prompt if the program is to be repeated
	printf("Do you wish to continue.. Press [Yy | Nn]:");
	scanf("\n%c", &option);
	getchar();


	}while (option == 'Y' || option == 'y');
}

//Defining the funtion to check alphabet or digit
int Isalnum(int ch)
{
	 if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
	 {
	 	 return 0;
	 }
	 else if (ch >= 48 && ch <= 57)
	 {
	 	 return 1;
	 }
	 return -1;
}

//Defining the function to check the case of the letter
int Isalpha(int ch)
{
	 if (ch >= 65 && ch <= 90) 
	 {
	 	 return 0;
	 }
	 else if (ch >= 97 && ch <= 122)
	 {
	 	 return 1;
	 }
	 return -1;
}

//Defining the function to check if entered value is ASCII
int Isascii(int ch)
{
	if (ch >= 0 && ch <= 127)
	{
		return 0;
	}
	return -1;
}

//Defining the funtion for blank character
int Isblank(int ch)
{
	if (ch == 32 || ch == 9)
	{
		return 0;
	}
	return -1;
}
