#include<stdio.h>
#include<stdlib.h>

struct process
{
int pid;
int atime,btime,wtime,ctime,ttime,bcount;
}p[10];
int completed[10]={0};

void sortA(struct process *a,int n)
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
    printf(" %d\n",i);
      printf("waiting time %d\n",a[i].wtime);
       printf("total time %d\n",a[i].ttime);
    }
}

void main()
{
  printf("Enter the number of process\n");
  int n;
  scanf("%d",&n);
  printf("Enter the quantum time\n");
  int q;
  scanf("%d",&q);
printf("Enter the Arival time and Burst time\n");
  for(int i=0;i<n;i++)
    {
      p[i].pid=i+1;
      scanf("%d",&p[i].atime);
      scanf("%d",&p[i].btime);
      p[i].bcount=p[i].btime%q;
    }
  int currtime=0;
  int k=0,count=0;

  
  int tttime=0;
  int twtime=0;

  while(count!=n)
    {
      for(int i=0;i<n;i++)
        {
          if(currtime>=p[i].atime && !completed[i])
          {
            if(p[i].btime>q)
            {
              p[i].btime-=q;
              currtime+=q;
            }
            else
            {
              completed[i]=1;
              count++;
              p[i].wtime=currtime-p[i].atime-(p[i].bcount>1 ?p[i].bcount*q:0);
              p[i].ctime=currtime;
              p[i].ttime=p[i].ctime-p[i].atime;
              currtime+=p[i].btime;
              tttime+=p[i].ttime;
              twtime+=p[i].wtime;
            }
          }
        }
    }

      
  display(p, n);

  printf("\ntotal waiting time :%d\n", twtime);
  printf("\naverage waiting time :%f\n", (float)twtime / n);
  printf("\ntotal turn around time :%d\n", tttime);
  printf("\naverage turn around time: :%f\n", (float)tttime / n);
      
    }