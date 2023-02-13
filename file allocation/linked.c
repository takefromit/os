#include<stdio.h>
#include<stdlib.h>
#define MAX 25

struct files{
int start;
int len;
int alloc[25];
int flag;
}file[10];

int block[MAX];

void allocate(int fno)
{
  int i=file[fno].start;
  int count=0;
  do{
  if(i==file[fno].start && block[i]==1)
  {
    file[fno].flag=0;
    break;
  }
    if(block[i]==0)
    {
      block[i]=1;
      file[fno].alloc[count]=i;
      count++;
    }
      i=(i+1)%MAX;
  }while(count<file[fno].len && i!=file[fno].start);

  if(count==file[fno].len)
    file[fno].flag=1;
  else
    file[fno].flag=0;
}

void display(int n)
{ int i,j
  	printf("File No.\tStarting block\tLength\tStatus\t\tBlocks\n");
  for( i=0;i<n;i++)
    {
      if(file[i].flag == 1) {
			printf("%d\t\t%d\t\t%d\tAllocated\t", (i+1), file[i].start, file[i].len);
			for( j=0; j < file[i].len-1; j++)
				printf("%d -> ", file[i].alloc[j]);
			printf("%d\n", file[i].alloc[j]);
		}
      else{
        printf("%d\t\t-\t\t-\tUnallocated\t\t-\n", (i+1));
      }
    }
}


int main(){
for(int i=0;i<MAX;i++)
  {
   block[i] =0;
  }
  
  int filled,x;
  printf("Enter the number of blocks already allocated\n");
  scanf("%d",&filled);
  for(int i=0;i<filled;i++)
    {
      printf("Enter the location of the occupied block\n");
      scanf("%d",&x);
      block[x]=1;
    }
  printf("Enter the number of file to be allocated\n");
  int n;
  scanf("%d",&n);

  printf("Enter the start and lenght of each file\n");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&file[i].start);
    scanf("%d",&file[i].len);
    allocate(i);
  if(file[i].flag == 1)
			printf("File %d was successfully allocated!\n", (i+1));
		else
			printf("Unable to allocate disk space to file %d\n", (i+1));
	}
	display(n);
  return 0;
}