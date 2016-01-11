// To Calculate the value of a postfix expression

#include<stdio.h>
#define intin(x) scanf("%d",&x)
#define in(x) scanf("%s",x)
#define RUNBF(i,a,b) for(i=a;i<b;i++)
#define RNB printf("Done by Rudra Nil Basu\n")

char pf[50];
int s[50];  // creating an array of size 50 (serving as stack)
int top=-1;

int isnum(char ch)
{
    if(ch>='0' && ch<='9')
        return 1; // returning 1 if ch is a number
    return 0;
}

int main()
{
    int t,i,res=0;
    printf("Enter no of test cases\n");
    intin(t);
    while(t--)
    {
        res=0;
        printf("Enter the postfix expression. Beware, typing any wrong expression is your fault.\n");
        in(pf);
        top=-1; // Re-initialising stack
        RUNBF(i,0,strlen(pf))
        {
            if( isnum(pf[i] ) ) // if pf[i] is a number
               {
                   s[++top]=(pf[i]-48); // converting the number from character to integer format
               }
               if(pf[i]=='+')
               {
                   int a=s[top];
                   top--;
                   int b=s[top];
                   top--;
                   res=a+b;
                   s[++top]=res;
               }
               else if(pf[i]=='*')
               {
                   int a=s[top];
                   top--;
                   int b=s[top];
                   top--;
                   res=a*b;
                   s[++top]=res;
               }
               else if(pf[i]=='-')
               {
                   int a=s[top];
                   top--;
                   int b=s[top];
                   top--;
                   res=a-b;
                   s[++top]=res;
               }
               else if(pf[i]=='/')
               {
                   int a=s[top];
                   top--;
                   int b=s[top];
                   top--;
                   res=a/b;
                   s[++top]=res;
               }
        }
        printf("Result is %d\n",res);
    }
    RNB;
    return 0;
}
