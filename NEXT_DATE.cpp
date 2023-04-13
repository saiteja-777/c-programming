#include<stdio.h>
void nextd(int,int,int,int);
int main()
{
	int d,m,y,l;
	printf("Enter your date :");
	scanf("%d %d %d",&d,&m,&y);
	printf("The date you have entered is : %d:%d:%d",d,m,y);
	if((m>12||d>31)||(m<0||d<0||y<0)||(d==0||m==0||y==0))
	{
		printf("\nThe date you have entered does not exist");
	}
     else if(m==2)
       {if(y%4==0||y%40==0||y%400==0){
				l=29;}
       else {
				l=28;}
	}
	else if(m==10||1||3||5||7||8||12){
			   l=31;
	  }
       else if(m==4||6||9||11){
			   l=30; }    
    printf("\nlimit is : %d",l); 
    nextd(d,m,y,l);
}
void nextd(int d,int m,int y,int l)
{
	if(d>l){
		printf("\nThis date does not exist");}
	else if(d==l)
	{if(m==12){
			d=1;
			m=1;
			y=y+1;}
		else{
			d=1;
			m=m+1;
		}
		printf("\nNext date is : %d : %d : %d",d,m,y);
	}
	else if(d<l){
		d=d+1;
		printf("\nNext date is : %d : %d : %d",d,m,y);
	}
}
