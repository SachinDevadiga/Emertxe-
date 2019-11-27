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
	LIST_EMPTY,
	DATA_NOT_FOUND
};

int insert_at_first(slist **head, data_t);
int insert_at_last(slist **head, data_t);
int delete_first(slist **head);
int insert_before(slist **head, data_t n_data, data_t g_data);
int insert_after(slist **head, data_t n_data, data_t g_data);
int insert_nth(slist **head, data_t n);
int delete_element(slist **head, data_t n_data);
void print_slist(slist *head);


#endif
