#include<stdio.h>
int arr[20],n;
void read()
{
    int i;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("\nEnter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}
void insert()
{
    int pos,item;
    printf("Enter value to be entered: ");
    scanf("%d",&item);
    printf("Enter position: ");
    scanf("%d",&pos);
    for(int i=n-1;i>=pos-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos-1]=item;
    n++;
    printf("%d is entered at %d",item,pos);
}
int lsearch()
{
    int i,x;
    printf("\nEnter the searching element:");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
            return i;
    }
    return -1;
}
int delete()
{
    int pos,i,item;
    printf("Enter position: ");
    scanf("%d",&pos);
    item=arr[pos-1];
    for(i=pos-1;i<n-1;i++)
    {
            arr[i]=arr[i+1];
    }
    n--;
    return item;
}
void display()
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
void main()
{
    read();
    int y=1,a,c,pos;
    while(y)
    {
        printf("\n1. Insert \n2. delete \n3. Display \n4. Linear search \n5. Exit \nEnter your choice:");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            insert();
            break;
        case 2:
            a=delete();
            printf("\nDeleted item=%d",a);
            break;
        case 3:
            display();
            break;
        case 4:
            pos=lsearch();
            if(pos==-1)
                printf("\nElement not found");
            else
                printf("\nElement found at %d",pos+1);
            break;
        case 5:
            y=0;
            printf("Exit");
            break;
        default:printf("\nIncorrect input");
        }
    }
}
