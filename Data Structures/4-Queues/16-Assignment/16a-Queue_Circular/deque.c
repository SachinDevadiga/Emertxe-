#include "main.h"

int deque(Q_array *Q, data_t *data)
{
	//Check if queue empty or not
	if (Q->count == 0)
	{
		return QUEUE_EMPTY;
	}
	//Fetching the value of the inserted data and incrementing the front value
	*data = Q->data[(Q->front)];
	(Q->front) = (Q->front + 1) % SIZE;
	//Decrementing the count
	(Q->count)--;

	return SUCCESS;
}
