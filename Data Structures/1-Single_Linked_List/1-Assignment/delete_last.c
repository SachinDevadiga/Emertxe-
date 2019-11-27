#include "main.h"

int delete_last(slist **head)
{
	//Validation
	if (*head == NULL)
	{
		return FAILURE;
	}
	//Assigning the head value to a temporary pointer variable
	slist *temp = *head;

	//Check for first node
	if (temp->link == NULL)
	{
		free(*head);
		*head = NULL;
		return SUCCESS;
	}
	
	//Traverse till the last node 
	//Below loop checks for NULL in the immediate next node from the current node
	while (temp->link->link)
	{
		temp = temp->link;
	}
	temp->link = NULL;
	free(temp->link);
	return SUCCESS;
	
}
