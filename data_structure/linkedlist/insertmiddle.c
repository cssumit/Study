#include"header.h"
node* insertmiddle(node* head)
{
	node* ptr=head;
	int data,pos;
	printf("Enter the Position==");
	scanf("%d",&pos);
	printf("Enter the Value==");
	scanf("%d",&data);
	int cnt=2;
	if(ptr==NULL)
	{
		if(pos!=1)
		{
			printf("Position is not valid\n");
			return head;
		}
		else
		{
			ptr=(node*)malloc(sizeof(node));
			ptr->info=data;
			ptr->next=NULL;
			return ptr;
		}    
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
			cnt++;
			if(cnt==pos)
				break;
		}
		if(cnt==pos)
		{
			node* news=(node*)malloc(sizeof(node));
			news->info=data;
			news->next=ptr->next;
			ptr->next=news;
		}
		else
		{
			printf("Position in not valid\n");
		}
		return head;
	}
}
