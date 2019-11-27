#include "main.h"

int insert_before(Dlist **head, Dlist **tail, data_t n_data, data_t g_data)
{
	//Check for list empty
	if (*head == NULL)
	{
		return LIST_EMPTY;
	}
	
	//Assign the head value to a temp  pointer
	Dlist *temp = *head;
	
	//Traverse the list till NULL
	while (temp)
	{
		//Check if node data is same as n_data
		if (temp->data == n_data)
		{
			//Create a node
			Dlist *new = malloc(sizeof(Dlist));

			//Validation
			if (new == NULL)
			{
				return FAILURE;
			}
			//Store the data value and addresses into the new node
			new->data = g_data;
	        new->prev = temp->prev;
	        new->next = temp;
	        //If next node is not NULL, assign the current node address to the next pointer of the previous node
			if (temp->prev)
			{
				temp->prev->next = new;
			}
			else
			{
				*head = new;
			}
			//Assigning the address of new node to the next pointer of the node
			temp->prev = new;
			return SUCCESS;
		}
		//Incrementing temp
		temp = temp->next;
	}
	return DATA_NOT_FOUND;
}
