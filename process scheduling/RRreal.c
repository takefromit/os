#include<stdio.h>
 
int main() {
  int i, limit, total = 0, n, ctr = 0, tq;
  int wt = 0, tat = 0, arrival_time[10], bt[10], temp[10];
  float avg_wt, avg_tat;
  printf("\n Round Robin Preemptive \n");
  printf("\n Enter number of processes : ");
  scanf("%d", &limit);
  n = limit;
  for(i = 0; i < limit; i++) {
    printf("\n Enter details of process %d", i + 1);
    printf("\n Arrival Time : ");
    scanf("%d", &arrival_time[i]);
    printf(" Burst Time : ");
    scanf("%d", &bt[i]);
    temp[i] = bt[i];
  }
  printf("\n Enter time quantum : ");
  scanf("%d", &tq);
  printf("\n Process ID Burst Time Turn Around Time Waiting Time\n");
  for(total = 0, i = 0; n != 0;) {
    if(temp[i] <= tq && temp[i] > 0) {
      total = total + temp[i];
      temp[i] = 0;
      ctr = 1;
    } else if(temp[i] > 0) {
        temp[i] = temp[i] - tq;
        total = total + tq;
    }

    if(temp[i] == 0 && ctr == 1) {
      n--;
      printf("\t %d\t\t\t%d\t\t\t%d\t\t\t%d\n", i + 1, bt[i], total - arrival_time[i], total - arrival_time[i]-bt[i]);
      wt = wt + total - arrival_time[i] - bt[i];
      tat = tat + total - arrival_time[i];
      ctr = 0;
    }

    if(i == limit - 1)
      i = 0;
    else if(arrival_time[i + 1] <= total)
      i++;
    else
      i = 0;
  }
  avg_wt = wt * 1.0 / limit;
  avg_tat = tat * 1.0 / limit;
  printf("\n The average waiting time : %f", avg_wt);
  printf("\n The average turnaround time : %f", avg_tat);
  printf("\n");
  return 0;
}