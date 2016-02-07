/*
Implementation of Circular Queue using array
Done by : Rudra Nil Basu
*/

#include<stdio.h>
#define intd(x) scanf("%d",&x)

#define SIZE 5

int front=0,rear=-1; // the front and rear element's index of the circular queue
int a[SIZE];


int del()
{
    if(front==0 && rear == -1)
    {
        printf("Underflow\n");
    }
    else if(front==rear)
    {
        printf("Element deleted : %d\n",a[front]);
        front=0;
        rear=-1;
    }
    else if(front==SIZE-1) // if the element to be deleted is the last element of the array
    {
        printf("Element deleted : %d\n",a[front]);
        front=0;
    }
    else
    {
        printf("Element deleted : %d\n",a[front++]);
    }
    return 0;
}


int insrt(int x)
{
    // insert a number to the queue
    if(front==0 && rear==SIZE-1)
    {
        printf("Queue Overflow.\n");
    }
    else if(front>0 && rear == front-1)
    {
        printf("Queue Overflow.\n");
    }
    else
    {
        if(front>0 && rear==SIZE-1) // when the array end is full but there is some element empty from the front
        {
            rear=0;
            a[rear]=x;
        }
        else
        {
            if(rear!=front-1)
            {
                a[++rear]=x;
            }
            else if(front==0 && rear==-1)
            {
                a[++rear]=x; // when the queue is empty
            }
        }
    }
    return 0;
}

int display()
{
    int i;
    if(front==0 && rear==-1)
    {
        printf("Queue Empty.\n");
    }
    else if(front>rear)
    {
        printf("Queue is : .\n");
        for(i=front;i<SIZE;i++)
        {
            printf("%d\n",a[i]);
        }
        for(i=0;i<=rear;i++)
        {
            printf("%d\n",a[i]);
        }
    }
    else
    {
        printf("Queue is : .\n");
        for(i=front;i<=rear;i++)
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
        printf("1.Insert\n2.Delete.\n3.Display.\n4.EXIT\n");
        intd(choice);
        if(choice==1)
        {
            printf("Enter no to insert\n");
            intd(x);
            insrt(x);
        }
        if(choice==2)
        {
            del();
        }
        if(choice==3)
        {
            display();
        }
        if(choice==4)
        {
            break;
        }
    }
    return 0;
}
