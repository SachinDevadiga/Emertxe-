#include "main.h"

int insert_after(slist **head, data_t n_data, data_t g_data)
{
	//Check for empty list
	if (*head == NULL)
	{
		return LIST_EMPTY;
	}

	//Assigning the head value to a temp pointer variable
	slist *temp = *head;

	//Traverse the list till n_data is found
	while (temp && temp->data != n_data)
	{
		temp = temp->link;
	}
	if (temp)
	{
		//Create a new node
		slist *new = malloc(sizeof(slist));
	
		//Validation
		if (new == NULL)
		{
			return FAILURE;
		}
		new->data = g_data;
		new->link = temp->link;
		temp->link = new;
		return SUCCESS;
	}
	return DATA_NOT_FOUND;
}
