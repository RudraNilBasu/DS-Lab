/*
Input a sparse matrix in 3 tupple form and find sum and product
Refer this link for better understanding of the pointer notation used in the array in this code : 
http://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
*/
#include<stdio.h>
int main()
{
    int n,i,j;
    printf("Enter the number of rows in the 3-tupple form 1st matrix\n");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*3*sizeof(int));
    //Input the 3 tuppled Matrix
    printf("Enter the 3-tupple form matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
             scanf("%d",(arr + i*3 + j));
        }
    }
    //Convert three tupple to 2D array.
    int r,c;
    r=*(arr +0);
    c=*(arr + 1);
    int **a=(int **)malloc(r*sizeof(int));
    for(i=0;i<r;i++)
    {
        a[i]=(int *)malloc(c*sizeof(int));
    }
    //creating the 2D array
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            a[i][j]=0; // initialising to 0
        }
    }
    int nonzero=*(arr + 2);// storing the number of non zero elements
    int k=1,r1,c1,num1;
    while(nonzero--)
    {
        //fill up the sparse matrix
        r1=*(arr+(k*3)+0);
        c1=*(arr+(k*3)+1);
        num1=*(arr+(k*3)+2);
        k++;
        a[r1][c1]=num1;
    }
    printf("The matrix is:\n"); // Printing the Sparse Matrix
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);//arr[i][j]=count++;
        }
        printf("\n");
    }
    //OTHER MATRIX
    printf("Enter the number of rows in the 3-tupple form 2nd matrix\n");
    scanf("%d",&n);
    int *arr2=(int *)malloc(n*3*sizeof(int));
    printf("Enter the 3-tupple form matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
             scanf("%d",(arr2 + i*3 + j));//*(arr + i*3 + j)
        }
    }
    r=*(arr2 +0);
    c=*(arr2 + 1);
    int **a2=(int **)malloc(r*sizeof(int));
    for(i=0;i<r;i++)
    {
        a2[i]=(int *)malloc(c*sizeof(int));
    }
    //creating the 2D array
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            a2[i][j]=0;
        }
    }
    nonzero=*(arr2 + 2);
    k=1,r1,c1,num1;
    while(nonzero--)
    {
        //fill up
        r1=*(arr2+(k*3)+0);
        c1=*(arr2+(k*3)+1);
        num1=*(arr2+(k*3)+2);
        k++;
        a2[r1][c1]=num1;
    }
    printf("The matrix is:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",a2[i][j]);//arr[i][j]=count++;
        }
        printf("\n");
    }
    //Addition
    printf("ADDITION\n");
    if( *(arr2 +0)!=*(arr +0) && (*(arr2 +1) !=*(arr +1)) )
    {
        printf("NOT COMPATIBLE\n");
    }
    else
    {
        int **add=(int **)malloc(r*sizeof(int));
        for(i=0;i<r;i++)
        {
            add[i]=(int *)malloc(c*sizeof(int));
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
               add[i][j]=a[i][j]+a2[i][j];
            }
        }
        printf("The Added matrix is:\n");
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                printf("%d ",add[i][j]);//arr[i][j]=count++;
            }
            printf("\n");
        }
    }
    //MULTIPLICATION
    printf("MULTIPLICATION\n");
    if( *(arr +1) != *(arr2 +0) )
    {
        printf("NOT COMPATIBLE\n");
    }
    else
    {
        int rm,cm;
        rm=*(arr+0);
        cm=*(arr2+1);
        int **mult=(int **)malloc(rm*sizeof(int));
        for(i=0;i<rm;i++)
        {
            mult[i]=(int *)malloc(cm*sizeof(int));
        }
        int sum=0,c,d,k;
        for(c=0;c<rm;c++) // m,q,p
		{
			for(d=0;d<cm;d++)
			{
				for(k=0;k<*(arr2+0);k++)
				{
					sum=sum+ a[c][k]*a2[k][d];
				}
				mult[c][d]=sum;
				sum=0;
			}
		}
		printf("The Multiplied matrix is:\n");
        for(i=0;i<rm;i++)
        {
            for(j=0;j<cm;j++)
            {
                printf("%d ",mult[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
