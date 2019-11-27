#include "main.h"

int insert_after(Dlist **head, Dlist **tail, data_t n_data, data_t g_data)
{
	//Check for list empty
	if (*head == NULL)
	{
		return LIST_EMPTY;
	}
	
	//Assigning the head value to a temporary variable
	Dlist *temp = *head;
	
	//Traversing as long a temp is not NULL
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
	        new->next = temp->next;
	        new->prev = temp;
	        //If next node is not NULL, assign the current node address to the previous pointer of the next node
			if (temp->next)
			{
				temp->next->prev = new;
			}
			else
			{
				*tail = new;
			}
			//Assigning the address of new node to the next pointer of the node
			temp->next = new;
			return SUCCESS;
		}
		//Incrementing temp
		temp = temp->next;
	}
	return DATA_NOT_FOUND;
}
