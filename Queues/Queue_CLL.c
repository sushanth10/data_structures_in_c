#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}node;

node *rear = NULL;

int isEmpty()
{
	if( rear == NULL )
		return 1;
	else
		return 0;
}


void enqueue(int ele)
{
	node *tmp;
	tmp=(node *)malloc(sizeof(node));
	tmp->info=ele;
	if(tmp==NULL)
	{
		printf("\nMemory not available\n");
		return;
	}
	if( isEmpty() )
	{
		rear=tmp;
		tmp->next=rear;
	}
	else
	{
		tmp->next=rear->next;
		rear->next=tmp;
		rear=tmp;
	}
}

int dequeue()
{
	int ele;
	node *tmp;
	if( isEmpty() )
	{
		printf("\nQueue underflow\n");
		exit(1);
	}
	if(rear->next==rear)
	{
		tmp=rear;
		rear=NULL;
	}
	else
	{
		tmp=rear->next;
		rear->next=rear->next->next;
	}
	ele=tmp->info;
	free(tmp);
	return ele;
}


void display()
{
	node *p;
	if(isEmpty())
	{
		printf("\nQueue is empty\n");
		return;
	}
		printf("\nQueue is : ");
		p=rear->next;
	do
	{
		printf("%d\t",p->info);
		p=p->next;
	}while(p!=rear->next);
	printf("\n");
}


int main()
{
	int ch, ele, l=1;
    printf("\n1.Enqueue");
	printf("\n2.Dequeue");
	printf("\n3.Display");
	printf("\nAny other number to Exit\n");
    printf("\nEnter your choice : ");
	scanf("%d",&ch);
	while(l)
	{

		switch(ch)
		{
			case 1:
			printf("\nEnter the element for insertion : ");
			scanf("%d",&ele);
			enqueue(ele);
			break;
			case 2:
			printf("\nDeleted element is : %d", dequeue());
			break;
			case 3:
			display();
			break;
			default:
			l = 0;
		}
        
    printf("\nEnter your choice : ");
	scanf("%d",&ch);
	}
}
