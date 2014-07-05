#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
	int info;
	struct st* next;
}node;
node* insert(node*,int);
void display(node*);
void mergelist(node**,node**);
int main()
{
	node* head1=NULL;
	node* head2=NULL;
	int data;
	int c;
	do
	{
		printf("1.Insert in first list \n2.Insert in second list\n3.Display first list.\n4.Display second list.\n5.MergeList\n0.Exit\n");
		printf("Enter your choice==");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Enter the number==");
				scanf("%d",&data);
				head1=insert(head1,data);
				//printf("%d-->",head->info);
			break;
			case 2:
				printf("Enter the number==");
				scanf("%d",&data);
				head2=insert(head2,data);
			break;
			case 3:
				display(head1);
			break;
			case 4:
				display(head2);
			break;
			case 5:
				mergelist(&head1,&head2);
			break;
			default:
			break;
		}
	}while(c!=0);
	return 0;
}
node* insert(node* head,int data)
{
	node* p;
	node* q;
	p=head;
	if(p==NULL)
	{
		p=(node*)malloc(sizeof(node));
		p->info=data;
		p->next=NULL;
		return p;
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		q=(node*)malloc(sizeof(node));
		q->info=data;
		q->next=NULL;
		p->next=q;
		return head;
	}
}
void display(node* head)
{
	node* p;

	p=head;
	while(p!=NULL)
	{
		printf("%d-->",p->info);
		p=p->next;
	}
	printf("\n");
}
void mergelist(node** head1,node** head2)
{
	node* p=*head1;
	node* q=*head2;
	while(1)
	{
		if(p==NULL)
		{
			break;
		}
		else if(q->next!=NULL)
		{
			node* temp=q->next;
			q->next=p->next;
			p->next=q;
			*head2=temp;
		}
		else if(q->next==NULL)
		{
			q->next=p->next;
			p->next=q;
			*head2=NULL;
			break;
		}
		p=q->next;
		q=*head2;

	}
}
