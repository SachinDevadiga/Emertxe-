#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>

typedef int data_t;
#define SIZE 5
typedef struct 
{
	data_t data[SIZE];
	int top;

}s_array;

enum status
{
	FAILURE,
	SUCCESS,
	STACK_OVERFLOW,
	STACK_EMPTY
};

int push(s_array *s, data_t data);
int pop(s_array *s, data_t *data);
int peak(s_array *s, data_t *data);
int peep(s_array *s);

#endif
