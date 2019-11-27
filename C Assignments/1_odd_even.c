/*
	Title:	Signed Even or Odd
	Author: Sachin Devadiga
	Date:	24/05/2019 12:25 IST
	Description: Program to check if the given number is a signed even or odd integer and display the result. 
				 Input specifications: num: Variable to hold the entered integer number
				 Output specifications: Display the result
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	//Clear the output screen
	system("clear");

	//Declaration of variable num to hold an integer value and initialising flag variable to zero
	int num,i,pow;
	int flag = 0;

	//Promt the user to enter a number
	printf("Enter the number: ");

	//Read the value + store the value in the variable num
	scanf("%d", &num);

	/*Logic to obtain the value for the range condition 2^20. The loop multples 2 with itself and the loop iterates 20 times as per the given conditon*/ 
	for(i = 1,pow = 1; i <= 20; i++)
	{
		pow = pow * 2;
	}

	//Validation to check if entered value is an integer or not
	if(num >= -pow && num <= pow)
	{
		flag = 1;
	}
	else
	{
		printf("Invalid. Enter an integer number\n");
	}

	//Below condition is executed when the flag becomes 1
	if(flag)
	{
		if(num > 0) //Condition to check if the number lies in the negative range
		{
			if(num % 2) // Logic to check if the number is even or odd
			{
				printf("%d is a positive Odd number\n", num);
			}
			else
			{
				printf("%d is a positive Even number\n", num);
			}
		}
		else if(num < 0) //Condition to check if the number lies in the positive range
		{
			if(num % 2) // Logic to check if the number is even or odd
			{
				printf("%d is a negative Odd number\n", num);
			}
			else
			{
				printf("%d is a negative Even number\n", num);
			}
		}
	}
	return 0;
}
