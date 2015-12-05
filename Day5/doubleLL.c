/*
Implementation of Doubly Linked List.
Implement Insert at front, end, any position
	  Delete at front rear any position

Done by Rudra Nil Basu	  
*/
#include<stdio.h>
#define intd(x) scanf("%d",&x)

struct node // basic node structure
{
	struct node *prev; // link to the previous node
	int data;   // the data part containing the value of the node
	struct node *next;  // link to the next node
};

struct node *list; // pointer to the first node of the list

int insFr()// to insert at front
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node ));
	if(list==NULL)
	{
		// if the list is empty
		printf("Enter the data\n");
		intd(p->data); 
		p->next=NULL; // the next part of the last node is NULL
		list=p;
		p->prev=list; // inserting at front, so previous part has to be "list"
	}
	else
	{
		// if list is not empty
		printf("Enter the data\n");
		intd(p->data);

		p->next=list; // next part of last node is NULL
		list->prev=p; 
		list=p;

	}
	return 0; // for successfull execution of the method
}

int display()
{
	struct node *p;
	if(list==NULL) // if list is empty
	{
		printf("Empty\n");
	}
	else
	{
		printf("\n\nThe list is \n");
		for(p=list;p!=NULL;p=p->next)
		{
			printf("%d\n",p->data);
		}
	}
	printf("\n");
	return 0;
}

int insEnd()
{
	struct node *p;
	struct node *q;
	p=(struct node *)malloc(sizeof(struct node));
	if(list==NULL) // if the list is empty
	{
		insFr(); // call insert at the front
		return 0;
	}
	else 
	{
		// accept the value of the node
		printf("Enter the value of the data part of the node\n");
		intd(p->data);
		// if the list is not empty
		for(q=list;q->next!=NULL;q=q->next) // moving to the last node
		{}
		p->next=NULL;
		p->prev=q;
		q->next=p;
	}
	return 0;
}

int insPos()
{
	int pos;
	printf("Enter the position after which you want to insert\n");
	intd(pos);
	struct node *p,*q;
	p=(struct node *)malloc(sizeof(struct node));
	int c=0;
	for(q=list;q->next!=NULL;q=q->next)
	{
		c++;
		if(c==pos){break;}
	}
	printf("Enter the data\n");
	intd(p->data);

	// inserting
	p->next=q->next;
	p->prev=q;

	(q->next)->prev=p;
	q->next=p;
	return 0;
}

int delFr()
{
	if(list==NULL) // not performing deletion if the list is empty
	{
		printf("Empty\n");
		return 0;
	}
	else
	{
		(list->next)->prev=NULL;
		list=list->next;
	}
	return 0;
}

int delEnd()
{
	struct node *q;
	if(list==NULL)
	{
		printf("Empty\n");
		return 0;
	}
	for(q=list;q->next!=NULL;q=q->next);
	(q->prev)->next=NULL;
	return 0;
}

int delPos()
{
	int pos;
	if(list==NULL)
	{
		return 0;
	}
	printf("Enter the pos\n");
	intd(pos);
	int c=0;
	struct node *q;
	for(q=list;q->next!=NULL;q=q->next)
	{
		c++;
		if(c==pos)
		{
			break;
		}
	}
	((q->next)->next)->prev=q;
	q->next=(q->next)->next;
	return 0;
}

int main()
{
	int ch; // choice of the user
	while(1)
	{
		// input of choice
		printf("1.Insert at front\n");
		printf("2.Insert at end\n");
		printf("3.Insert at any position\n");
		printf("4.Delete from front\n");
		printf("5.Delete from rear.\n");
		printf("6.Delete at any position\n");
		printf("7.Display\n");
		printf("8.End\n");
		intd(ch);
		// calling other functions as per the choice
		if(ch==1)
		{
			insFr();
		}
		if(ch==2)
		{
			insEnd();
		}
		if(ch==3)
		{
			insPos();
		}
		if(ch==4)
		{
			delFr();
		}
		if(ch==5)
		{
			delEnd();
		}
		if(ch==6)
		{
			delPos();
		}
		if(ch==7)
		{
			display();
		}
		if(ch==8)
		{
			break;
		}
	}
	return 0;
}
