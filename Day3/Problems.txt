Problems for Day 3 : 
i) Implementation of stack using array showing push pop display
ii) Check whether a given infix expression is correct or not
iii) Infix to postfix conversion
iv) Evaluate a given postfix expression
v) Implement Queue using array showing - insert , remove and display operations

Infix To Postfix Algo - http://www.c4learn.com/data-structure/algorithm-for-infix-to-postfix-conversion-using-stack/


Algorithm for Conversion Of An Expression From Infix to Postfix

Consider -
    Stack S
    Char  ch
    Char  element
while(Tokens are Available)
 {
     ch = Read(Token);
     if(ch is Operand)
       {
       Print ch ;
       }
     else
       {
       while(Priority(ch) <= Priority(Top Most Stack))
            {
            element = Pop(S);
            Print(ele);
            }
       Push(S,ch);
       }
}
while(!Empty(S))
{
element = Pop(S);
Print(ele);
}
Explanation :

In this Algorithm we are reading token from Left to Right and Postfix expression is generated. [See What is Postfix ? ]
So Entered Token may be –
Alphabet from A-Z or a-Z
Numerical Digit from 0-9
Operator
Opening And Closing Braces ( , )
If Entered Character is Alphabet then Following Action Should be taken-
Print Alphabet as Output
If Entered Character is Digit then Following Action Should be taken-
Print Digit as Output
If Entered Character is Opening Bracket then Following Action Should be taken-
Push ‘(‘ Onto Stack
If any Operator Appears before ‘)’ then Push it onto Stack.
If Corresponding ‘)’ bracket appears then Start Removing Elements [Pop] from Stack till ‘(‘ is removed.
If Entered Character is Operator then Following Action Should be taken-
Check Whether There is any Operator Already present in Stack or not.
If Stack is Empty then Push Operator Onto Stack.
If Present then Check Whether Priority of Incoming Operator is greater than Priority of Topmost Stack Operator.
If Priority of Incoming Operator is Greater then Push Incoming Operator Onto Stack.
Else Pop Operator From Stack again goto Step 6.
