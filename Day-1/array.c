// insert variable in beginning
// delete using a given index
// display the array

#include<stdio.h>
#define SIZE 50 

int a[SIZE];
int top = -1;


int insert(int x)
{
	int i;
	if(top==SIZE-1)
	{
		printf("Array is full.\n");
	}
	else
	{
		top++;
		//shifting
		
		for(i=top-1;i>=0;i--)
		{
			a[i]=a[i-1];
		}
		a[0]=x;
		printf("***We inserted %d . ***\n",x);
	}
}

int del(int x)
{
	int i;
	for(i=x;i<top;i++)
	{
		a[i]=a[i+1];
		top--;
	}
}

int display()
{
	int i;
	if(top==-1)
	{
		printf("Empty\n");
	}
	else
	{
		printf("The array is : \n");
		for(i=0;i<=top;i++)
		{
			printf("%d",a[i]);
		}
	}
	printf("\n..................................\n");
}

int main()
{
	int i,c,number,pos,cases;
	printf("Enter number of choices\n");
	scanf("%d",&cases);
	for(i=1;i<=cases;i++)
	{
		printf("\n........................\n");
		printf("1. Insert at beginning.\n2. Delete at any position.\n3.Display\n");
		printf("\n....................\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: 
			printf("Enter the number to be inserted.\n");
			scanf("%d",&number);
			insert(number);
			//printf("\n**LOL**\n");
			break;
			case 2:
			printf("Enter the position to be deleted.\n");
			scanf("%d",&pos);
			del(pos);
			break;
			case 3 : 
			display();
			break;
		}
	}
}
