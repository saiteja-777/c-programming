#include<stdio.h>
#include<string.h>
int main()
{
    int arr[10],bur[10],star[10],ct[10],tat[10],wt[10],i,j,n,temp;
    int pid[n];
    int totwt=0,tottat=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the Arrival Time& Burst Time:");
        scanf("%d%d",&arr[i],&bur[i]);
        pid[i]=i+1;
    }
    //sorting
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                temp=bur[j+1];
                bur[j+1]=bur[j];
                bur[j]=temp;
                temp=pid[j+1];
                pid[j+1]=pid[j];
                pid[j]=temp;
            }
 
        }
    }
    for(i=0;i<n;i++)
    {
        if(i==0)
            star[i]=arr[i];
        else
        {
        	if(arr[i]<=ct[i-1])
        	{
        	/*if the process arrival time<=previous process completion time 
			then scheduling time of the current process is 
			completion time of the previous process*/
            star[i]=ct[i-1];
        	}
        	else
        	/*else scheduling time of the current process is 
			arrival time of the current process*/
        	star[i]=arr[i];
        }
        //current process executed and wt,tat,ct calculated
        
        ct[i]=star[i]+bur[i];
        tat[i]=ct[i]-arr[i];
        wt[i]=tat[i]-bur[i];
    }
    printf("\nPName Arrtime Burtime Waittime Turnaroundtime Completiontime");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%3d\t%3d\t%3d\t%6d\t%9d",pid[i],arr[i],bur[i],wt[i],tat[i],ct[i]);
        totwt+=wt[i];
        tottat+=tat[i];
    }
    printf("\nAverage Waiting time:%f",(float)totwt/n);
    printf("\nAverage Turn Around Time:%f",(float)tottat/n);
    return 0;
}

