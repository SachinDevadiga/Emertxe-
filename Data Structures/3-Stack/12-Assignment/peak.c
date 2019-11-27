#include "main.h"

int peak(slist **stack_top, data_t *data)
{
	//Check for stack FULL or NOT
	if (*stack_top == NULL)
	{
		return STACK_EMPTY;
	}
	//Fetch the topmost data from the list
	*data = (*stack_top)->data;
	return SUCCESS;
}
