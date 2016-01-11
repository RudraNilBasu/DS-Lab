#include<stdio.h>
#define SIZE 5
int a[SIZE];
int front=-1,last=0;

int push(int x)
{
	if(front>=SIZE) // Overflow condition
	{
		printf("Queue Overflow\n");
	}
	else
	{
		a[++front]=x; // increasing front value by one and storing the input in a[front]
		printf("Element pushed : %d\n",a[front]);
	}
	return 0;
}

int pop()
{
	if(last>front)
	{
		printf("QUEUE Underflow\n");
	}
	else
	{
		printf("Element popped : %d\n",a[last++]);
	}
	return 0;
}

int display()
{
	int i;
	if(last>front)
	{
		printf("QUEUE Empty\n");
	}
	else
	{
		printf("\nThe QUEUE is : \n");
		for(i=last;i<=front;i++)
		{
			printf("%d\n",a[i]);
		}
	}
	return 0;
}

int main()
{
	int choice,x;
	while(1)
	{
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Enter the number to push\n");
			scanf("%d",&x);
			push(x);
		}
		else if(choice==2)
		{
			pop();
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
