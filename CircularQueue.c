#include<stdio.h>
#define max 5
int Queue[max];
int front=-1,rear=-1;
void enque(int item)
{
    if(front==(rear+1)%max)
    {
        printf("\nQueue overflow");
        return;
    }
    if(front==-1)
        front=0;
    rear=(rear+1)%max;
    Queue[rear]=item;
    return;
}
int deque()
{
    if(front==-1)
    {
        printf("\nQueue underflow");
        return 0;
    }
    int item=Queue[front];
    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%max;
    return item;
}
void display()
{
    if(front==-1)
        printf("\nQueue is empty");
    else
    {
        int i=front;
        while(i!=rear)
        {
            printf("%d ",Queue[i]);
            i=(i+1)%max;
        }
        printf("%d ",Queue[rear]);
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
