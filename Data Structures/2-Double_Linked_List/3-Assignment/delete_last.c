#include "main.h"

int delete_last(Dlist **head, Dlist **tail)
{
	//Check list empty
	if (*head == NULL)
	{
		return LIST_EMPTY;
	}

	//Moving tail pointer to the previous node 
	*tail = (*tail)->prev;

	//If the tail node is not NULL, freeing the next node after the tail node
	if (*tail != NULL)
	{
		free ((*tail)->next);
		(*tail)->next = NULL;
	}
	else
	{
		free(*head);
		*head = NULL;
	}
	return SUCCESS;
}
