#include "main.h"

int enque(Q_array *Q, data_t data) 
{
	//Validation to check if the queue is full or not
	if (Q->count == SIZE)
	{
		return QUEUE_FULL;
	}

	//Incrementing the Q->front so that the 0th location of the array could be accessed
	if (Q->front == -1)
	{
		(Q->front)++;
	}

	//Incrementing the Q->rear so that the 0th loctaion could be accessed
	(Q->rear) = (Q->rear + 1) % SIZE;
	//Inserting the data into the array
	Q->data[(Q->rear)] = data;
	//Incrementing the count
	(Q->count)++;
	return SUCCESS;
}
