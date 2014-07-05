#include"header.h"
int main()
{
	node* head=NULL;
	int c;
	printf("--------------------------------LINKED LIST PROGRAM-------------------------------\n");
	do
	{
		printf("\n1.INSERT IN THE END\n2.INSERT IN THE BEGIN\n3.INSERT IN THE MIDDLE\n10.DISPLAY THE LIST\n0.EXIT\n");
		printf("\nENTER YOUR CHOICE==\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				head=insertend(head);
				break;
			case 2:
				head=insertbegin(head);
				break;
			case 3:
				head=insertmiddle(head);
				break;
			case 10: 
				display(head);
		}
	}while(c!=0);
	return 0;
}
