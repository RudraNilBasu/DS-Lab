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
		if(a[mid]==n) // checking if the number is the mid element
		{
			printf("Found\n");
			flag=1;
			break;
		}
		else
		{
			if(n>a[mid]) // checking whether to take the first or second half of the array
			{
				low=mid+1;
			}
			else // if the element is in the second half of the array
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
