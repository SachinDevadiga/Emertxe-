/*
      Title:  Tower of Hanoi
      Author: Sachin Devadiga
      Date:   18/06/2019 12:25 IST
      Description: Program to display the movement of disks in Tower of Hanoi. 
                  Input specifications: disk: Variable to hold the entered integer number
                  Output specifications: Display the result
*/
/*-----------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

//Declaring the functions
void hanoi(int, char *, char *, char *);
int isvalid(int status);

int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables here
	char source[] = "Source", temp[] = "Temporary", dest[] = "Destination", option;
	int disk, status;

	do
	{

		//Prompt + read the entered value
		printf("Enter the number of disks: ");
		status = scanf("%d", &disk);

		//Validation of the entered value
		if (isvalid(status) || disk <= 0)
		{
			printf("Invalid entry.. Please enter value greater than zero\n ");
			return 0;
		}

		//Display the result
		printf("Seguence is :\n");

		//Calling the hanoi function
		hanoi(disk, source, temp, dest);

		//Prompt if the program is to be repeated
		printf("Do you wish to continue.. Press[Yy | Nn]: ");
		scanf("\n%c", &option);

	}while (option == 'Y'|| option == 'y');
	return 0;
}

//Defining the hanoi function
void hanoi(int disk, char *source, char *temp, char *destination)
{
	if (disk > 0)
	{
		//Recursively calling the same function to implement the operation
		hanoi(disk - 1, source, destination, temp);

		//Displaying the action performed 
		printf("Move Disk %d from %s to %s\n", disk, source, destination);
	
		//Recursively calling the same function to implement the operation
		hanoi(disk - 1, temp, source, destination);
	}
}

//Defining the validation function
int isvalid(int status)
{
	if (status != 1)
	{
		return 1;
	}
	return 0;
}	
