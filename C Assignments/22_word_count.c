/*
		Title:  Word Count
		Author: Sachin Devadiga
		Date:   01/07/2019 10:25 IST
		Description: Program to find the number of words, lines, characters and display the result. 
			          Input specifications: stdin: Read the value from standard input buffer
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
	int flag = 0, lines = 0, words = 0, characters = 0;
	char c, previouscharacter = ' ';

	do
	{
		//Read a character
		c = getc(stdin);

		//Increment the character count
		characters++;

		//If newline increment the line count
		if (c == '\n')
		{
			lines++;
		}
		
		
		//If newline or space or tab increment the word count
		if ((previouscharacter != ' ' &&  previouscharacter != '\n' && previouscharacter != '\t') && (c == ' ' || c == '\n'|| c == '\t')) 
		{
		
					//If next character is newline or space or tab decrement the word count
						words++;
				
		}
		
		//If EOF [ctrl+D] break the loop
		if (c == EOF)
		{
			//Decrement one character count for EOF
			characters--;
			break;
		}
		previouscharacter = c;

	} while (1);

	if (previouscharacter != ' ' &&  previouscharacter != '\n' && previouscharacter != '\t')
	{
		words++;

	}


	//Print the character count, word count and line count
	printf("\n");
	printf("Lines = %d, Words = %d, Characters = %d\n", lines, words, characters);

	return 0;

}
