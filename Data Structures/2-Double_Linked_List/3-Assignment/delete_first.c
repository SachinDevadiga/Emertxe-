#include "main.h"

int delete_first(Dlist **head, Dlist **tail)
{
	//Check for list empty
	if (*head == NULL)
	{
		return LIST_EMPTY;
	}

	//Head pointer to point to next node
	*head = (*head)->next;

	//If the value of the next node is not NULL, free the previous node
	if (*head != NULL)
	{
		free ((*head)->prev);
		(*head)->prev = NULL;
	}
	else
	{
		free(*tail);
		*tail = NULL;
	}
	return SUCCESS;
}
