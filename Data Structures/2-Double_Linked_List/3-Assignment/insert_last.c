#include "main.h"

int insert_last(Dlist **head, Dlist **tail, data_t data)
{
	//Create a node
	Dlist *new = malloc (sizeof(Dlist));

	//Validation
	if (new == NULL)
	{
		return FAILURE;
	}

	//Assigning the data value and the addesses to the node
	new->data = data;
	new->prev = *tail;
	new->next = NULL;
	
	//If first node, then head value is also set to the address of the new node
	if(*head == NULL)
	{
		*head = new;
	}
	//If tail is not NULL, assigning the adddress of the current node to the next pointer of the previous node
	if (*tail != NULL)
	{
		new->prev->next = new;
	}
	//Assigning the address of the created node to the tail pointer
	*tail = new;
	return SUCCESS;
}
