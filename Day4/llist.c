/*
Program to perform basic operations in a linked list, including
i) insert (at beginning, at end, at any position)
ii) delete (from beginning, from end, any position)
iii) reversing a linked list
*/
//TODO: Reversing the linked list
#include<stdio.h>
#define intd(x) scanf("%d",&x)

struct node // basic structure of all nodes
{
	int data;
	struct node *next; // pointer to the next node
};

struct node *list; // pointer to the first list

int insert_beg() //insert in the beginning of the list
{
	int n;
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data \n");
	intd(n);
	p->data=n;
	p->next=list;
	list=p; // inserting at the beginning
}

int insert_end()
{
	int n;
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

int insert_pos()
{
	int pos,n,c=0,k=0;
	printf("Enter the position after which the node will be inserted\n");
	intd(pos);
	printf("Enter data\n");
	intd(n);
	struct node *p;
	struct node *q;
	q=(struct node *)malloc(sizeof(struct node));
	for(p=list;p!=NULL;p=p->next)
	{
		c++;
	}
	if(pos>c)
	{
		printf("Out of bounds\n");
	}
	else
	{
		c=0;
		for(p=list;p!=NULL;p=p->next)
		{
			c++;
			if(c==pos)
			{
				q->data=n;
				q->next=p->next;
				p->next=q;
				break;
			}
		}
	}
}

int delEnd()
{
	struct node *p,*q;
	p=(struct node *)malloc(sizeof(struct node));
	q=(struct node *)malloc(sizeof(struct node));
	if(list==NULL)  // checking whether the list is empty
	{
		printf("Empty\n");
	}
	else
	{
		p=list;
		if(p->next == NULL)
        	{
            		// if there is only one node in the list
            		p=NULL;
            		list=NULL;
        	}
		while(p->next!=NULL) // moving till the 2nd last node
		{
			q=p;
			p=p->next;
		}
		q->next=NULL;
	}
	//q->next=NULL;
}

int delBeg()
{
	if(list==NULL)
	{
		printf("Empty\n");
	}
	else
	{
		//list->next=(list->next)->next;
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
		return 0;
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
			if(c==pos-1)
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
		printf("1.Insert at Beg\n2.Insert at end\n3.Delete at beginning\n4.Delete at end\n5.Delete at any pos\n6.Insert at any pos\n7.End\n8.Display\n");
		intd(choice);
		if(choice==1)
		{
			insert_beg();
		}
		else if(choice==2)
		{
			insert_end();
		}
		else if(choice==3)
		{
			delBeg();
		}
		else if(choice==4)
		{
			delEnd();
		}
		else if(choice==5)
		{
			delPos();
		}
		else if(choice==6)
		{
			insert_pos();
		}
		else if(choice==7)
		{
			break;
		}
		else if(choice==8)
		{
			display();
		}
	}
	return 0;
}
