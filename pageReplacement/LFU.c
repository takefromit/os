#include<stdio.h>

struct frame{
int value;
int time;
int frequency;
};

int main()
{
  printf("Enter the number of pages\n");
  int pno;
  scanf("%d",&pno);
  printf("Enter the pages\n");
  int pArr[pno];
  for(int i=0;i<pno;i++)
    {
      scanf("%d",&pArr[i]);
    }

  printf("Enter the number of frames\n");
  int fno;
  scanf("%d",&fno);
  
struct frame fArr[fno];
  for(int i=0;i<fno;i++)
    {
      fArr[i].value=-1;
       fArr[i].time=-1;
       fArr[i].frequency=-1;
      
    }
 int hitCount=0;
 int missCount=0;
 int counter=0; 
  for(int i=0;i<pno;i++)
    {
      int flag1=0;int flag2=0;
      for(int j=0;j<fno;j++)
        {
          if(fArr[j].value==pArr[i])
          {
            counter++;
            fArr[j].frequency++;
            flag1=1;
            flag2=1;
            printf("Hit\n");
            hitCount++;
          }
          }
          if(flag1==0)
          {
            for(int k=0;k<fno;k++)
              {
                if(fArr[k].value==-1)
                {
                  counter++;
                  fArr[k].frequency=1;
                   flag2=1;
                   printf("Miss\n");
                   fArr[k].time=counter;
                   missCount++;
                   fArr[k].value=pArr[i];
                  break;
                }
              }
          }
         if(flag2==0)
         {
           int leastfrq=fArr[0].frequency;
          int index=0;
           for(int j=0;j<fno;j++)
             {
               if(leastfrq<fArr[j].frequency)
               {
                 leastfrq=fArr[j].frequency;
                 
               }
             }
           int leastTime=100;
           for(int k=0;k<fno;k++)
             {
               if(leastTime<fArr[k].time &&fArr[k].frequency==leastfrq )
               {
                 index=k;
                 
               }
             }
           printf("Miss\n");
           missCount++;
           counter++;
           fArr[index].time=counter;
           fArr[index].value=pArr[i];
           fArr[index].frequency=1;
           
           
         }
      for(int p=0;p<fno;p++)
        {
          printf("%d ",fArr[p].value);
        }
      printf("\n");
        }
    printf("Hit:%d",hitCount);
    printf("Miss:%d",missCount);

  return 0;
}
