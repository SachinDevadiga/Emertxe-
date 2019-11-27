/*
     Title:  Combination
     Author: Sachin Devadiga
     Date:   14/06/2019 12:25 IST
     Description: Program to find combination of characters and display the result. 
                  Input specifications: len: Variable to hold the entered integer number
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

//Declaring the functions
void combination(char *str, int start, int last);
void swap(char *c1, char *c2);

int main()
{	
	//Declare the variable
	int len;
	
	//Prompt + read the value
	printf("Enter the length: ");
	scanf("%d", &len);
	
	//Declaring the array
	char str[len];

	//Prompt + read the value
	printf("Enter the characters: ");
	scanf("%s", str);
	
	//Calling the combination function
	combination(str, 0, len - 1);

	return 0;
}
//Defining the combination function
void combination(char *str, int start, int last)
{	
	//Declaring the variable
	int i;
	
	//Displaying the string when the location become equal
	if (start == last)
	{
		printf("%s\n", str);
	}
	else
	{
		for (i = start; i <= last; i++)
		{
			swap ((str + start), (str + i));
			//Calling the function recursively
			combination(str, start + 1, last);
			swap ((str + start), (str + i));

		}
	}
}
//Defining the swap function
void swap(char *c1, char *c2)
{
	char temp;

	temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}
