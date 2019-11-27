#include "main.h"

int insert_at_first(slist **head, data_t data)
{
	//Create node
	slist *new = malloc(sizeof(slist));

	//Validation
	if (new == NULL)
	{
		return FAILURE;
	}
	new->data = data;
	new->link = *head;
	*head = new;
	return SUCCESS;
}
