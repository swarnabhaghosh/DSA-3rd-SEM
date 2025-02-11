#include<stdio.h>
int a[20],n;
void insertionS()
{
    int i,j;
    for(i=1;i<n;i++)
    {
        int temp;
        temp=a[i];
        j=i-1;
        while(j>=0 && temp<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
void main()
{
    int i;
    printf("\nEnter no. of elements:");
    scanf("%d",&n);
    printf("\nEnter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    insertionS();
    printf("\nSorted array:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
