#include<stdio.h>
int a[20],n;
int partition(int lb,int ub)
{
    int start=lb,end=ub,pivot=a[lb],temp;
    while(start<end)
    {
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end)
        {
            temp=a[start];
            a[start]=a[end];
            a[end]=temp;
        }
    }
    temp=a[lb];
    a[lb]=a[end];
    a[end]=temp;
    return end;
}
void quickS(int lb,int ub)
{
    if(lb<ub)
    {
        int loc;
        loc=partition(lb,ub);
        quickS(lb,loc-1);
        quickS(loc+1,ub);
    }
}
void main()
{
    int i;
    printf("\nNo. of elements:");
    scanf("%d",&n);
    printf("\nEnter elements:");
    for(i=0;i<n;i++)
    {
        printf("\na[%d]=",i);
        scanf("%d",&a[i]);
    }
    printf("\nUnsorted Array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    quickS(0,n-1);
    printf("\nSorted Array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
