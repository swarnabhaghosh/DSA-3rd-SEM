/*priority queue*/
#include<stdio.h>
#define size 5
typedef struct
{
    int data[5];
    int prio[5];
    int front;
    int rear;
}queue;

queue q;

void ins(int d,int r)
{
    if(q.rear==size-1)
    {
        printf("\n queue if full.");
        return;
    }
    if(q.front==-1)
    {
          q.front=0;
    }
    q.rear++;
    q.data[q.rear]=d;
    q.prio[q.rear]=r;
}

int max_priority()
{
      int m,i,p;
      m=q.prio[q.front];
      p=q.front;
      for(i=q.front+1;i<=q.rear;i++)
      {
            if(q.prio[i]>m)
            {
                  m=q.prio[i];
                  p=i;
            }
      }
      return p;
}

int del()
{
      int i,x,pos;
      if(q.front==-1)
      {
            printf("\n queue is empty");
            return 0;
      }
      if(q.front==q.rear)
      {
            x=q.data[q.front];
            q.front=-1;
            q.rear=-1;
      }
      else
      {
            pos=max_priority();
            x=q.data[pos];
            for(i=pos;i>q.front;i--)
            {
                  q.data[i]=q.data[i-1];
                  q.prio[i]=q.prio[i-1];
            }
            q.front++;
      }
      return x;
}

void list()
{
      int i;
      if(q.front!=-1)
      printf("\n front=%d rear=%d:\n",q.front,q.rear);
      for(i=q.front;i<=q.rear;i++)
      {
            printf("%d (%d)\n",q.data[i],q.prio[i]);
      }
      return;

}
main()
{
      int d,c,m,r;
      q.front=-1;
      q.rear=-1;
      do
      {
            printf("\n1.insert");
            printf("\n2.delete");
            printf("\n3.exit");
            printf("\n enter your choice:");
            scanf("%d",&c);

            switch(c)
            {
            case 1:
                  printf("\n enter data and priority:");
                  scanf("%d %d",&d,&r);
                  ins(d,r);
                  list();
                  break;
            case 2:
                  m=del();
                  if(m!=0)
                  {
                        printf("\n deleted element:%d ",m);
                        list();
                  }
            }
      }while(c!=3);
}

