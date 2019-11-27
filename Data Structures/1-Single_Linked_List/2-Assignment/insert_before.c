#include "main.h"

int insert_before(slist **head, data_t n_data, data_t g_data)
{
	//Check for list empty
	if (*head == NULL)
	{
		return LIST_EMPTY;
	}

	//Creating a node
	slist *new = malloc(sizeof(slist));
	
	//Assign head value to a temporary pointer variable
	slist *temp = *head;

	//Check the first node
	if (temp->data == n_data)
	{
		new->data = g_data;
		new->link = *head;
		*head = new;
		return SUCCESS;
	}

	//Assigning the temp variable value to another variable
	slist *prev = temp;

	//Traverse till the n_data node is reached
	while (temp)
	{
		if (temp->data == n_data)
		{
			new->data = g_data;
			new->link = prev->link;
			prev->link = new;
			return SUCCESS;
		}
		prev = temp;
		temp = temp->link;
	}
	return DATA_NOT_FOUND;
}
				if (status == SUCCESS)
				{
					printf("First node has been deleted\n\n");
				}
				else
				{
					printf("Unable to delete node\n\n");
				}
