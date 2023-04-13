#include<stdio.h>
int main(){
	int n;
	printf("Enter array size:");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter array elements:");
	int i,j=0,temp;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		if(a[i]<0){
			if(i!=j){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			j++;
		}
	}
	printf("\nAfter sorting:");
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	
}
