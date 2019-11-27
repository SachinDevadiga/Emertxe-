/* Title: Sort names 
   Author: Sachin
   Date : 22/062019
   Description : Input: Read 'n' Names
				 output : Display the Names sorted order			 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 32
//Function Declaration
void sortnames(char **string, int);

int main()
{
	//Variables Declaration
	int n;
	char option;
	char **strings;
	int i;

	do
	{
		//prompt the user to enter the limit
		printf("Enter the limit : ");
		scanf("%d", &n);

		//memory allocating
		strings = (char **) malloc( n * sizeof(char *));
		 for (i = 0; i < n; i++)
		 {
		 	 strings[i] = (char *)malloc(MAX * sizeof(char));
		 }
	
		printf("Enter the strings..\n");
		for (i = 0; i < n; i++)
		{
			printf("strings[%d]=", i);
			getchar();
			scanf("%[^\n]s", strings[i]);

		}


		//Calling a function
		sortnames(strings, n);

		//Display the after sorting string
		printf("\nAfter sorting\n");	

		for (i = 0; i < n; i++)
		{
			printf("strings-->%s\n", strings[i]);
		}

		//want to continue press Yy || Nn
		printf("\nContinue press [Yy || Nn] : ");
		getchar();
		scanf("%c", &option);
	} while (option == 'Y' || option == 'y');
	return 0;
}

//Function defination for sorting
void sortnames(char **string, int n)
{
	int i, j, k;
	char temp; 
	//Sorting names by alphabetically
	for (i = 0; i < n; i++)
	{
		for (k = i +1; k < n; k++)
		{
			for (j = 0; j < n; j++)
			{
				//Check the condition two equal to character increment column and check next character
				if (*(*(string+i)+j) == *(*(string+k)+j))
				{
					continue;
				}
				//Check the condition 1st chara < 2nd chara break the column and increment  to check next string
				else if (*(*(string+i)+j) < *(*(string+k)+j))
				{
					break;
				}
				//Swap the two strings
				else
				{
					int m=0; 
					while(*(*(string+i)+m) != '\0' || *(*(string+k)+m) != '\0')
					{
						temp = *(*(string+i)+m);
						*(*(string+i)+m) = *(*(string+k)+m);
						*(*(string+k)+m) = temp;
						m++;
					}
				}
			}
		}
	}
}


