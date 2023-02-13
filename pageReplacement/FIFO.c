#include <stdio.h>
#include <limits.h>
struct frame
{
 int value;
 int time;
};

int main() {
  printf("Enter the number of pages\n");
  int pno;
  scanf("%d", &pno);
  int pArr[pno];
  int hitCount=0;
  int missCount=0;
  int counterTime=0;
  int flag1=0,flag2=0;
  printf("Enter the pages\n");
  for (int i = 0; i < pno; i++) {
    scanf("%d", &pArr[i]);
  }
  printf("Enter the number of frames\n");
  int fno;
  scanf("%d", &fno);
  struct frame frames[fno];
  for(int k=0;k<fno;k++)
    {
      frames[k].value=-1;
      frames[k].time=-1;
    }
  for(int i=0;i<pno;i++)
    {
      flag1=0,flag2=0;
      for(int j=0;j<fno;j++)
        {
          if(pArr[i]==frames[j].value)
          {
            counterTime++;
            hitCount++;
            // frames[j].time=counterTime;
            printf("Hit\n");
            flag1=1,flag2=1;
          }
        }   
          if(flag1==0)
          {
            for(int j=0;j<fno;j++)
              {
                if(frames[j].value==-1)
            {
               printf("Miss \n");
               frames[j].value=pArr[i];
               counterTime++;
               frames[j].time=counterTime;
               flag2=1;
              break;
            }
              
                }
            } 
            if(flag2==0)
            {
              int lowest=frames[0].time;
              int index=0;
              for(int p=1;p<fno;++p)
                {
                   //printf("-value:%d...-time:%d \n",frames[p].value,frames[p].time);
                  if(frames[p].time<lowest)
                  {
                     lowest=frames[p].time;
                     index=p; 
                    //printf("-----value:%d---time:%d\n",frames[p].value,frames[p].time);
                  }
                }
              printf("Miss \n");
              missCount++;
              frames[index].value=pArr[i];
              counterTime++;
              frames[index].time=counterTime;
              
            }
      for(int t=0;t<fno;t++)
        {
          printf("%d ",frames[t].value);
        }
      printf("\n");
    }
  printf("hit count %d",hitCount);
  printf("miss count %d",missCount);
} 