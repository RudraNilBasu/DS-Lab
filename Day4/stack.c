#include<stdio.h>
#define intd(x) scanf("%d",&x)

struct node // basic node structure
{
	int data; // the data part of the node storing integer value.
	struct node *next; // the pointer to the next node
};

struct node *list; //Pointer to the first node 

int insert_beg() // inserting in the beginning of the list
{
	int n;
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data \n");
	intd(n);// taking input of the node value
	p->data=n;
	p->next=list;
	list=p;// setting the initial node
}

int insert_end() // inserting a node in the end of the list
{
	int n;// the value of the data part of the node
	struct node *p,*q;
	p=(struct node *)malloc(sizeof(struct node));
	q=(struct node *)malloc(sizeof(struct node));
	if(list==NULL)   // if there is no node in the linked list
	{
		printf("Enter the 1st Data\n");
		intd(n);
		p->data=n;
		p->next=NULL;
		list=p;
	}
	else // if list is not NULL
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

int insert_pos() // inserting at any given position
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
				// previous next = p;
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
	//for(p=list;p->next!=NULL;p=p->next);
	//p->next=NULL;
	//printf("DEL  : %d\n",p->data);
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
	//list=p;
	/*
	printf("Enter no of elements in the linked list\n");
	int t,n;
	intd(t);
	while(t--)
	{
		insert_end();
	}
	display();
	printf("YOLO\n");
	delBeg();
	display();
	insert_beg();
	display();
	insert_pos();
	display();
	delEnd();
	display();
	delPos();
	display();
	//printf("LOL\n");
	//delBeg();
	//display();
	*/
	int choice=0;
	while(1)
	{
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
		intd(choice);
		if(choice==1)
		{
			insert_beg();
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
		/*
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
		*/
	}
	return 0;
}
