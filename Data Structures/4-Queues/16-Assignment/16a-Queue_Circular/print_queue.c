#include "main.h"

int print_queue(Q_array *Q)
{
	//Check if queue empty or not
	if (Q->count == 0)
	{
		return QUEUE_EMPTY;
	}
	//Assigning the Q->front and Q->count value to the temporary variables
	data_t front = (Q->front);
	data_t count = (Q->count);
	printf("Elements are\n");
	//Displaying the elements of the queue
	while (count > 0)
	{
		printf("%d-->", Q->data[front]);
		front = (front + 1) % SIZE;
		count--;
	}
	printf("\n");
	return SUCCESS;
}
