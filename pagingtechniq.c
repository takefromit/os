#include<stdio.h>
int main()
{
    int ms,ps,nop,np,rempages,i,j,x,y,pa,offset;
    int s[10],fno[10][20];

    printf("\nEnter the memory size \n");
    scanf("%d",&ms);
    printf("Enter the page size \n");
    scanf("%d",&ps);
    nop=ms/ps;

    printf("The number of pages available in the memory %d\n", nop);

    printf("Enter the number of process\n");
    scanf("%d",&np);

    rempages=nop;

    for(int i=0;i<np;i++)
    {
        printf("\nEnter the number of pages required for p[%d]\n",i);
        scanf("%d",&s[i]);
        if(s[i]>rempages)
        {
            printf("\nMemory full");
            break;
        }
        rempages=rempages-s[i];
        printf("\nEnter the page table for p[%d]\n",i);
        for(int j=0;j<s[i];j++)
         scanf("%d",&fno[i][j]);

    }

    printf("\nEnter the process number pagenumber and offset\n");
    scanf("%d %d %d",&x,&y,&offset);

    if(x>np || y>=s[i] || offset>=ps)
     printf("\n invalid process or page number or offset\n");

    else{
        pa=fno[x-1][y]*ps+offset;
        printf("\n The physical address is %d",pa);
    } 
}

























//
// Enter the memory size
// 1000
// Enter the page size
// 100
// The number of pages available in the memory 10
// Enter the number of process
// 3

// Enter the number of pages required for p[0]
// 4

// Enter the page table for p[0]
// 8
// 6
// 9
// 5

// Enter the number of pages required for p[1]
// 5

// Enter the page table for p[1]
// 1
// 4
// 5
// 7
// 3

// Enter the number of pages required for p[2]
// 5

// Memory full
// Enter the process number pagenumber and offset
// 2 3 60

//  The physical address is 760