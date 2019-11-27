#include "main.h"

int find_node(slist **head, data_t n_data)
{
	//Check for list empty
	if (*head == NULL)
	{
		return LIST_EMPTY;
	}
	//Check for first node
	if ((*head)->data == n_data)
	{
		return SUCCESS;
	}
	//Assigning head value to a temporary variable
	slist *temp = *head;
	
	//Traversing through the list till n_data is found
	while(temp)
	{
		if (temp->data == n_data)
		{
			return SUCCESS;
		}
		temp = temp->link;
	}
}
