#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
typedef struct node Queue;

Queue* enque(Queue* head)
{
    Queue* newQueue=(Queue*)malloc(sizeof(Queue));
    printf("\nEnter data:");
    scanf("%d",&newQueue->data);
    newQueue->next=NULL;
    if(head==NULL)
    {
        head=newQueue;
        return head;
    }
    Queue* c=head;
    while(c->next!=NULL)
    {
        c=c->next;
    }
    c->next=newQueue;
    return head;
}
Queue*deque(Queue*head)
{
    Queue* temp;
    if(head==NULL)
        printf("Queue Underflow");
    temp=head;
    printf("dequed element=%d",head->data);
    head=head->next;
    free(temp);
    return head;
}
void display(Queue* head)
{
    Queue* c;
    for(c=head;c!=NULL;c=c->next)
    {
        if(c==NULL)
            printf("Queue is Empty");
        else
            printf("%d ",c->data);
    }
}
void main()
{
    Queue* head=NULL;
    int y=1,c;
    while(y)
    {
        printf("\n1.Enque \n2.Deque \n3.Display \n4.Exit \nEnter choice:");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            head=enque(head);
            break;
        case 2:
            head=deque(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            y=0;
            printf("exit");
            break;
        default:printf("incorrect input");
        }
    }
}
