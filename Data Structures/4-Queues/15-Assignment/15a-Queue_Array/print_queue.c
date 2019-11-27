#include "main.h"

int print_queue(Q_array *Q)
{
	//Check if queue empty or not
	if (Q->front == -1)
	{
		return QUEUE_EMPTY;
	}
	//Assigning the Q->front value to the temporary variable
	data_t front = (Q->front);
	
	printf("Elements are\n");
	//Displaying the elements of the queue 
	while (front <= Q->rear)
	{
		printf("%d-->", Q->data[front]);
		front++;
	}
	printf("\n");
	return SUCCESS;
}
