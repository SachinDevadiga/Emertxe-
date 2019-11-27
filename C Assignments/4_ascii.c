/*
     Title:  ASCII Table
     Author: Sachin Devadiga
     Date:   29/05/2019 23:36 IST
     Description: Program to display the ASCII table. 
                  Input specifications: N/A
                  Output specifications: Display the ASCII table
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	//Clear the output screen
	system("clear");

	//Declaring the variables used in the program
	int dec, oct, hex, i;
	char ch, option;
	
	//Looping to re-iterate the program of the user keys in [Yy] at the end of the program
	do
	{
		//Displaying the title row on the output screen
		printf("Decimal\tOctal\tHexadecimal\tCharacter\n");

		//Using the for loop which is iterated 127 times, wherein each iteration value is taken as the input to obtain the decimal,octal,hexadecimal and character values  
		for(i = 0; i < 128; i++)
		{	
			//Initiating the variables to hold the i value to display the output
			dec = i;
			oct = i;
			hex = i;
			ch = i;

			//Character values from 0-32 and 127 are non printable. Thus below condition checks if i value falls between the range and dispalys the output
			if(i <= 32 || i == 127)
			{
				printf("%d\t%o\t%X\t\tNon-Printable\n", dec,oct,hex);
			}
			else 
			{
				printf("%d\t%o\t%X\t\t%c\n", dec,oct,hex,ch);
			}
		}

		//Prompt the user is the program requires to be repeated 
		printf("Do you wish to continue.. Press [Yy | Nn]: ");

		//Read the value + store in the variable
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
}
