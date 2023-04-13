#include<stdio.h>
int main()
{
	int i,j,n;
	int p[10],bt[10],ct[10],tat[10],wt[10];
	float awt=0,atat=0;
	printf("enter number of process:");
	scanf("%d",&n);
	printf("enter process id: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	printf("enter burst time: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	printf("pid \t bt\n");
	for(i=0;i<n;i++)
	{
		printf("%d \t %d\n",p[i],bt[i]);
	}
	printf("after sorting \n");
    for(i=0;i<n-1;i++)	
    {
    	int min=i;
    	int min1=i;
    	for(j=1+1;j<n;j++)
    	{
    		if(bt[j]<bt[min])
    		{
    			min=j;
    			min1=j;
			}
		}
		int temp;
		temp=bt[min];
		bt[min]=bt[i];
		bt[i]=temp;
		 
		int temp1;
		temp1=p[min1];
		p[min1]=p[i];
		p[i]=temp1;
	}
	ct[0]=bt[0];
	for(i=1;i<n;i++)
	{
		ct[i]=ct[i-1]+bt[i];
	}
	printf("pid \t bt \t ct \t tat \t wt\n");
	for(i=0;i<n;i++)
	{
		tat[i]=ct[i];
		wt[i]=tat[i]-bt[i];
		atat+=tat[i];
		awt+=wt[i];
	}
	atat=atat/n;
	awt=awt/n;
	for(i=0;i<n;i++)
	{
	   printf("%d \t %d \t %d \t %d \t %d\n",p[i],bt[i],ct[i],tat[i],wt[i]);	
	}
	
	printf("Average turnaroundtime: %f\n",atat);
	printf("Average waiting time:%f",awt);
}
