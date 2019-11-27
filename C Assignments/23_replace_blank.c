/*
		Title:  Replace blank spaces 
		Author: Sachin Devadiga
		Date:   1/07/2019 12:25 IST
		Description: Program to replace multiple blank spaces with single blank space and display the result. 
			          Input specifications: stdin: Read values from standard input buffer
				      Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int main()
{	
	//Clear the output screen
	system("clear");

	//Declare the variables
    char c, previous_character;
    
    //Read a character till EOF is recieved 
    while ((c = getchar()) != '\n')
    {
        //Check if the character is space 
        if (c == ' ')
        {
            //Check if previous character was not space, then print the character
            if (previous_character != ' ')
            {
                putchar(c);
            }
        }
         //If the character is not space then print
        else
        {
            putchar(c);
        }
        //Update the previouscharacter with curent c
        previous_character = c;
    }
    return 0;
}
