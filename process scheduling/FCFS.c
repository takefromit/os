#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct process{
int pid;
int atime,btime,ttime,ctime,wtime;
}p[10];
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
    printf("waiting time %d\n", a[i].wtime);
    printf("total time %d\n", a[i].ttime);
    }
}

int main()
{
  printf("Enter the number of process\n");
  int n;
  scanf("%d",&n);
  printf("Enter the arival time ,burst time\n");
  for(int i=0;i<n;i++)
    {
      p[i].pid=i+1;
      scanf("%d",&p[i].atime);
      scanf("%d",&p[i].btime);
    }
  sort(p,n);

  int totatime=0;
  int towtwtime=0;

  p[0].wtime=0;
  p[0].ctime=p[0].btime;
  p[0].ttime=p[0].btime;

  totatime=p[0].ctime;

  for(int i=1;i<n;i++)
    {
      p[i].wtime=(p[i].atime>=p[i-1].ctime)?0:(p[i-1].ctime-p[i].atime);
      p[i].ttime=p[i].btime+p[i].wtime;
      p[i].ctime=p[i].btime+p[i].atime+p[i].wtime;

      totatime+=p[i].ttime;
      towtwtime+=p[i].wtime;
    }
  display(p,n);
  printf("\ntotal waiting time :%d", towtwtime);
  printf("\naverage waiting time :%f", (float)towtwtime / n);
  printf("\ntotal turn around time :%d", totatime);
  printf("\naverage turn around time: :%f\n", (float)totatime / n);
  return 0;
}