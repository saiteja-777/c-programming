// heap sort
#include<stdio.h>  
int temp;  
void heapify(int a[],int n,int i)  
{  
int largest=i;    
int l=2*i+1;    
int r=2*i+2;    
if(l<n&&a[l]>a[largest])  
largest=l;  
  
if(r<n&&a[r]>a[largest])  
l=r;  
  
if(largest!=i)  
{  
    temp=a[i];  
    a[i]=a[largest];   
    a[largest]=temp;  
heapify(a,n,largest);  
}  
}   
void heapsort(int a[],int n)  
{  
int i;  
for (i=n/2-1;i>=0;i--)  
heapify(a,n,i);  
for (i=n-1;i>=0;i--)  
{  
temp = a[0];  
    a[0]=a[i];   
    a[i]=temp;  
heapify(a, i, 0);  
}  
}  
int main()  
{  
int a[10],n,i;
printf("Enter the number of elements:");
scanf("%d",&n);
printf("Enter elements into array:");
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{
	printf(" %d",a[i]);
}
heapsort(a,n);  
printf("\nSorted elements\n");  
for (i=0;i<n;i++)  
printf("%d ",a[i]);  
}  

