#include<stdio.h>
#define max 5
int Queue[max],Stack[max];
int top=-1;
int front=-1,rear=-1;

void push(int item)
{
    if(top==max-1)
    {
        printf("Stack overflow!!");
        return;
    }
    Stack[++top]=item;
    return;
}
int pop()
{
    if(top==-1)
    {
        printf("Stack underflow!!");
        return 0;
    }
    int item=Stack[top--];
    return item;
}

void enque(int item)
{
    if(rear==max-1)
    {
        printf("Queue overflow!!");
        return;
    }
    if(front==-1)
        front=0;
    rear++;
    Queue[rear]=item;
    return;
}
int deque()
{
    if(front==-1)
    {
        printf("Queue underflow!!");
        return 0;
    }
    int item=Queue[front];
    if(front==rear)
        front=rear=-1;
    else
        front++;
    return item;
}

void inStack(int Queue,int Stack)
{
    int i;
    for(i=0;i<=max-1;i++)
    {
        int p;
        p=deque();
        push(p);
    }
}

void outStack(int Queue,int Stack)
{
    int i;
    for(i=0;i<=max-1;i++)
    {
        int p=pop();
        enque(p);
    }
}

void main()
{
    int a,n,i,y=1;
    while(y)
    {
        printf("\n1. Enque \n2. Reverse \n3.Display \n4.Exit \nEnter choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("Enter elements in Queue:");
                scanf("%d",&a);
                enque(a);
                break;
            case 2:
                inStack(Queue,Stack);
                outStack(Queue,Stack);
                printf("\nQueue is reversed");
                break;
            case 3:
                for(i=front;i<=rear;i++)
                    printf("\nQueue[i]=%d",Queue[i]);
                break;
            case 4:
                y=0;
                printf("\nProcess is ending...");
                break;
            default:printf("Incorrect input!!");
        }
    }
}

