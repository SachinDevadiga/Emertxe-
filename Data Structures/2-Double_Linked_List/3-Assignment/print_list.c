#include "main.h"

void print_list(Dlist *val, int n)
{
	//Check for list empty
	if (val == NULL)
	{
		printf("List is empty\n");
	}
	
	//Printing the list from head 
	else if (n)
	{
		printf("Elements are\n");
		while (val)
		{
			printf("%d-->", val->data);
			val = val->next;
		}
		putchar('\n');
	}
	//Printing the list from tail
	else
	{
		printf("Elements are\n");
		while (val)
		{
			printf("%d-->", val->data);
			val = val->prev;
		}
		putchar('\n');
	}
}
