/*
     Title:  Implementing scanf
     Author: Sachin Devadiga
     Date:   9/07/2019 23:25 IST
     Description: Program to write a function that mimics scanf and display the result. 
                  Input specifications: Value to be input via terminal
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

//Declaring the function
void my_scanf(const char *format, ...);
int my_atoi(const char *str);
float my_atof(const char *str);
int digit(int ch);

int main()
{
	char option;

	do
	{
		//Declaring the variable
		char ch;
		//Prompt + read the value
		printf("Enter a character: ");
		my_scanf("%c", &ch);
		//Display the character
		printf("Entered character: %c\n", ch);
		getchar();

		//Declaring the variable
		int a;
		//Prompt + read the value
		printf("Enter an integer number: ");
		my_scanf("%d", &a);
		//Display the value
		printf("Entered integer: %d\n", a);

		//Declaring the variable
		float f;
		//Prompt + read the value
		printf("Enter a float number: ");
		my_scanf("%f", &f);
		//Display the value
		printf("Entered float number: %f\n", f);

		//Declaring the variable
		double d;
		//Prompt + read the value
		printf("Enter a double number: ");
		my_scanf("%lf", &d);
		//Display the value
		printf("Entered double number: %lf\n", d);

		//Prompt + read the value
		printf("Do you wish to continue... Press [Yy | Nn]: ");
		scanf("\n%c", &option);
		getchar();

	}while (option == 'Y' || option == 'y');

	return 0;
}

//Defining the scanf function
void my_scanf(const char *format, ...)
{
	//Declaring the variables
	va_list ap;
	const char *p = format;
	va_start(ap, format);
	char *cp = NULL;
	int *ip = NULL;
	float *fp = NULL;
	double *dp = NULL;
	char buffer[80] = {'\0'};

	while (*p)
	{
		if (*p == '%')
		{
			switch (*++p)
			{
				case 'c'://Performs scanning of character value
						cp = va_arg(ap, char *);
						*cp = getchar();
						break;

				case 'd'://Performs scanning of integer value
						fgets(buffer, 10, stdin);
						ip = va_arg(ap, int *);
						*ip = my_atoi(buffer);
						break;
				
				case 'f'://Performs scanning of float value
						fgets(buffer, 10, stdin);
						fp = va_arg(ap, float *);
						*fp = my_atof(buffer);
						break;

				case 'l':
						switch(*++p)
						{
							case 'f': //Performs scanning of double value
									fgets(buffer, 10, stdin);
									dp = va_arg(ap, double *);
									*dp = my_atof(buffer);
									break;
						}
	
			}
		}
		p++;
	}
	va_end(ap);
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
//Defining the my_atof function
float my_atof(const char *str)
{
	//Declaring the variables
	int i, j = 0, ten = 0;
	float dec = 0, result = 0;
	
	//Initiating the loop to traverse the string
	for (i = 0; *(str + i) != '\0'; i++)
	{
		//If first loaction is negative skip to the next location
		if(*(str + i) == '-')
		{
			continue;
		}

		//Performs conversion of the string after the decimal point to a float value
		if (*(str + i) == '.' && *(str + i) != '\0')
		{
			for (j = i + 1; *(str + j) != '\0'; j++)
			{
				dec = (dec * 10) + (*(str + j) - '0');
				ten = j - i;

			} 
			break;
		}
		//Performs conversion of the string before the decimal point to a float value
		else
		{
			result = (result * 10) + (*(str + i) - '0');
		}
	}
	
	//Obtaining the denominator to be used to obtain the float result
	float denominator = 1;
	for (i = 0; i < ten; i++)
	{
		denominator *= 10;
	}
	
	//Multiplying the value obtained before decimal point with the denominator
	float temp = result * denominator;
	
	//Adding the decimal value to the temp value
	temp += dec;
	
	//Obtaining the floating value
	result = temp / denominator;
	
	//Multiplying with -1 if the first location of the string has a negative sign
	if (*(str + 0) == '-')
	{
		result *= -1;
	}

	return result;
}



