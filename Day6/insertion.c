#include<stdio.h>
int main()
{
	int a[5];
	printf("Enter the unsorted elements\n");
	int i,j;
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<5;i++)
	{
		j=i;
		while(j>0 && a[j-1]>a[j])
		{
			a[j-1]=a[j-1]+a[j];
			a[j]=a[j-1]-a[j];
			a[j-1]=a[j-1]-a[j];

			j--;
		}
	}
	printf("Sorted array : \n");
	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
