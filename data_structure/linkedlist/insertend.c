#include"header.h"
node* insertend(node* head)
{
	node* ptr=head;
	int data;
	printf("Enter the Value==");
	scanf("%d",&data);
	if(ptr==NULL)
	{
		ptr=(node*)malloc(sizeof(node));
		ptr->info=data;
		ptr->next=NULL;
		return ptr;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		node* news=(node*)malloc(sizeof(node));
		news->info=data;
		news->next=NULL;
		ptr->next=news;
		return head;
	}
}
