//To check whether a infix expression is correct or not
// Done upto checking the number of Brackets, not operands, so it is a WIP :P 
#include<stdio.h>
#include<string.h>

char s[50];
char inf[50];

int top=-1;


int main()
{
	printf("Enter the infix expression\n");
	scanf("%s",inf);
	int i;
	for(i=0;i<strlen(inf);i++)
	{
		if(inf[i]=='(')
		{
			inf[++top]='(';
		}
		else if(inf[i]=='[')
		{
			inf[++top]='[';
		}
		else if(inf[i]==')')
		{
			top--;
		}
		else if(inf[i]==']')
		{
			top--;
		}
	}
	if(top==-1)
	{
		printf("Correct\n");
	}
	else
	{
		printf("Not correct\n");
	}
}
