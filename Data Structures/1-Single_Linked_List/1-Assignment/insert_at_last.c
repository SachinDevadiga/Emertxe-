#include "main.h"

int insert_at_last(slist **head, data_t data)
{
	//Create node
	slist *new = malloc(sizeof(slist));

	//Validation
	if (new == NULL)
	{
		return FAILURE;
	}
	new->data = data;
	new->link = NULL;

	//Check for list empty or not
	if (*head == NULL)
	{
		*head = new;
		return SUCCESS;
	}

	//Take a temporary pointer
	slist *temp = *head;

	//Traverse till last node
	while (temp->link)
	{
		temp = temp->link;
	}
	temp->link = new;
	return SUCCESS;
}
