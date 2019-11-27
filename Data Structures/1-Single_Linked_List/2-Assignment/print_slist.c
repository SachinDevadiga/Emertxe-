#include "main.h"

void print_slist(slist *head)
{
	if (head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("Elements are\n");
		while (head)
		{
			printf("%d-->", head->data);
			head = head->link;
		}
		printf("\n");
	}
}
