#include "main.h"

int pop(s_array *s, data_t *data)
{
	//Check for stack FULL or NOT
	if (s->top == -1)
	{
		return STACK_EMPTY;
	}
	//Fetch the value and decrement the top
	*data = s->data[s->top];
	(s->top)--;
	return SUCCESS;
}
