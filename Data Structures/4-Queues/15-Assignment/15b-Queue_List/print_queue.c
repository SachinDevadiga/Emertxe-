#include "main.h"

int print_queue(slist *front)
{
	//Check for the first node
	if (front == NULL)
	{
		return QUEUE_EMPTY;
	}
	else
	{
		printf("Elements are\n");
		//Traverse the list printing the values 
		while (front)
		{
			printf("%d-->", front->data);
			front = front->link;
		}
		printf("\n");		
	}
	return SUCCESS;
}
