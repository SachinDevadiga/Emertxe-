/*
     Title:  Implementing printf
     Author: Sachin Devadiga
     Date:   9/07/2019 23:25 IST
     Description: Program to write a function that mimics printf and display the result 
                  Input specifications: Predefined in the program with a constant value
                  Output specifications: Display the result
*/
/*------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

//Declare the my_printf function
void my_printf(const char *format,...);

int main()
{
	//Clear the output screen
	system("clear");

	//Define the variables here
	char c = 'A';
	int i = 10;
	float f = 1.3;
	double d = 12.48;

	//Calling the my_printf function
	my_printf("The value of c: %c\n", c);
	my_printf("The value of i: %d\n", i);
	my_printf("The value of f: %f\n", f);
	my_printf("The value of d: %lf\n", d);

	return 0;
}

//Defining the my_printf function
void my_printf(const char *format,...)
{
	char c;
	int i;
	float f;
	double d;
	va_list ap;
	const char *p = format;

	va_start(ap, format);
	char buffer[80] = {'\0'};
	while (*p)
	{
		if ( *p == '%')
		{
			switch (*++p)
			{
				case 'c'://Displays the character on the output screen
					c = (char)va_arg(ap, int);
					putchar(c);
					break;

				case 'd'://Displays the integer value on the output screen
					i = va_arg(ap, int); 
					sprintf(buffer, "%d", i);
					puts(buffer);
					break;

				case 'f'://Displays the float value on the output screen
					f = va_arg(ap, double);
					sprintf(buffer, "%f", f);
					puts(buffer);
					break;

				case 'l':
					switch (*++p)
					{
						case 'f'://Displays the double value on the output screen
							d = va_arg(ap, double);
							sprintf(buffer, "%lf", d);
							puts(buffer);
							break;
					}
			}
		}
		else
		{
			putchar(*p);
		}
		p++;

	}
	va_end(ap);
}

