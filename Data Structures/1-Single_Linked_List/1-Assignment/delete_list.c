#include "main.h"

int delete_list(slist **head)
{
	//Validation
	
	if (*head == NULL)
	{
		return FAILURE;
	}
	//Assigning the head value to a temporary pointer
	slist *temp;
	//Traversing through all the nodes and freeing the memory
	while ((*head) != NULL)
	{
		temp = *head;
		*head = temp->link;
		free(temp);
	}
	return SUCCESS;
}
