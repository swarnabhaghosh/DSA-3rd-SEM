#include<stdio.h>
int lsearch(int arr[20],int d,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==d)
            return i+1;
    }
    return -1;
}
int bsearch(int arr[20],int low,int high,int d)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(d==arr[mid])
        {
            return mid+1;
        }
        else if(d>arr[mid])
        {
            return bsearch(arr,mid+1,high,d);
        }
        else
        {
            return bsearch(arr,low,mid-1,d);
        }
    }
    return -1;
}
int insearch(int arr[20],int low,int high,int d)
{
    int pos;
    while(low<=high)
    {
        pos=low+(((d-arr[low])*(high-low))/(arr[high]-arr[low]));
        if(d==arr[pos])
        {
            return pos+1;
        }
        else if(d>arr[pos])
        {
            return insearch(arr,pos+1,high,d);
        }
        else
        {
            return insearch(arr,low,pos-1,d);
        }
    }
    return -1;
}
void main()
{
    int arr[20],a,b,c,d,i,n,y=1;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    printf("\nEnter elements:");
    for(i=0;i<n;i++)
    {
        //printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
    }
    printf("\nArray:");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    while(y)
    {
        printf("\n1. Linear search \n2. Binary search \n3. Interpolation search \n4. Exit \nEnter choice:");
        scanf("%d",&c);
        if(c==1 || c==2 || c==3)
        {
            printf("\nEnter element to be searched:");
            scanf("%d",&d);
        }
        switch(c)
        {
        case 1:
            a=lsearch(arr,d,n);
            if(a!=-1)
                printf("%d found at %d",d,a);
            else
                printf("not found");
            break;
        case 2:
            a=lsearch(arr,d,n);
            if(a!=-1)
                printf("%d found at %d",d,a);
            else
                printf("not found");
            break;
        case 3:
            a=lsearch(arr,d,n);
            if(a!=-1)
                printf("%d found at %d",d,a);
            else
                printf("not found");
            break;
        case 4:
            y=0;
            printf("\nSeaching ended");
            break;
        default:
            printf("Incorrect input");
        }
    }
}
