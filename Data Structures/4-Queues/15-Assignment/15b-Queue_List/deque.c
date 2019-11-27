#include "main.h"

int deque(slist **front, data_t *data)
{
	//Validation
	if (*front == NULL)
	{
		return QUEUE_EMPTY;
	}
	//Assigning the head value to a temporary pointer variable
	slist *temp =  *front;
	//Fetching the data value of the node
	*data = temp->data;
	//Updating the head with the next node address
	*front = temp->link;
	//Deallocating the memory of thr previous node
	free(temp);
	return SUCCESS;
}
