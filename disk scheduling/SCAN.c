#include<stdio.h>
#include<stdlib.h>

int main()
{
  printf("Enter the number of request\n");
  int num;
  scanf("%d",&num);
  int requestArr[num];
  printf("Enter the request sequence\n");
  for(int i=0;i<num;i++)
    {
      scanf("%d",&requestArr[i]);
    }
//  Sort the request
    for(int i=0;i<num;++i)
    {
      for(int j=0;j<num-i-1;++j)
        {
          if(requestArr[j]>requestArr[j+1])
          {
            int temp=requestArr[j];
            requestArr[j]=requestArr[j+1];
            requestArr[j+1]=temp;
          }
        }
    }
     //To print the sorted arr
  for(int i=0;i<num;i++)
    {
      printf("%d ",requestArr[i]);
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
 //to find the index position of the head
int index=0;
  for(int i=0;i<num;i++)
    {
      if(initial<requestArr[i])
      {
        index=i;
      }
    }
  int totalHeadMoment=0;

  if(direction==1)
  {
    for(int j=index;j<num;j++)
      {
        totalHeadMoment+=requestArr[j]-initial;
        initial=requestArr[j];
      }

    totalHeadMoment+=diskSize-1-initial;
    initial=diskSize-1;
    for(int j=index-1;j>=0;j--)
      {
        totalHeadMoment+=initial-requestArr[j];
        initial=requestArr[j];
      }
    
  }
  if(direction==0)
  {
    for(int j=index-1;j>=0;j--)
      {
        totalHeadMoment+=initial-requestArr[j];
        initial=requestArr[j];
      }
    totalHeadMoment+=initial-0;
    initial=0;
    for(int j=index;j<num;j++)
      {
        totalHeadMoment+=requestArr[j]-initial;
        initial=requestArr[j];
      }

    
  }
    printf("The head moment is %d",totalHeadMoment);
  return 0;
  
}