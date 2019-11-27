/*
     Title:  Copy file content
     Author: Sachin Devadiga
     Date:   28/06/2019 12:25 IST
     Description: Program to copy content of one file to another file using command line arguments. 
                  Input specifications: Source File name, Destination File name
                  Output specifications: To copy contents of source file to destination file
*/
/*-----------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

//Declare the function
int my_copy(FILE *, FILE *);

int main(int argc, char *argv[])
{
	//Clear the output screen
	system("clear");

	//Declare the variables
	FILE *fs, *fd;

	//Open the source file in read mode
	fs = fopen(argv[1], "r");
	
	//Validation to check if the value is NULL
	if (fs == NULL)
	{
		perror(argv[1]);
		return 0;
	}
	
	//Open the destination file in write mode
	fd = fopen(argv[2], "w");
	
	//Validation to check if the value is NULL
	if (fd == NULL)
	{
		perror(argv[2]);
		return 0;
	}
	
	//Calling the funtion to copy the content from source to destination
	my_copy(fs, fd);

	//Closing the files
	fclose(fs);
	fclose(fd);
}

//Defining the copy function
int my_copy(FILE *fs, FILE *fd)
{
	char buffer;

	while(fread(&buffer, 1, 1, fs) > 0)
	{
		fwrite(&buffer, 1, 1, fd);
	}

