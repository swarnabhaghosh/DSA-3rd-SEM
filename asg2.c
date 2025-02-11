#include<stdio.h>
#define max 5
int Stack[max];
int top=-1;

void push(int item)
{
    if(top==max-1)
    {
        printf("Stack overflow");
        return;
    }
    Stack[++top]=item;
    return;
}
int pop()
{
    if(top==-1)
    {
        printf("Stack underflow");
        return 0;
    }
    int item=Stack[top--];
    return item;
}
void display()
{
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        for(int i=top;i>=0;i--)
            printf("%d \n",Stack[i]);
    }
}
void main()
{
    int a,b,c,d,y=1;
    while(y)
    {
        printf("\n1. Push \n2. Pop \n3. Display \n4. Exit \nEnter choice:");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("\nEnter element:");
            scanf("%d",&a);
            push(a);
            break;
        case 2:
            d=pop();
            printf("\nPopped element=%d",d);
            break;
        case 3:
            display();
            break;
        case 4:
            y=0;
            printf("Exit");
            break;
        default:printf("Incorrect input");
        }
    }
}
