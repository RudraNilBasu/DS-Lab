/*
Alternate of array.c
Insert element in the beginning
Delete from any position
Display
*/

#include<stdio.h>
#define SIZE 5
#define intd(x) scanf("%d",&x)

int a[SIZE];
int front=-1;

int insert()
{
	//insert at beginning
	
	// Boundary condition when the array is full
	if(front==SIZE-1)
	{
	    printf("Array is full\n");
	    return 0;
	}
	int i,value;
	printf("Enter the value\n");
	intd(value);
	for(i=front;i>=0;i--)
	{
		a[i+1]=a[i];
	}
	front++; //increasing front value by one
	a[0]=value;
	return 0;
}

int delete()
{
	int pos,i;
	printf("Enter position (starting from 0)\n");
	intd(pos);
	if(pos>front)
	{
		printf("Out of Bounds\n");
	}
	else if(pos==front)
	{
		printf("Deleted element %d\n",a[front]);
		front--; // the last element is to be deleted
	}
	else
	{
		printf("Deleted element : %d\n",a[pos]);
		for(i=pos;i<front;i++)
		{
			a[i]=a[i+1]; // shifting left
		}
		front--;
	}
	return 0;
}

int display()
{
	int i;
	printf("The array is : \n");
	for(i=0;i<=front;i++)
	{
		printf("%d\n",a[i]);
	}
	if(front==-1)
	{
		printf("Empty\n");
	}
	return 0;
}

int main()
{
	int choice;
	while(1)
	{
		printf("1.Insert at beginning\n2.Delete at any pos\n3.Display\n4.Exit\n");
		intd(choice);
		if(choice==1)
		{
			insert();
		}
		else if(choice==2)
		{
			delete();
		}
		else if(choice==3)
		{
			display();
		}
		else
		{
			break;
		}
	}
	return 0;
}
