#include<stdio.h>
int main(){
	int n;
	printf("Enter no of processes:");
	scanf("%d",&n);
	int arrival[n],burst[n],pid[n],x[n+1];
	int i,j;
	for(i=0;i<n;i++){
		printf("enter arrival of %d process",i+1);
		scanf("%d",&arrival[i]);
		pid[i]=i+1;
	}
	for(i=0;i<n;i++){
		printf("enter burst of %d process",i+1);
		scanf("%d",&x[i]);
	}
	for(i = 0; i < n; i++)
        burst[i]=x[i];
	int count=0;
	int ct[n],tat[n],wt[n],s;
	int currtime=0,flag;
	x[n]=10000;
	burst[n]=x[n];
	while(count!=n){
		flag=0;
		s=n;//starting comparision with highest burst time at n in x  array having remaining burst times
		for(i=0;i<n;i++)//finding shortest time and its arrival time <= time process among all process
		{
			if(x[i]>0&&arrival[i]<=currtime&&x[i]<x[s])
			{
				flag=1;//if there is the a process found
				s=i;
			} 
		}
		if(flag!=0)
		{
			x[s]--;
			if(x[s]==0)
			{
				ct[s]=currtime+1;
				tat[s]=ct[s]-arrival[s];
				wt[s]=tat[s]-burst[s];
				count++;//count the number of the completed processes
			}			
		}
			currtime++;//since it is preemptive increament time by 1 for every time
		}
		printf("\npid   AT   BT   CT   TAT   WT\n");
		for(i=0;i<n;i++){
			printf("%d     %d    %d    %d    %d      %d\n",pid[i],arrival[i],burst[i],ct[i],tat[i],wt[i]);	
		}
	}
		

