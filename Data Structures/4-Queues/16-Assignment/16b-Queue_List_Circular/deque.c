#include "main.h"

int deque(slist **head, slist **rear, data_t *data)
{
	//Check if queue empty or not
	if (*head == NULL)
	{
		return QUEUE_EMPTY;
	}
	
	//Operation to be performed if only one node
	if (((*head)->link) == *head)
	{
		*data = (*head)->data; //Fetch the data and free the node
		free(*head);
		*head = NULL;
		*rear = NULL;
		return SUCCESS;
	}

	else
	{
		//Assigning the link address of the pointer
		slist *temp = *head;
		*data = temp->data;				//Fetch the data
		//Since the head would be pointing to the last node value, updating the link address to the next node from temp node 
		*head = temp->link;		
		free(temp);
		(*rear)->link = *head;
	}
	return SUCCESS;
}
