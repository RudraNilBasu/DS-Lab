// merging two arrays in sorted order without using any sorting technique

#include<stdio.h>

int main()
{
	printf("Thou art RNBfied\n");
	int a[10],b[5],c[15]; // first array -10 elements. second array - 5 elements.
	int lol=0,pos=0,posa=0,posb=0,yolo=0; // posa is the current position in array a[]. posb is the current position in array b[].
	printf("Insert 10 elements in 1st array in sorted order\n");
	int i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Insert 5 elements in 2nd array in sorted order\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&b[i]);
	}
	// merging
	while(pos!=15)
	{
		
			if(a[posa]<b[posb])
			{
					//posa++;
					c[pos++]=a[posa++];
					if(posa>9)
					{
						for(i=posb;i<5;i++)
						{
							c[pos++]=b[i];
						}
						break;
					}
			}
			else
			{
				c[pos++]=b[posb++];
				if(posb>5)
				{
					yolo=1;
					for(i=posa;i<10;i++)
					{
						c[pos++]=a[i];
					}
					break;
				}
			}
		//}
	}
	for(i=0;i<15;i++)
	{
		printf("%d\n",c[i]);
	}
}
