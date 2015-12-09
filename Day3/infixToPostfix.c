// Convert Infix To Postfix
// Considering the input infix to be a correct one

#include<string.h>
#include<stdio.h>
#define intin(x) scanf("%d",&x)
#define input(x) scanf("%s",x)
#define RUNBF(i,a,b) for(i=a;i<b;i++)
#define RUN(i,a,b) for(i=a;i<=b;i++)
#define newline printf("\n")
#define printc(x) printf("%c",x)
#define RNB printf("Done by : Rudra Nil Basu\n")

char inf[50];
char s[50];
int top=-1;

int operatorPresent()
{
    int i;
    RUN(i,0,top) // checking if more operators are present
    {
        if(s[i]=='+' ||s[i]=='-' ||s[i]=='*' ||s[i]=='*' ||s[i]=='/' ||s[i]=='*')
            return 1;
    }
    return 0;
}

int priority(char c)
{
       int mo=0;
       if(c=='$'||c=='^')
       mo=5;
       if(c=='*'||c=='/'||c=='%')
       mo=4;
       if(c=='+'||c=='-')
       mo=3;
       if(c=='(')
       mo=1;
       return mo;
}

int main()
{
    printf("Enter No of Test Cases\n");
    int t,i;
    intin(t);
    while(t--)
    {
        top=-1;
        printf("Enter the infix expression\n");
        input(inf);
        RUNBF(i,0,strlen(inf))
        {
            if(inf[i]>='a' && inf[i]<='z')
            {
                printf("%c",inf[i]);
            }
            else if(inf[i]=='(')
            {
                s[++top]='(';
                while(1)
                {
                    i++;
                    if(inf[i]>='a' && inf[i]<='z')
                    {
                        printf("%c",inf[i]);
                    }
                    else if(inf[i]=='+' ||inf[i]=='-' ||inf[i]=='*' ||inf[i]=='*' ||inf[i]=='/' ||inf[i]=='*')
                    {
                        s[++top]=inf[i];
                    }
                    else if(inf[i]==')')
                        break;
                }
                while(s[top]!='(')
                {
                    printc(s[top]);
                    top--;
                }
                top--;
            }
            else if(inf[i]=='+' ||inf[i]=='-' ||inf[i]=='*' ||inf[i]=='*' ||inf[i]=='/' ||inf[i]=='*')
            {
                while(1)
                {
                    if(top==-1)
                    {
                        s[++top]=inf[i];
                        break;
                    }
                    else
                    {
                        if(operatorPresent())
                        {
                            //checking proprity of incoming and topmost
                            if( priority(inf[i]) > priority(s[top]) )
                            {
                                s[++top]=inf[i];
                                break;
                            }
                            else
                            {
                                char ch=s[top];
                                printc(ch);
                                top--;
                            }
                        }
                    }
                }
            }
        }
        while(top>(-1))
        {
            printc(s[top]);
            top--;
        }
        newline;
    }
    RNB;
}
