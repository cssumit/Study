#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
	int info;
	struct st* next;
}node;
node* insertbegin(node*);
node* insertend(node*);
node* insertmiddle(node*);
