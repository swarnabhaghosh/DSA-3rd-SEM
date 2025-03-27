#include<stdio.h>

void siftDown (int numbers[], int root, int bottom);
void heapsort (int numbers[], int array_size);

int main()
{
    int n,i,a[20];
    printf("\n How many number ?");
    scanf ("%d",&n);
    printf("\n enter numbers :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    heapsort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%5d",a[i]);
    }
}

void heapsort(int numbers[],int n)
{
    int i,temp;
    for(i=(n/2)-1;i>=0;i--)
    {
        siftDown(numbers,i,n-1);
    }
    for(i=n-1;i>=1;i--)
    {
        temp=numbers[0];
        numbers[0]=numbers[i];
        numbers[i]=temp;
        siftDown(numbers,0,i-1);
    }
}

void siftDown(int numbers[],int root,int bottom)
{
    int flag,maxChild,temp;
    flag=1;
    while((root*2+1<=bottom) && (flag==1))
    {
        if(root*2+1==bottom)
            maxChild=root*2+1;
        else if(numbers[root*2+1]>numbers[root*2+2])
            maxChild=root*2+1;
        else
            maxChild=root*2+2;

        if(numbers[root]<numbers[maxChild])
        {
            temp=numbers[root];
            numbers[root]=numbers[maxChild];
            numbers[maxChild]=temp;
            root=maxChild;
        }
        else
            flag=0;
    }
}
