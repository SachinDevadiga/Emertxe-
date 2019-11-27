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
	STACK_OVERFLOW,
	STACK_EMPTY
};

int peak(slist **stack_top, data_t *data);
int push(slist **stack_top, data_t data);
int pop(slist **stack_top, data_t *data);
int peep(slist *stack_top);
#endif
