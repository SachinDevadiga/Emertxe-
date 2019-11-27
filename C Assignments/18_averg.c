/*
     Title:  Average
     Author: Sachin Devadiga
     Date:   10/06/2019 12:25 IST
     Description: Program to find average of numbers using two methods(Preset environmental variable, Command Line input) and display the result.
                  Input specifications: Choice to be selected on the terminal window
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declare the environmental function
void environmental_var(float *avg, char **env);
int my_atoi(const char *str);
int digit(int ch);

int main(int argc, char *argv[], char *env[])
{
	//Declare the variables
	int i, size, choice;
	int sum = 0;
	int count = 0;
	float avg;

	//Prompt + read the choice
	printf("Enter the choice:\n1.Environmental variable\n2.Command line input\n");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1://Calling the environmental function
			environmental_var(&avg, env);
			printf("Average: %f\n", avg);
			break;

		case 2://Calculating average when inputs are given via command line
			if (argc > 1)	//If the argument count is greater than 1 
			{
				for (i = 1; i < argc; i++)
				{
					if (my_atoi(argv[i]))
					{
						sum += my_atoi(argv[i]); //Converting the ASCII value in the arguments to integer and adding the values
					}
					else
					{
						printf("Enter only numbers in command line\n");
						return 0;
					}
				}
				avg = (float)sum / (argc - 1);
				//Displaying the result
				printf("Average: %f\n", avg);
			}
			else
			{
				printf("No input given in command line\n");
				return 0;
			}
			break;

	}
}
//Defining the environmental function
void environmental_var(float *avg, char **env)
{
	//Declaring the variables
	int i;
	int sum = 0;
	int count = 0;
	int flag = 0;
	char *p;
	
	//Logic to check if the mentioned environmental variable is available
	for (i = 0; env[i]; i++)
	{
		if (strncmp (env[i], "ARRAY", 5) == 0)
		{
			printf("Match found %s\n", env[i]);
			flag = 1;
			strtok(env[i], "=");	//Once match is found, separating the values from the environmental variable and summing the values
			while ((p = strtok (NULL, ",")) != NULL)
			{
				sum = sum + atoi(p);
				count++;
			}
		}
	}

	if (flag)
	{
		*avg = (float)sum / count;
	}
	else
	{
		printf("Match not found\n");
		*avg = 0;
		return;
	}
}
//Defining the my_atoi function
int my_atoi(const char *str)
{
	//Declaring the variables
	int flag = 0;
	int num = 0;

	//Checking if the first value is negative sign
	if (*(str + 0) == '-')
	{
		flag = 1;
		str++;
	}

	//Converting the string into an integer value
	while (*str)
	{
		if (digit(*str))
		{
			num = num * 10 + (*str - '0');
		}
		else
		{
			return 0;
		}
		str++;
	}

	//If enetered nember is negative, multiply with -1
	if (flag)
	{
		num = num * (-1);
	}
	return num;
}
//Defining the digit function
int digit(int ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return 1;
	}	
	return 0;
}

