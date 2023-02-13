#include<stdio.h>
#include<stdlib.h>

struct process{
int a,b,c;
};
struct process alloc[10],max[10],need[10],total;
int selected[10]={0};

int main()
{
  printf("Enter the number of process\n");
  int num;
  scanf("%d",&num);
  printf("Enter the total number of resource availabe\n");
  scanf("%d",&total.a);
  scanf("%d",&total.b);
  scanf("%d",&total.c);

  for (int i = 0; i < num; i++) {
    printf("Process %d:\n", i);
    printf("Enter the number of resource alocated to each process");
    scanf("%d %d %d", &alloc[i].a, &alloc[i].b, &alloc[i].c);
    printf("Enter the maximum number of resource  required for each process");
    scanf("%d %d %d", &max[i].a, &max[i].b, &max[i].c);
    need[i].a = max[i].a - alloc[i].a;
    need[i].b = max[i].b - alloc[i].b;
    need[i].c = max[i].c - alloc[i].c;
    printf("need a=%d,b=%d,c=%d:\n", need[i].a, need[i].b, need[i].c);
  }

  int count=0;
   int check=0;
  while(count<num)
    {
      for(int i=0;i<num;i++)
     {
       if(need[i].a<=total.a && need[i].b<=total.b && need[i].c<=total.c)
       {
         total.a+=max[i].a;
         total.b+=max[i].b;
         total.c+=max[i].c;
         check=0;
         count++;
       }
       else{
         check++;
       }
       
      if(check>=num)
      {
        if (check == num) {
        printf("The execution is not possible %d %d\n ", i, check);
        exit(0);
      } 
      }
     }
        printf("The execution is possible\n");
    }
  
  
  return 0;
}