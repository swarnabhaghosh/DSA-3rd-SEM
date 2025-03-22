#include<stdio.h>
#define max 5
int Queue[max];
int front=-1,rear=-1;
void enque(int item)
{
    if(rear==max-1)
    {
        printf("\nQueue overflow");
        return;
    }
    if(front==-1)
        front=0;
    Queue[++rear]=item;
    return;
}
int deque()
{
    if(front==-1 && rear==-1||front>rear)
    {
        printf("\nQueue underflow");
        return 0;
    }
    int item=Queue[front++];
    return item;
}
void display()
{
    if(front==-1 && rear==-1)
        printf("\nQueue is empty");
    else
    {
        int i;
        for(i=front;i<=rear;i++)
        {
            printf("%d ",Queue[i]);
        }
    }
}
void main()
{
    int a,b,c,d,y=1;
    while(y)
    {
        printf("\n1. Enque \n2. Deque \n3. Display \n4. Exit \nEnter choice:");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("\nEnter element:");
            scanf("%d",&a);
            enque(a);
            break;
        case 2:
            d=deque();
            printf("\nDequeued element=%d",d);
            break;
        case 3:
            display();
            break;
        case 4:
            y=0;
            printf("Ended");
            break;
        default:
            printf("Incorrect input");
        }
    }
}
