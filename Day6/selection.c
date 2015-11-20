#include<stdio.h>
#define SIZE 5
int main()
{
	int a[SIZE];
	int i,j,pos=0;
	printf("Enter the unsorted aray\n");
	for(i=0;i<SIZE;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Sorted array : \n");
	for(i=0;i<SIZE;i++)
	{
		pos=i;
		for(j=i+1;j<SIZE ;j++)
		{
			if(a[pos]>a[j])
			{
				pos=j;
			}
		}
		if(pos!=i)
		{
			//swap a[pos] and a[i]
			int temp=a[pos];
			a[pos]=a[i];
			a[i]=temp;
		}
	}
	for(i=0;i<SIZE;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
