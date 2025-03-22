#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 20
int stack[max],top=-1;
void push(int x)
{
    stack[++top]=x;
}
int pop()
{
    if(top==-1)
        return -1;
    int val=stack[top--];
    return val;
}

int res(char a[max])
{
    int A,B,i,num,l;
    char c;
    l=strlen(a); //returns the length of the postfix notation,, i=length
    a[l++] = ')'; //adding closing bracket at the postfix notation
    a[l++] = '\0'; //lastly adding null character at the end of the postfix notation
    for(i=0;a[i]!=')';i++) //traversing until a closing bracket is encountered
    {
        c=a[i]; //scanning and storing characters in to a variable
        if(isdigit(c)) //checking digit or not
        {
            num=c-'0';
            //converting a character into an integer,
            //[i.e. let c='5'=53[in ascii] and '0'=48; c-'0'='5'-'0'=53-48=5
            //getting exact value
            push(num);
        }
        else
        {
            A=pop();
            B=pop();
            switch(c)
            {
            case '+':
                push(B+A);
                break;
            case '-':
                push(B-A);
                break;
            case '*':
                push(B*A);
                break;
            case '/':
                if(A==0)
                    printf("Zero division error");
                else
                    push(B/A);
                break;
            case '^':
                if(A==0)
                    push(1);
                else if(A==1)
                    push(B);
                else
                    while(A--)
                        push(B*B);
                break;
            }
        }
    }
    int x=pop();
    return(x);
}

void main()
{
    char postfix[20];
    int result;
    printf("enter postfix expression:");
    scanf("%s",postfix);
    result=res(postfix);
    printf("%d",result);
}
