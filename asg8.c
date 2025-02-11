#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff,exp;
    struct node* next;
};
typedef struct node node;

node* createnode(node* start)
{
    int co,ex;
    int y;
    node* newnode;
    node* c;
    do
    {
        printf("\nEnter coefficient:");
        scanf("%d",&co);
        printf("\nEnter exponent:");
        scanf("%d",&ex);
        newnode=(node*)malloc(sizeof(node));
        newnode->coeff=co;
        newnode->exp=ex;
        newnode->next=NULL;
        if(start==NULL)
            start=newnode;
        else
        {
            c=start;
            while(c->next!=NULL)
            {
                c=c->next;
            }
            c->next=newnode;
        }
        printf("\ny=0 for continue, y=-1 for stop\ny=");
        scanf("%d",&y);
    }while(y!=-1);
    return start;
}
node* addnode(node* start,int coef,int exp)
{
    int y;
    node* newnode;
    node* c;
    newnode=(node*)malloc(sizeof(node));
    newnode->coeff=coef;
    newnode->exp=exp;
    newnode->next=NULL;
    if(start==NULL)
        start=newnode;
    else
    {
        c=start;
        while(c->next!=NULL)
        {
            c=c->next;
        }
        c->next=newnode;
    }
    return start;
    printf("\ny=0 for continue, y=-1 for stop\ny=");
    scanf("%d",&y);
}
node* addpoly(node* p1,node* p2,node* p3)
{
    int i;
    node* ptr1,*ptr2;
    ptr1=p1;ptr2=p2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->exp>ptr2->exp)
        {
            p3=addnode(p3,ptr1->coeff,ptr1->exp);
            ptr1=ptr1->next;
        }
        else if(ptr2->exp>ptr1->exp)
        {
            p3=addnode(p3,ptr2->coeff,ptr2->exp);
            ptr2=ptr2->next;
        }
        else
        {
            i=ptr1->coeff+ptr2->coeff;
            p3=addnode(p3,i,ptr1->exp);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
    if(ptr1==NULL)
    {
        while(ptr2!=NULL)
        {
            p3=addnode(p3,ptr2->coeff,ptr2->exp);
            ptr2=ptr2->next;
        }
    }
    if(ptr2==NULL)
    {
        while(ptr1!=NULL)
        {
            p3=addnode(p3,ptr1->coeff,ptr1->exp);
            ptr1=ptr1->next;
        }
    }
    return p3;
}
void display(node* start)
{
    node* c=start;
    while(c!=NULL)
    {
        if(c->exp==1)
            printf("%dx",c->coeff);
        else if(c->exp==0)
            printf("%d",c->coeff);
        else
            printf("\n%dx^%d",c->coeff,c->exp);
        if(c->next!=NULL)
            printf("+");
        c=c->next;
    }
}

void main()
{
    node *ptr1=NULL,*ptr2=NULL,*ptr3=NULL;
    printf("\nEnter 1st polynomial:");
    ptr1=createnode(ptr1);
    display(ptr1);
    printf("\n___________________________________________________");
    printf("\nEnter 2nd polynomial:");
    ptr2=createnode(ptr2);
    display(ptr2);
    printf("\n___________________________________________________");
    ptr3=addpoly(ptr1,ptr2,ptr3);
    printf("\nResult=");
    display(ptr3);
}
