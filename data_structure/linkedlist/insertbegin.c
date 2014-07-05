#include"header.h"
node* insertbegin(node* head)
{
	int data;
	printf("Enter the value==");
	scanf("%d",&data);
	node* news=(node*)malloc(sizeof(node));
	news->info=data;
	news->next=head;
	head=news;
	return head;
}
