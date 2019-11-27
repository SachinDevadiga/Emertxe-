#include "main.h"

int enque(slist **head, slist **rear, data_t data)
{
	//Create node
	slist *new = malloc(sizeof(slist));

	//Validation
	if (new == NULL)
	{
		return QUEUE_FULL;
	}

	//Check for list empty or not
	if (*head == NULL)
	{
		new->data = data;
		new->link = new;		//Assigning the address of the node itself
		*head = new;			//Assigning the new node to the pointer
		*rear = new;
		return SUCCESS;
	}

	else
	{
	//Take a temporary pointer
		slist *temp = *rear;
		new->data = data;			//Insert the data
		new->link = temp->link;		//Assigning the previous link address to the new node link pointer thereby creating a loop
		temp->link = new;			//Updating the head node with the new node address
		*rear = new;				//Moving the head pointer to the new node
		return SUCCESS;
	}
}
