#include "main.h"

int insert_first(Dlist **head, Dlist **tail, data_t data)
{
	//Create a node
	Dlist *new = malloc(sizeof(Dlist));

	//Validation
	if (new == NULL)
	{
		return FAILURE;
	}
	
	//Assigning the data value and addresses to the node
	new->data = data;
	new->prev = NULL;
	new->next = *head;
	
	//If first node, then tail value is also set to the address first node
	if (*head == NULL)
	{
		*tail = new;
	}

	//If it is not the first node, assigning the current node address to the previous pointer of the next node
	if (new->next != NULL)
	{
		new->next->prev = new;
	}
	//Assigning the address of the created node to the head pointer 
	*head = new;
	return SUCCESS;
}
