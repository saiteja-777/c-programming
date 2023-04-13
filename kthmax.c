#include<stdio.h>
#include<stdlib.h>
int main(){
	int i,j,n,k,temp,kmin,kmax,kk;
	
	printf("Enter n value:");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter array values:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\nEnter k value:");
	scanf("%d",&k);
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j+1]<a[j]){
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("\n%d",a[i]);
	}
	if(k<=n){
		k=k-1;
		kmin=a[k];
		kk=n-k-1;
		kmax=a[kk];
    
	printf("\nkth minimum: %d",kmin);
	printf("\nkth maxmimum:%d",kmax);
    }
    
	
}
