#include<stdio.h>
int a[20],n;
void selectionS()
{
    int min,loc,i,j;
    for(i=0;i<n;i++)
    {
        min=a[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                loc=j;
            }
        }
        if(i!=loc)
        {
            int t;
            t=a[i];
            a[i]=a[loc];
            a[loc]=t;
        }
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
    selectionS();
    printf("\nSorted array:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
