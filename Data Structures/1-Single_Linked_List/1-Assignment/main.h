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
int delete_last(slist **head);
int find_node(slist **head, data_t n_data);
int delete_list(slist **head);
void print_slist(slist *head);


#endif
