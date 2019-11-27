#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>

typedef int data_t;
#define SIZE 5
typedef struct 
{
	data_t data[SIZE];
	int front, rear, count;

}Q_array;

enum status
{
	FAILURE,
	SUCCESS,
	QUEUE_FULL,
	QUEUE_EMPTY
};

int enque(Q_array *Q, data_t data);
int deque(Q_array *Q, data_t *data);
int print_queue(Q_array *Q);

#endif
