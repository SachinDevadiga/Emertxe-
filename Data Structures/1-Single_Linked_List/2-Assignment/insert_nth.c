#include "main.h"

int insert_nth(slist **head, data_t n)
{
	data_t i;
	data_t g_data;

	//Check for list empty
	if (*head == NULL)
	{
		return LIST_EMPTY;
	}

	//Creating a node
	slist *new = malloc(sizeof(slist));

	//Assigning the head value to a temporary pointer variable
	slist *temp = *head;

	//Traverse till the nth value
	for (i = 1; i <= n; i++)
	{
		if (temp != NULL)
		{
			if (i == n)
			{
				//Prompt + read the new data value
				printf("Enter the g_data: ");
				scanf("%d", &g_data);
				new->data = g_data;
				new->link = temp->link;
				temp->link = new;
				return SUCCESS;
			}
		}
		else
		{
			return FAILURE;
		}
		//Increment temp to the next link
		temp = temp->link;
	}

}
