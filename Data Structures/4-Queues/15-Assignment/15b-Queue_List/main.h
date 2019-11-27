#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>

typedef int data_t;
typedef struct node 
{
	data_t data;
	struct node *link;

}slist;

enum status
{
	FAILURE,
	SUCCESS,
	QUEUE_FULL,
	QUEUE_EMPTY
};

int enque(slist **front, data_t data);
int deque(slist **front, data_t *data);
int print_queue(slist *front);
#endif
