//To check whether a infix expression is correct or not
// Done upto checking the number of Brackets, not operands, so it is a WIP :P 
//TODO : Check if the popped element is the openning of the closing bracket type, if no, then WA [DONE]
#include<stdio.h>
int top=-1;
char inf[50];
char s[50];

int main()
{
    scanf("%s",inf);
    int i,flag=0;
    for(i=0;i<strlen(inf);i++)
    {
        if(inf[i]=='(')
		{
			s[++top]='(';
		}
		else if(inf[i]=='[')
		{
			s[++top]='[';
		}
		else if(inf[i]=='{')
		{
			s[++top]='{';
		}
		else if(inf[i]==')')
		{
			if(s[top]!='(')
            {
                flag=1;
                break;
            }
            top--;
		}
		else if(inf[i]==']')
		{
			if(s[top]!='[')
            {
                flag=1;
                break;
            }
            top--;
		}
		else if(inf[i]=='}')
		{
			if(s[top]!='{')
            {
                flag=1;
                break;
            }
            top--;
		}
    }
    if(flag==1)
    {
        printf("Incorrect Bracket placements\n");
    }
    else
    {
        if(top==-1)
        {
            printf("Correct.\n");
        }
        else
        {
            printf("Not Correct.\n");
        }
    }
    return 0;
}
