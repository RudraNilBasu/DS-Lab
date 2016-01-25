/*
Implementation of stack using array.
maximum size of the array is taken a small number (5) to correctly demonstrate the "Stack Full" operation
*/

#include<stdio.h>
#define MAX 5
// MAX is SIZE of the array
int a[MAX];
int top=-1; // the top index of the stack

int push(int x)
{
	if(top>=MAX)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		a[++top]=x;
		printf("%d is pushed in the stack\n",a[top]);
	}
	return 0;
}

int pop()
{
	if(top<0)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		printf("Element popped : %d\n",a[top--]);
	}
	return 0;
}

int display()
{
	int i;
	if(top==-1)
	{
		printf("Stack empty.\n");
	}
	else
	{
		printf("The stack is : \n");
		for(i=0;i<=top;i++)
		{
			printf("%d\n",a[i]);
		}
	}
	return 0;
}

int main()
{
	int i,choice,x;
	while(1)
	{
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			//implement Push FUnctionality
			printf("Enter the number to be pushed\n");
			scanf("%d",&x);// entering the number
			push(x); //calling push method
		}
		else if(choice==2)
		{
			//pop
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
}
