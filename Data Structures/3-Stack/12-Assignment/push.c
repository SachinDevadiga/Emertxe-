#include "main.h"

int push(slist **stack_top, data_t data)
{
	//Create node
	slist *new = malloc(sizeof(slist));

	//Validation
	if (new == NULL)
	{
		return STACK_EMPTY;
	}
	//Assigning the data value and address to the created node
	new->data = data;
	new->link = *stack_top;
	*stack_top = new;
	return SUCCESS;
}
