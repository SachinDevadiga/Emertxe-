#include "main.h"

int delete_element(Dlist **head, Dlist **tail, data_t n_data)
{
	//Check for list empty
	if (*head == NULL)
	{
		return LIST_EMPTY;
	}

	//Check for first node
	if ((*head)->data == n_data)
	{
		return delete_first(head, tail);
	}
	
	//Assigning the head value to a temp pointer 
	Dlist *temp = *head;
	
	//Traverse the list till NULL
	while (temp)
	{
		//Check node data is same as n_data
		if (temp->data == n_data)
		{
			//Assign the address if the next node to the next pointer of the previous node
			temp->prev->next = temp->next;
			//If next pointer value of the current node is not NULL, then assign the previous address of the node to the previous pointer of the next node
			if (temp->next != NULL)
			{
				temp->next->prev = temp->prev;
			}
			//Deallocate the memory
			free(temp);
			return SUCCESS;
		}
		//Incrementing temp
		temp = temp->next;
	}
	return DATA_NOT_FOUND;
}
