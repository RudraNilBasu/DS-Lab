#include<stdio.h>
int main()
{
	int a[50],b[50],c[50];
	char p1[50],p2[50];
	int i,n,pos,num;
	for(i=0;i<50;i++)
	{
		a[i]=0;
		b[i]=0;
		c[i]=0;
	}
	printf("Enter the first polynomial\n");
	printf("Enter the number of elements in the first polynomial\n");
	scanf("%d",&n);
	while(n--)
	{
		printf("Enter the coeff\n");
		scanf("%d",&pos);
		printf("Enter value\n");
		scanf("%d",&num);
		a[pos]=num;
	}
	printf("\n................\n");
	printf("Enter the second polynomial\n");
	printf("Enter the number of elements in the second polynomial\n");
	scanf("%d",&n);
	while(n--)
	{
		printf("Enter the coeff\n");
		scanf("%d",&pos);
		printf("Enter value\n");
		scanf("%d",&num);
		b[pos]=num;
	}
	/*
	//PRINTING 
	printf("1st array\n");
	for(i=0;i<50;i++)
	{
		if(a[i]!=0)
		{
			printf("%d ( %d ) +",a[i],i);
		}
	}
	printf("\n");
	//END OF PRINTING
	*/
	//ADDING
	for(i=0;i<50;i++)
	{
		c[i]=a[i]+b[i];
	}
	//PRINTING
	printf("FIRST POLYNOMMIAL\n");
	for(i=0;i<50;i++)
	{
		if(a[i]!=0)
		{
			printf("%dx^%d+",a[i],i);
		}
	}
	printf("\n");
	//.....................
	printf("SECOND POLYNOMIAL\n");
	for(i=0;i<50;i++)
	{
		if(b[i]!=0)
		{
			printf("%dx^%d+",b[i],i);
		}
	}
	printf("\n");
	//-----------------
	printf("\nFINAL POLYNOMIAL\n");
	for(i=0;i<50;i++)
	{
		if(c[i]!=0)
		{
			printf("%dx^%d+",c[i],i);
		}
	}
	printf("\n");
}