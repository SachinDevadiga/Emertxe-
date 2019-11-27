#include "main.h"

int deque(Q_array *Q, data_t *data)
{
	//Check if queue empty or not
	if (Q->front == -1)
	{
		return QUEUE_EMPTY;
	}
	//Fetching the value of the first inserted data and incrementing the front value
	*data = Q->data[(Q->front)];
	(Q->front)++;
	
	//If the front value is greater than rear, resetting it to -1
	if (Q->front > Q->rear)
	{
		Q->front = -1;
		Q->rear = -1;
	}
	return SUCCESS;
}
