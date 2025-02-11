#include<stdio.h>
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
    int arr[20],a,c,d,n,i,y=1;
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
        printf("\nEnter element to be searched:");
        scanf("%d",&d);
        a=insearch(arr,0,n-1,d);
        if(a!=-1)
            printf("%d found at %d",d,a);
        else
            printf("not found");
        printf("\nEnter y=0 to stop, y=1 to continue:\ny=");
        scanf("%d",&y);
    }
    printf("\nSearch end");
}
