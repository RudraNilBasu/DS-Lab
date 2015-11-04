/*
Implementation of reversing a linked list
Done by Rudra Nil Basu
*/
#include<stdio.h>
#define intd(x) scanf("%d",&x)

struct node
{
    int data;
    struct node *next;
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
	list=p;
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

int reverse()
{
    if(list==NULL)
    {
        return 0;
    }
    else
    {
        //reversing algo
        struct node *p,*q,*r; // 3 pointers to struct node
        r=NULL;p=list;q=p->next;
        while(p->next!=NULL)
        {
            p->next=r;
            r=p;
            p=q;
            q=q->next;
        }
        p->next=r;
        list=p;
    }
    return 0;
}

int main()
{
    int n;
    printf("Enter the number of data in the linked list\n");
    intd(n);
    while(n--)
    {
        //input of the linked list
        insert_end();
    }
    printf("Before Reversing : \n");
    display();
    reverse();//reversing the linked list
    printf("After Reversing : \n");
    display();
    return 0;
}
