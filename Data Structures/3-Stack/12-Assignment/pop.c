#include "main.h"

int pop(slist **stack_top, data_t *data)
{
	//Validation
	if (*stack_top == NULL)
	{
		return STACK_EMPTY;
	}
	//Assigning the head value to a temporary pointer variable
	slist *temp =  *stack_top;
	//Assign the data value to data variable
	*data = temp->data;
	//Incrementing the node and assigning the node address to head and freeing the previous node
	*stack_top = temp->link;
	free(temp);
	return SUCCESS;
}
