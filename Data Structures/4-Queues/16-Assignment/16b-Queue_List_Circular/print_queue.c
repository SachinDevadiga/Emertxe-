#include "main.h"

int print_queue(slist *head)
{
	//Check for the first node
	if (head == NULL)
	{
		return QUEUE_EMPTY;
	}
	else
	{
		printf("Elements are\n");
		//Assigning the link address of the head pointer to temp pointer so that printing starts from first node
		slist *temp = head;
		//Traverse the list printing the values 
		while (temp->link != head)
		{
			printf("%d-->", temp->data);
			temp = temp->link;
		}
		printf("%d-->", temp->data);
		printf("\n");		
	}
	return SUCCESS;
}
