#include "main.h"

int delete_list(Dlist **head, Dlist **tail)
{

	//Check for list empty
	if (*head == NULL)
	{
		return LIST_EMPTY;
	}
	//Freeing the previous nodes as long as the next pointer of the nodes is not NULL
	while ((*head)->next != NULL)
	{
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
	//Freeing the tail node and assigning NULL to the head and tail pointers
	free(*tail);
	*tail = NULL;
	*head = NULL;
	return SUCCESS;
}
