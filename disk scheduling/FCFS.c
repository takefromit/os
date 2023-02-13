#include<stdio.h>
#include<stdlib.h>

int main()
{
  printf("Enter the number of requests\n");
  int num;
  scanf("%d",&num);
  int requestArr[num];
  printf("Enter the request\n");
  for(int i=0;i<num;i++)
    {
      scanf("%d",&requestArr[i]);
    }
  printf("Enter the head point\n");
  int head;
  scanf("%d",&head);
  int totalHeadMoment=0;
  for(int i=0;i<num;i++)
    {
      totalHeadMoment=totalHeadMoment+abs(requestArr[i]-head);
      head=requestArr[i];
    }
  
 printf("The total head movement is:%d\n",totalHeadMoment);
  
  return 0;
}