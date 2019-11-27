#include "main.h"

void print_slist(slist *head)
{
	//Check for the first node
	if (head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("Elements are\n");
		//Traverse the list printing the values 
		while (head)
		{
			printf("%d-->", head->data);
			head = head->link;
		}
		printf("\n");
	}
}
