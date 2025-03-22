#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
typedef struct node node;

node* insbeg(node* head)
{
    node* newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the data:");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    return head;
}
node* insend(node *head)
{
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    node* c=head;
    while(c->next!=NULL)
    {
        c=c->next;
    }
    c->next=newnode;
    return head;
}

void inspos(node* head)
{
    int pos,i=0;
    node* newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    printf("\nEnter the position:");
    scanf("%d",&pos);
    node* c=head;
    while(c!=NULL)
    {
        i++;
        if(i==pos-1)
        {
            newnode->next=c->next;
            c->next=newnode;
            return;
        }
        c=c->next;
    }
}

void insnode(node *head)
{
    if(head==NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    int x;
    node* newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the data:");
    scanf("%d",&newnode->data);
    printf("\nEnter the node after which enter:");
    scanf("%d",&x);
    node* c=head;
    while(c!=NULL)
    {
        if(x==c->data)
        {
            newnode->next=c->next;
            c->next=newnode;
            return;
        }
        c=c->next;
    }
}

node* delbeg(node* head)
{
    if(head==NULL)
    {
        printf("The list is empty.\n");
        return NULL;
    }
    node* temp;
    temp=head;
    head=head->next;
    free(temp);
    return head;
}

node* delend(node* head)
{
    if(head==NULL)
    {
        printf("The list is empty.\n");
        return NULL;
    }
    node* prevnode;
    node* c=head;
    while(c->next!=NULL)
    {
        prevnode=c;
        c=c->next;
    }
    if(c==head)
        head=NULL;
    else
        prevnode->next=NULL;
    free(c);
    return head;
}

void delpos(node* head)
{
    if(head==NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    node* nextnode;
    node* c=head;
    int i=1,pos;
    printf("\nEnter the position:");
    scanf("%d",&pos);
    while(i<pos-1)
    {
        c=c->next;
        i++;
    }
    nextnode=c->next;
    c->next=nextnode->next;
    free(nextnode);
    return;
}

void list(node* head)
{
    node* c=head;
    if(head==NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    while(c!=NULL)
    {
        printf("|%d|%u|",c->data,c->next);
        if(c->next!=NULL)
            printf("-->");
        c=c->next;
    }
}


void main()
{
    node* head=NULL;
    int y=1,c;
    while(y)
    {
        printf("\n1.insert in begin \n2.insert in position \n3.insert after \n4.insert at end \n5.del from begin \n6.del from position \n7.del from end \n8.list \n9.Exit \nEnter choice:");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            head=insbeg(head);
            break;
        case 2:
            inspos(head);
            break;
        case 3:
            insnode(head);
            break;
        case 4:
            head=insend(head);
            break;
        case 5:
            head=delbeg(head);
            break;
        case 6:
            delpos(head);
            break;
        case 7:
            head=delend(head);
            break;
        case 8:
            list(head);
            break;
        case 9:
            printf("End");
            y=0;
            break;
        default:
            printf("invalid");
        }
    }
}
