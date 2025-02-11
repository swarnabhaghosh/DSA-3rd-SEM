#include<stdio.h>
int a[20],n;
void merge(int l,int m,int h)
{
    int b[20];
    int i=l,j=m+1,k=l;
    while(i<=m && j<=h)
    {
        if(a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }
    }
    while(i<=m)
    {
        b[k++]=a[i++];
    }
    while(j<=h)
    {
        b[k++]=a[j++];
    }
    for(i=l;i<=h;i++)
        a[i]=b[i];
}
void mergeS(int l,int h)
{
    if(l<h)
    {
        int m=(l+h)/2;
        mergeS(l,m);
        mergeS(m+1,h);
        merge(l,m,h);
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
    mergeS(0,n-1);
    printf("\nSorted Array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
