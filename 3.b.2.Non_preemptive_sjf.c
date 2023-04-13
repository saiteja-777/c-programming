#include<stdio.h>
int main(){
	int n;
	printf("Enter no of processes:");
	scanf("%d",&n);
	int arrival[n],burst[n],pid[n],x[n];
	int i,j,temp;
	for(i=0;i<n;i++){
		printf("enter arrival of %d process",i+1);
		scanf("%d",&arrival[i]);
		pid[i]=i+1;
	}
	for(i=0;i<n;i++){
		printf("enter burst of %d process",i+1);
		scanf("%d",&burst[i]);
	}
	//Sorting by burst time
	for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(burst[j+1]<burst[j])
            {
                temp=arrival[j+1];
                arrival[j+1]=arrival[j];
                arrival[j]=temp;
                temp=burst[j+1];
                burst[j+1]=burst[j];
                burst[j]=temp;
                temp=pid[j+1];
                pid[j+1]=pid[j];
                pid[j]=temp;
            }
 
        }
    }
    //printing arrival and burst times after sorting
    for(i = 0; i < n; i++)
        x[i]=burst[i];
	printf("Arrivals after sort\n");
	for(i=0;i<n;i++){
		printf("%d\n",arrival[i]);
	}
	printf("Burst after sort\n");
	for(i=0;i<n;i++){
		printf("%d\n",burst[i]);
	}
	int count=0,ct[n],currtime=0,flag;	
	while(count!=n){
		flag=0;
		for(i=0;i<n;i++)//finding shortest time process among all process and executing it
		{
			if(x[i]>0&&arrival[i]<=currtime)
			{
				currtime=currtime+burst[i];
				ct[i]=currtime;
				count++;//count the number of the completed processes
				flag=1;
				x[i]=0;
				break;//if a process found execute it and come out from the loop 
			}
		}
		if(flag==0)//if there is no process found in the above loop increament currtime by 1 because,arrival times of the remaining processes are > current time
		{
			currtime++;
		}
		}
		printf("\npid   AT   BT   CT   TAT   WT\n");
		for(i=0;i<n;i++){
			printf("%d     %d    %d    %d    %d      %d\n",pid[i],arrival[i],burst[i],ct[i],ct[i]-arrival[i],ct[i]-arrival[i]-burst[i]);	
		}
	}
		

