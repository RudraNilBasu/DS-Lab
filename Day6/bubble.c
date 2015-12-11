#include<stdio.h>
#define SIZE 5
int main()
{
	int i,j;
	int a[SIZE];
	printf("Enter elements in unsorted order\n");
	for(i=0;i<SIZE;i++)
	{
		scanf("%d",&a[i]); // the unsorted array
	}
	//Sorting
	for(i=0;i<SIZE-1;i++)
	{
		for(j=0;j<SIZE-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]=(a[j]+a[j+1])-(a[j+1]=a[j]);
			}
		}
	}
	//Printinh
	printf("Sorted array\n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
