#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>

typedef int data_t;
#define SIZE 5
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

int enque(slist **head, slist **rear, data_t data);
int deque(slist **head, slist **rear, data_t *data);
int print_queue(slist *head);

#endif
