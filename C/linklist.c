#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
	int info;
	struct st* next;
}node;
node* insert(node*,int);
void display(node*);
node* pairwiseswap(node*);
int main()
{
	node* head=NULL;
	int data;
	int c;
	do
	{
		printf("1.Insert\n2.Display\n3.PairWiseSwap\n0.Exit\n");
		printf("Enter your choice==");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Enter the number==");
				scanf("%d",&data);
				head=insert(head,data);
				//printf("%d-->",head->info);
			break;
			case 2:
				display(head);
			break;
			case 3:
				head=pairwiseswap(head);
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
node* pairwiseswap(node* head)
{
	if (head == NULL || (head)->next == NULL)
		        return;
	 
	    // Initialize previous and current pointers
	    node *prev = head;
	    node *curr = (head)->next;
	    head = curr;  // Change head before proceeeding
		     
		        // Traverse the list
	    while (1)
	    {
	    	node *next = curr->next;
		curr->next = prev; // Change next of current as previous node
		// If next NULL or next is the last node
		if (next == NULL || next->next == NULL)
		{
			prev->next = next;
			break;
		}
		// Change next of previous to next next
		prev->next = next->next;
		// Update previous and curr
		prev = next;
		curr = prev->next;
	    }
	    return head;
}
