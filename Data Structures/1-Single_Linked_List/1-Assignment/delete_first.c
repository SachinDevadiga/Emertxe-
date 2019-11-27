#include "main.h"

int delete_first(slist **head)
{
	//Validation
	if (*head == NULL)
	{
		return FAILURE;
	}
	//Assigning the head value to a temporary pointer variable
	slist *temp =  *head;
	*head = temp->link;
	free(temp);
	return SUCCESS;
}
