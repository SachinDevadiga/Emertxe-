/*
     Title:  Days of the year
     Author: Sachin Devadiga
     Date:   26/05/2019 18:25 IST
     Description: Program to display the nth day when the start day is provided, where the nth day is the number of days to be added to the start day. 
                  Input specifications: start: Variable to hold the start day value entered by the user.
										days: Variable to hold the nth value/number of days to be added to the start day 

                  Output specifications: Display the result
*/
/*-------------------------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	//Clear the output screen
	system("clear");

	// Declaring the variables to hold the values of the start day, number of days, evaluation operation
	int start,days,new;

	//Prompt the user to enter the start day value
	printf("Enter the start day\n1.Sunday\n2.Monday\n3.Tuesday\n4.Wednesday\n5.Thursday\n6.Friday\n7.Saturday\n");

	//Read the value + store in the variable start
	scanf("%d", &start);

	//Validation to check if entered number is within the specified range
	if(start < 1 || start >7)
	{
		printf("Invalid input. Please try again.\n");
		exit(1);
	}

	//Prompt the user to enter the number of days to be added to the start day
	printf("Enter the number of days\n");

	//Read the value + store in the variable days
	scanf("%d", &days);

	//Validation to check if given number is within the range 1 - 365
	if (days < 1 || days > 365)
	{
		printf("Invalid input. Please try again.\n");
		exit(2);
	}

	//Logic to calculate the value of the nth day to obtain the final result
	new = start + days - 1;

	//Switch case is used to print the name of the nth day obtained by adding the start value and the result obtained form the Logic operation value new 
	switch(new % 7)
	{
		case 0: 
			printf("The day is Saturday\n");
			break;
		case 1: 
			printf("The day is Sunday\n");
			break;
		case 2:		
			printf("The day is Monday\n");
			break;
		case 3: 
			printf("The day is Tuesday\n");
			break;
		case 4:		
			printf("The day is Wednesday\n");
			break;
		case 5: 
			printf("The day is Thursday\n");
			break;
		case 6: 
			printf("The day is Friday\n");
			break;
	default:
			printf("Invalid\n");
	}
	return 0;
}
