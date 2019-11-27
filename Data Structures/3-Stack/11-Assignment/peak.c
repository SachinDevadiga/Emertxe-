#include "main.h"

int peak(s_array *s, data_t *data)
{
	//Check for stack FULL or NOT
	if (s->top == -1)
	{
		return STACK_EMPTY;
	}
	//Fetch the data if the topmost element
	*data = s->data[s->top];
	return SUCCESS;
}
