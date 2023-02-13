#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct process{
int pid;
int atime,btime,wtime,ttime,ctime;
}p[10];
int completed[10]={0};
void sort(struct process *a,int n)
{
  struct process temp;
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n-i-1;j++)
        {
          temp=a[j];
          a[j]=a[j+1];
          a[j+1]=temp;
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

  for(int i=0;i<n;i++)
    {
      p[i].pid=i+1;
      scanf("%d %d",&p[i].atime,&p[i].btime);
    }
  sort(p,n);

  int currtime=0;
  int count=0;
  int ttatime=0;
  int twtime=0;

while(count<n){
  int min=1000;
  int minIndex=0;
  for(int i=0;i<n;i++)
    {
    if(p[i].atime<currtime&&!completed[i])
      {
        if(p[i].btime<min)
        {
          minIndex=i;
          min=p[i].btime;
        }
      }
      else
      {
        continue;
      }
    }
  p[minIndex].wtime=currtime>p[minIndex].atime ? 0:currtime-p[minIndex].atime;
  p[minIndex].ttime=p[minIndex].btime+p[minIndex].wtime;
  p[minIndex].ctime=p[minIndex].btime+p[minIndex].wtime+p[minIndex].atime;
  completed[minIndex]=1;
  ttatime+=p[minIndex].ttime;
  twtime+=p[minIndex].wtime;
  count++;
  currtime=p[minIndex].ctime;
  }
  display(p, n);

  printf("\ntotal waiting time :%d\n", twtime);
  printf("\naverage waiting time :%f\n", (float)twtime / n);
  printf("\ntotal turn around time :%d\n", ttatime);
  printf("\naverage turn around time: :%f\n", (float)ttatime / n);
  return 0;
}