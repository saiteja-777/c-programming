//C Implementation of Non-Preemptive Priority Scheduling lower number higher priority
#include<stdio.h>
#include<conio.h>
main()
{
    int n,i;//number of processes to be scheduled
    printf("Enter the number of processes:");
    scanf("%d",&n);
    int arrivalTime[n],burstTime[n],priority[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the Arrival Time& Burst Time:");
        scanf("%d%d",&arrivalTime[i],&burstTime[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the Priority:");
        scanf("%d",&priority[i]);
    }
    int x[n];
    int waitingTime[n],turnaroundTime[n], completionTime[n];
    int j,smallest,count=0,time=0;//count number of processes completed
    double avg=0,tt=0,end;
    for(i = 0; i < n; i++)
        x[i]=burstTime[i];
    priority[n]=10000;
    while(count!=n)
    {
    	int flag=0;
        smallest=n;//starting comparision with lowest priority at n in priority array
        for(i=0;i<n;i++)//finding highest priority process among all process and its arrival time <= time and executing it
        {
            if (arrivalTime[i]<=time&&priority[i]<priority[smallest] && burstTime[i] > 0)
            {
			smallest = i;
			flag++;//to indicate a process is found
        	}
        }
        if(flag!=0)//if a process found in the above loop
        {
        count++;//count the number of process that are executed completely 
        completionTime[smallest]=time+burstTime[smallest];
        waitingTime[smallest]=completionTime[smallest]-arrivalTime[smallest]-burstTime[smallest];
        turnaroundTime[smallest]=completionTime[smallest]-arrivalTime[smallest];
        time=completionTime[smallest];
        burstTime[smallest]=0;//the process at the smallest is executed completely
    	}  
    	else
    	{
    		time++;//if no process found in above for loop increase the time by 1 because,arrival times of the remaining processes are > current time
		}
    }
    printf("Process\tburst-time\tarrival-time\twaiting-time\tturnaround-time\tcompletion-time\tPriority\n");
    for (i = 0; i < n; i++)
    {
        printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i + 1,x[i],arrivalTime[i],waitingTime[i],turnaroundTime[i],completionTime[i],priority[i]);
        avg = avg + waitingTime[i];
        tt = tt + turnaroundTime[i];
    }
    avg=avg/n;
    tt=tt/n;
    printf("\n\nAverage waiting time time =%f",avg);
    printf("Average turnaround time time =%f",tt);
}
