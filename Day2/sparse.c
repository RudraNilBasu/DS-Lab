#include<stdio.h>
int main()
{
	int a[20][3]; // 3 tupple
	int v,h,r1,c1,r2,c2,v1,v2,i,j,val;
	int sp1[20][20],sp2[20][20];
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			sp1[i][j]=0;
			sp2[i][j]=0;
		}
	}
	printf("Enter for First Matrix\n");
	printf("Enter no of rows and columns\n");
	scanf("%d %d",&r1,&c1);
	printf("Enter no of non zero elements\n");
	scanf("%d",&v1);
	for(i=1;i<=v1;i++)
	{
		printf("Enter ith and jth position\n");
		scanf("%d %d",&i,&j);
		printf("ENter the value\n");
		scanf("%d",&v);
		sp1[i][j]=v;
	}
	printf("Enter for Second Matrix\n");
	printf("Enter no of rows and columns\n");
	scanf("%d %d",&r2,&c2);
	printf("Enter no of non zero elements\n");
	scanf("%d",&v2);
	for(i=1;i<=v2;i++)
	{
		printf("Enter ith and jth position\n");
		scanf("%d %d",&i,&j);
		printf("ENter the value\n");
		scanf("%d",&v);
		sp2[i][j]=v;
	}
	int sp3[20][20];
	printf("CHOOSE AN OPTION : \n1.Addition.\n2.Multiplication\n");
	int choice;
	scanf("%d",&choice);
	if(choice==1)
	{
		if(r1!=r2 || c1!=c2)
		{
			printf("INCOMPATIBLE\n");
		}
		else
		{
			for(i=0;i<r1;i++)
			{
				for(j=0;j<c1;j++)
				{
					sp3[i][j]=sp1[i][j]+sp2[i][j];
				}
			}
		}
		//PRINTING
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				printf("%d ",sp3[i][j]);
			}
			printf("\n");
		}
	}
}
