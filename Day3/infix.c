/*
To check whether a infix expression is correct or not
 Done upto checking the number of Brackets,  operands.
 Done by - Rudra Nil Basu
*/
#include<stdio.h>
int top=-1;
char inf[50];
char s[50];
char inf2[50];

int isoperand(int i)
{
    if(inf2[i]>='a' && inf2[i]<='z')
        return 1;
    return 0; // if not operand
}

int isoperator(int i)
{
    // checking for operator
    if(inf2[i]=='+')
    {
        return 1;
    }
    if(inf2[i]=='-')
    {
        return 1;
    }
    if(inf2[i]=='*')
    {
        return 1;
    }
    if(inf2[i]=='/')
    {
        return 1;
    }
    if(inf2[i]=='^')
    {
        return 1;
    }
    return 0;
}

int rem() // making a copy of infix[] in infix2[] without storing any brackets.
{
    int i,k=0;
    for(i=0;inf[i]!=';';i++)
    {
        if(inf[i]=='(' ||inf[i]==')' ||inf[i]=='{' ||inf[i]=='}' ||inf[i]=='[' ||inf[i]==']' )
        //if(inf[i]!='(' ||inf[i]!=')' ||inf[i]!='{' ||inf[i]!='}' ||inf[i]!='[' ||inf[i]!=']' )
            {
                continue;
            }
            inf2[k++]=inf[i];
    }
    inf2[k]=';';
}

int main()
{
    scanf("%s",inf);
    int i,flag=0,part1=0,part2=1;
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
        part1=0;//printf("Incorrect Bracket placements\n");
    }
    else
    {
        if(top==-1)
        {
            part1=1;
        }
        else
        {
            part1=0;
        }
    }
    inf[strlen(inf)]=';';
    rem();//to remove all brackets
    for(i=0;inf2[i]!=';';i++)
    {
        if(isoperand(i) && isoperand(i+1))
        {
            part2=0;
            break;
        }
        if(inf2[i+1]!=';')
        {
            if( isoperand(i) && isoperator(i+1))
            {
                if(inf2[i+2]==';')
                {
                    part2=0;
                    break;
                }
                else if( !isoperand(i+2) )
                {
                    part2=0;
                    break;
                }
            }
        }
    }
    if( part1 && part2)
    {
        printf("Correct\n");
    }
    else
    {
        printf("Incorrect:/\n");
    }
    return 0;
}
