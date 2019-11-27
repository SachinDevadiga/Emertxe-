#include "main.h"

int peep(slist *stack_top)
{
	//Check for the first node
	if (stack_top == NULL)
	{
		return STACK_EMPTY;
	}
	else
	{
		printf("Elements are\n");
		//Traverse the list printing the values 
		while (stack_top)
		{
			printf("%d\n", stack_top->data);
			stack_top = stack_top->link;
		}
		printf("\n");
		return SUCCESS;
	}
}
