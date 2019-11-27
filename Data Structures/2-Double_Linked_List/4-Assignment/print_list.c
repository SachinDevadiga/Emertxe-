#include "main.h"

void print_list(Dlist *val, int n)
{
	if (val == NULL)
	{
		printf("List is empty\n");
	}

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
