#include "main.h"

int delete_element(slist **head, data_t n_data)
{
	//Check if list is empty
	if (*head == NULL)
	{
		return LIST_EMPTY;
	}

	//Check for first node
	if ((*head)->data == n_data)
	{
		return delete_first(head);
	}
	
	//Assigning the head value to a temporary pointer variable
	slist *temp = *head;
	slist *past = NULL;

	//Traversing till n_data is reached
	while (temp)
	{
		if (temp->data == n_data)
		{
			past->link = temp->link;
			free(temp);
			return SUCCESS;
		}
		past = temp;
		temp = temp->link;
	}
	return DATA_NOT_FOUND;
}
