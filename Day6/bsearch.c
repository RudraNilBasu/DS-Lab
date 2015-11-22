#include<stdio.h>
int main()
{
	int a[5];
	int n,i; // no to search
	printf("Enter the sorted array\n"); // considering sorted array
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the number to search\n");
	scanf("%d",&n);
	int low=0,high=4,mid=(low+high)/2,flag=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==n)
		{
			printf("Found\n");
			flag=1;
			break;
		}
		else
		{
			if(n>a[mid])
			{
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}
		}
	}
	if(!flag)
	{
		printf("Not Found\n");
	}
	return 0;
}
