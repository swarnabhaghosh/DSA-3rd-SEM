#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
typedef struct node Stack;

Stack* push(Stack* head)
{
    Stack* newStack=(Stack*)malloc(sizeof(Stack));
    printf("\nEnter data:");
    scanf("%d",&newStack->data);
    newStack->next=head;
    head=newStack;
    return head;
}

Stack* pop(Stack* head)
{
    if(head==NULL)
    {
        printf("\nStack underflow");
        return 0;
    }
    Stack* temp;
    temp=head;
    printf("\nPopped element=%d",temp->data);
    head=head->next;
    free(temp);
    return head;
}

void display(Stack* head)
{
    if(head==NULL)
        printf("Stack is empty");
    else
    {
        Stack* c=head;
        while(c!=NULL)
        {
            printf("%d ",c->data);
            c=c->next;
        }
    }
}

void main()
{
    Stack* head=NULL;
    int y=1,c;
    while(y)
    {
        printf("\n1. Push \n2. Pop \n3. Display \n4. Exit \nEnter choice:");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            head=push(head);
            break;
        case 2:
            head=pop(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            y=0;
            printf("\nEnded");
            break;
        default:
            printf("Incorrect input");
        }
    }
}
