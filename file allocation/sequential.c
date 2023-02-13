#include<stdio.h>
#include<stdlib.h>
int files[100],start[10],len[10],alloc[10];

void allocate(int i)
{
  int count=0;
  for(int k=start[i];k<=(start[i]+len[i]);k++ )
    {
      if(!files[k])
        count++;
    }
  if(count==len[i])
  {
    for(int k=start[i];k<=(start[i]+len[i]);k++ )
    {
      files[k]=1; 
    }
    alloc[i]=1;
  }
  else{
    alloc[i]=0;
  }
}

void display(int n)
{
  	printf("\nFile No.\tStarting block\tLength\tStatus\n");
  for(int i=0;i<n;i++)
    {
      if(alloc[i] == 1)
      printf("%d\t\t%d\t\t%d\tAllocated\n", (i+1), start[i], len[i]);

      else
       printf("%d\t\t-\t\t-\tUnallocated\n", (i+1)); 
    }
}

int main()
{
  printf("Enter the number of files\n");
  int n;
  scanf("%d",&n);
   for(int i=0;i<100;i++)
     {
       files[i]=0;
     }
  printf("Enter the starting location and length ofthe files\n");
  for(int i=0;i<n;i++)
    {
      scanf("%d",&start[i]);
      scanf("%d",&len[10]);
      allocate(i);
if(alloc[i] == 1)
			printf("File %d was successfully allocated!\n", (i+1));
		else
			printf("Unable to allocate disk space to File %d\n", (i+1));
	}
	printf("\n-----------------------------\n");
	printf("The file allocation table is: \n");
	display(n);
  return 0;
  
}