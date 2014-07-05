#include"header.h"
void display(node* head)
{
	if(head==NULL)
	{
		printf("LIST EMPTY\n");
	}
	else
	{
		while(head!=NULL)
		{
			printf("%d---->",head->info);
			head=head->next;
		}
		printf("\n");
	}
}
