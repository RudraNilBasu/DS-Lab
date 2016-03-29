//Calculating Memory Address
/*
NOTE : it was considered here that the size of the matrix is 3X3
*/
#include<stdio.h>
int main()
{
	int ba,c,x,i,j;
	printf("Choose an option\n1.Row Major.\n2.Column Major");
	scanf("%d",&c);
	printf("Enter BA\n");
	scanf("%d",&ba);
	printf("Enter i and j\n");
	scanf("%d %d",&i,&j);
	if(c==1) // if row major 
	{
		x=ba+((i*3)+j)*sizeof(int); 
	}
	else  // if column major
	{
		x=ba+((j*3)+i)*sizeof(int);
	}
	printf("Ans = %d",x);
}
