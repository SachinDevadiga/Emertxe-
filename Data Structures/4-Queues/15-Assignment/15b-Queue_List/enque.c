#include "main.h"

int enque(slist **front, data_t data)
{
	//Create node
	slist *new = malloc(sizeof(slist));

	//Validation
	if (new == NULL)
	{
		return QUEUE_FULL;
	}
	new->data = data;
	new->link = NULL;

	//Check for list empty or not
	if (*front == NULL)
	{
		*front = new;
		return SUCCESS;
	}

	//Take a temporary pointer
	slist *temp = *front;

	//Traverse till last node
	while (temp->link)
	{
		temp = temp->link;
	}
	temp->link = new;
	return SUCCESS;
}
