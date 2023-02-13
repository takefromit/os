#include<stdio.h>
#include<stdlib.h>

int main()
{
  printf("Enter the Number of request\n");
  int reqsNo=0;
  scanf("%d",&reqsNo);

  printf("Enter the request in sequence\n");
  int reqArr[reqsNo];
 //printf("ttttt");
  for(int i=0;i<reqsNo;i++)
    {
      scanf("%d",&reqArr[i]);
    }
  //  Sort the request
  for(int i=0;i<reqsNo;++i)
    {
      for(int j=0;j<reqsNo-i-1;++j)
        {
          if(reqArr[j]>reqArr[j+1])
          {
            int temp=reqArr[j];
            reqArr[j]=reqArr[j+1];
            reqArr[j+1]=temp;
          }
        }
    }
    //To print the sorted arr
  for(int i=0;i<reqsNo;i++)
    {
      printf("%d ",reqArr[i]);
    }
  printf("\n");

  printf("Enter the initial head position\n");
  int initial=0;
  scanf("%d",&initial);

  printf("Enter the total disk size\n");
  int diskSize=0;
  scanf("%d",&diskSize);

  printf("Enter the disk moment direction 1 for high and 0 for low\n");
  int direction=0;
   scanf("%d",&direction);

  int index=0;
  for(int k=0;k<reqsNo;k++)
    {
      if(initial<reqArr[k])
      {
        index=k;
        break;
        //printf("inside index:%d\n",index);
      }
    }
  int totalHeadMoment=0;

if(direction==1)
{
  for(int j=index;j<reqsNo;j++)
    {
      totalHeadMoment+=reqArr[j]-initial;
      initial=reqArr[j];
    }
  totalHeadMoment+=diskSize-1-initial;
  initial=diskSize-1;
  totalHeadMoment+=initial-0;
  initial=0;

  for(int j=0;j<index;j++)
    {
      totalHeadMoment+=reqArr[j]-initial;
      initial=reqArr[j];
    }
  
}
if(direction==0)
{
  for(int j=index-1;j>0;j++)
    {
      totalHeadMoment+=initial-reqArr[j];
      initial=reqArr[j];
    }
  totalHeadMoment+=initial-0;
  initial=0;
  totalHeadMoment+=diskSize-1-initial;
  initial=diskSize-1;

  for(int j=reqsNo-1;j>=index;j--)
    {
      totalHeadMoment+=initial-reqArr[j];
      initial=reqArr[j];
    }
  
}  
  printf("The totalMoment Disk:%d\n",totalHeadMoment); 
  return 0;
  
}