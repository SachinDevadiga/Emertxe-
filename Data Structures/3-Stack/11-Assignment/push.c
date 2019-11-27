#include "main.h"

int push(s_array *s, data_t data)
{
	//Check for stack FULL or NOT
	if (s->top == SIZE - 1)
	{
		return STACK_OVERFLOW;
	}
	//Increment the top and add element
	(s->top)++;
	s->data[s->top] = data;
	return SUCCESS;
}
