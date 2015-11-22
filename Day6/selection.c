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
			if(a[pos]>a[j]) // finding the next minimum number
			{
				pos=j;
			}
		}
		if(pos!=i)
		{
			//swap a[pos] and a[i] to save the next least element in it's correct position
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
