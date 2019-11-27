/*
		Title:  File Concatenate
		Author: Sachin Devadiga
		Date:   28/06/2019 14:25 IST
		Description: Program to concatenate contents of two files into third file via command line arguments . 
				      Input specifications: Name of files given via command line
			          Output specifications: Concatenate the contents of the files into the third file
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

//Declare the filecopy function
void filecopy(FILE *fp1, FILE *fp2);

int main(int argc, char *argv[])
{	
	//Clear the output screen
	system("clear");
	
	//Declare the variable here
    char ch;
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    
    //Checking the first argument entered in the command line
    if (argc == 1)
    {
        //Print stdin contents into stdout
        filecopy(stdin, stdout);
    }

    //Checking the second argument entered which is the name of the file
    else if (argc == 2)
    {
        //Opening first file in read mode
        fp1 = fopen(argv[1], "r");
        
        //Error handling for the file 
        if (fp1 == NULL)
        {
            perror("argv[1]");
            return 0;
        }
        //Print the contents of the first file onto the standard output
        filecopy(fp1, stdout);
        //Closing first file
		fclose(fp1);
	}
	
	//Checking the arguments till the third argument which contains the first and second file
    else if (argc == 3)
    {
        //Open first file in read mode
        fp1 = fopen(argv[1], "r");

        //Error Handling for the first file
        if (fp1 == NULL)
        {
            perror("argv[1]");
            return 0;
        }
        
        //Opening second file in read mode
        fp2 = fopen(argv[2], "r");
        
        //Error Handling for the second file
        if (fp2 == NULL)
        {
            perror("argv[2]");
            return 0;
        }
        
        //Print file1 and file2 contents to stdout using filecopy function 
        filecopy(fp1, stdout);
        filecopy(fp2, stdout);
        
        //Closing file1 and file2
        fclose(fp1);
        fclose(fp2);     
    }

	//Checking the arguments till the fourth argument which contains the first,second file and the destination file where the conatenated data requires to be saved
    else if (argc == 4)
    {
        //Open first file in read mode
        fp1 = fopen(argv[1], "r");
        //Error Handling for the first file
        if (fp1 == NULL)
        {
            perror("argv[1]");
            return 0;
        }
        
        //Opening second file in read mode
        fp2 = fopen(argv[2], "r");
        //Error Handling for the second file
        if (fp2 == NULL)
        {
            perror("argv[2]");
            return 0;
        }
        
        //Open third file in write mode, file is created if it does not exist, otherwise it appends
        fp3 = fopen(argv[3], "a");

        //Error Handling for file
        if (NULL == fp3)
        {
            perror("argv[3]");
            //Close the file 1 and file 2
            fclose(fp1);
            fclose(fp2);
            
            return 0;
        }
        
        //Copies file1 and file2 contents to file3 by calling function to do filecopy
        filecopy(fp1, fp3);
        filecopy(fp2, fp3);
        
        //Close all the files
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
    }
    return 0;
    
}

//Defining the function to copy the contents of file 1 an file 2
void filecopy(FILE *fp1, FILE *fp2)
{
    char c;
    c = fgetc(fp1);
    while (c != EOF)
    {
        c = fgetc(fp1);
        fputc(c, fp2);
    }
}
