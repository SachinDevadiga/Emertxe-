/*
	Title:  Airthmetic Progression, Geometric Progression, Harmonic Progression
	Author: Sachin Devadiga
	Date:   30/05/2019 12:25 IST
	Description: Program to print the AP,GP,HP series when the start number, common ratio/difference, number of terms are given. 
				 Input specifications: start_num: Variable to hold the start number entered
									   common_diff: Variable to hold the common difference number entered
									   num: Variable to hold the nth number of terms to be displayed 
     			 Output specifications: AP_res: Variable to hold the result of the Airthmetic Progression
									   GP_res: Variable to hold the result of the Geometric Progression
									   HP_res: Variable to hold the result of the Harmonic Progression
 */
/*----------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables here
	char option;
	int start_num, common_diff, num, AP_res, GP_res , status1, status2, status3, i, pow = 1;
	float HP_res;

	do
	{
		//Prompt the user to enter the start number
		printf("Enter the start number: ");

		//Read the value + store in the variable
		status1 = scanf("%d", &start_num);

		//Validation to check if the entered number is positive integer number
		if(status1 != 1 || start_num <= 0)
		{
			printf("Invalid entry.. Please try again\n ");
			exit(1);
		}


		//Prompt the user to enter the common difference/ratio
		printf("Enter the common difference or common ratio: ");

		//Read the value + store in the variable
		status2 = scanf("%d", &common_diff);

		if(status2 != 1 || common_diff <= 0)
		{
			printf("Invalid entry.. Please try again\n ");
			exit(2);
		}
		//Prompt the user to enter the number of terms
		printf("Enter the number of terms: ");

		//Read the value + store in the variable
		status3 = scanf("%d", &num);

		if(status3 != 1 || num <= 0)
		{
			printf("Invalid entry.. Please try again\n ");
			exit(3);
		}

		AP_res = start_num;
		GP_res = start_num;
		HP_res = start_num;

		//Displaying the output for AP,GP,HP
		printf("AP\tGP\tHP\n");

		for (i = 0; i < num; i++)
		{
			//Logic to find the AP sequence wherein the n value is provided by i variable
			printf("%d\t" , AP_res);
			AP_res = AP_res + common_diff;
			
			//Logic to find the GP sequence wherein the n value is provided by i variable
			pow = pow * common_diff;
			printf("%d\t", GP_res);
			GP_res = start_num * pow;
			
			//Logic to find the HP sequence wherein the n value is provided by i variable
			printf("%f\t", HP_res); 
			HP_res = 1 / ((float)HP_res + common_diff);

			printf("\n");
		}

		//Prompt the user if the program requires to be repeated
		printf("\nDo you wish to continue...Press [Yy | Nn]");

		//Read the value + store in the variable
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
}
