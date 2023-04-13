// merge sort

#include<stdio.h>
void mergesort(int a[],int first,int mid,int last)
{
	int temp[200],index,i,j;
	i=first;
	j=mid+1;
	index=first;
	while(i<=mid&&j<=last)
	{
		if(a[i]<a[j])
		{
			temp[index]=a[i];
			i++;
			index++;
		}
		else
		{
			temp[index]=a[j];
			j++;
			index++;
		}
	}
	if(i>mid)
	{
		while(j<=last)
		{
			temp[index]=a[j];
			j++;
			index++;
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index]=a[i];
			i++;
			index++;
		}
	}
	for(i=0;i<index;i++)
	{
		a[i]=temp[i];
	}
}
void mergesort_divide(int a[],int first,int last)
{
	int mid;
	if(first<last)
	{
		mid=(first+last)/2;
		mergesort_divide(a,first,mid);
		mergesort_divide(a,mid+1,last);
		mergesort(a,first,mid,last);
	}
}
int main()
{
	int a[100],i,n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort_divide(a,0,n-1);
	printf("\nSorted elements:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

