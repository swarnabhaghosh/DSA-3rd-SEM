#include<stdio.h>
#include <ctype.h>
#define max 10
int Stack[max],top=-1;
void push(char x)
{
    if(top==max-1)
        printf("\nStack overflow");
    Stack[++top]=x;
}
char pop()
{
    if(top==-1)
        printf("\nStack underflow");
    int ele=Stack[top--];
    return ele;
}
int precedence(char x)
{
    if(x=='+'||x=='-')
        return 1;
    if(x=='*'||x=='/')
        return 2;
    if(x=='^')
        return 3;
    return 0;
}
void in2post(char exp[max])
{
    int i,j=0;
    char c;
    char res[max];
    for(i=0;exp[i]!='\0';i++)
    {
        c=exp[i];
        if(isalnum(c))
            res[j++]=c;
        else if(c=='(')
            push(c);
        else if(c==')')
        {
            while(top!=-1 && Stack[top]!='(')
                res[j++]=pop();
            if(Stack[top]=='(')
                pop();
        }
        else
        {
            while(top!=-1 && precedence(c)<=precedence(Stack[top]))
                res[j++]=pop();
            push(c);
        }
    }
    while(top!=-1)
        res[j++]=pop();
    res[j]='\0';
    printf("%s",res);
}
void main()
{
    char exp[max],res[max];
    printf("\nEnter Infix expression:");
    scanf("%s",exp);
    in2post(exp);
}
