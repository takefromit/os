#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct process{
  int pid;
  int priority;
  int atime,btime,ttime,wtime,ctime;
}p[10];
int completed[10]={0};

void sort(struct process *a,int n)
{
    struct process temp;
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n-i-1;j++)
        {
          if(a[j].atime>a[j+1].atime)
          {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
          }
        }
   } 
}
void display(struct process *a,int n)
{
  for(int i=0;i<n;i++)
    {
      printf("waiting time %d\n",a[i].wtime);
       printf("total time %d\n",a[i].ttime);
    }
}

int main()
{
 printf("Enter the number of process\n");
  int n;
  scanf("%d",&n);

  printf("Enter the process burst time priority and arival time");
    for(int i=0;i<n;i++)
    {
      p[i].pid=i+1;
      scanf("%d",&p[i].atime);
      scanf("%d",&p[i].priority);
      scanf("%d",&p[i].btime);
    }
  int currtime=0;
  int count=0;
  int tttime=0;
  int twtime=0;
  while(count<n)
    {
      int minindex=0;
      int min=1000;
      for(int i=0;i<n;i++)
        {
        if(currtime>=p[i].atime&&!completed[i])
        {
          if(p[i].priority<min)
          {
            min=p[i].priority;
            minindex=i;
          }
        }
          else{
            continue;
          }
          
        }
      p[minindex].wtime=currtime<=p[minindex].atime ? 0:
        currtime-p[minindex].atime;
       p[minindex].ttime=p[minindex].ctime-p[minindex].atime;
    tttime+=p[minindex].ttime;
    twtime+=p[minindex].wtime;
    count++;
    currtime= p[minindex].ctime;
    completed[minindex]=1;
      
    }
  return 0;
  
}