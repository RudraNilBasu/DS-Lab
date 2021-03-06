/*
Implementation of Queue using Linked List. (FIFO)
Done By Rudra Nil Basu
*/

#include<stdio.h>
#define intd(x) scanf("%d",&x)

// basic node structure
struct node
{
	int data;
	struct node *next;
};

struct node *list;

int insert_beg()
{
	// Insert at the beginning of the list
	int n;
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data \n");
	intd(n);
	p->data=n;
	p->next=list;
	list=p;
}

int insert_end()
{
	// insert a node at the end of the linked list
	int n; // data to be stored
	struct node *p,*q;
	p=(struct node *)malloc(sizeof(struct node));
	q=(struct node *)malloc(sizeof(struct node));
	if(list==NULL)
	{
		printf("Enter the 1st Data\n");
		intd(n);
		p->data=n;
		p->next=NULL;
		list=p;
	}
	else
	{
		for(q=list;q->next!=NULL;q=q->next);
		printf("Enter the data\n");
		intd(n);
		p->data=n;
		p->next=NULL;
		q->next=p;
	}
	return 0;
}



int delEnd()
{
	struct node *p,*q;
	p=(struct node *)malloc(sizeof(struct node));
	q=(struct node *)malloc(sizeof(struct node));
	p=list;
	if(list==NULL)
	{
		printf("Empty\n");
	}
	else
	{

		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		q->next=NULL;
	}
}

int delBeg()
{
	if(list==NULL)
	{
		printf("Empty\n");
	}
	else
	{
		list=list->next;
	}
}

int delPos()
{
	int pos,n,c=0;
	printf("Enter the position\n");
	intd(pos);
	if(pos==1)
	{
		delBeg();
	}
	struct node *p;
	for(p=list;p!=NULL;p=p->next)
	{
		c++;
	}
	if(c==pos)
	{
		delEnd();
	}
	if(pos>c)
	{
		printf("Not Possible\n");
	}
	else
	{
		c=0;
		for(p=list;p!=NULL;p=p->next)
		{
			c++;
			if(c==pos)
			{
				p->next=(p->next)->next;
				break;
			}
		}
	}
	return 0;
}

int display()
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	if(list==NULL)
	{
		printf("Empty\n");
	}
	else
	{
		printf("The list is : \n");
		for(p=list;p!=NULL;p=p->next)
		{
			printf("%d\n",p->data);
		}
	}
}

int main()
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	int choice=0;
	while(1)
	{
		printf("1.Insert\n2.Delete.\n3.Display\n4.Exit\n");
		intd(choice);
		if(choice==1)
		{
			insert_end();
		}
		else if(choice==2)
		{
			delBeg();
		}
		else if(choice==3)
		{
			display();
		}
		else if(choice==4)
		{
			break;
		}
	}
	return 0;
}
