#include<stdio.h>
#include<conio.h>
void SearchStack01(int pnt,int tm);
void SearchStack02(int pnt, int tm);
void AddQue(int pnt);
int n,at[50], bt[50], ct[50]={0}, qt, rq[50]={0}, st, flg=0, tm=0, noe=0, pnt=0, btm[50]={0}, tt, wt;
float att, awt;
int main(){
printf("Enter number of processes \n");
scanf("%d",&n);
int x;
for(x=0;x<n;x++){
    printf("\nProcess %d\n",x+1);
    printf("Enter AT and BT:");
    scanf("%d %d",&at[x],&bt[x]);
    btm[x]=bt[x];
	}
printf("\nEnter time quantum:");
scanf("%d",&qt);
do{
    if(flg==0){
       st=at[0];
       //---ReduceBT
       if(btm[0]<=qt){
          tm=st+btm[0];  	
          btm[0]=0;
          SearchStack01(pnt,tm);}
       else{
          btm[0]=btm[0]-qt;
          tm=st+qt;
          SearchStack01(pnt,tm);
          AddQue(pnt);
		  }
    }//if
 
    else{
       pnt=rq[0]-1;
       st=tm;
       //---DeleteQue
       int x;
       for(x=0;x<noe && noe!=1;x++){
          rq[x]=rq[x+1];
		  }
       noe--;
       //---ReduceBT
       if(btm[pnt]<=qt){
          tm=st+btm[pnt];
          btm[pnt]=0;
          SearchStack02(pnt, tm);}
       else{
         btm[pnt]=btm[pnt]-qt;
          tm=st+qt;
          SearchStack02(pnt, tm);
          AddQue(pnt);}
    }//else

    //AssignCTvalue
    if(btm[pnt]==0){
       ct[pnt]=tm;
    }//if

   flg++;
}while(noe!=0);

printf("\n\nPROCESS\t AT\t BT\t CT\t TT\t WT\n");
awt=att=0;  
for(x=0;x<n;x++){
    tt=ct[x]-at[x];
    wt=tt-bt[x];
    printf("P%d\t%d\t %d\t%d\t%d\t%d\n",x+1,at[x],bt[x],ct[x],tt,wt);
    awt=awt+wt;
    att=att+tt;
}//for

printf("\nAVERAGE TT:%f \nAVERAGE WT:%f ",att/n,awt/n);

}//main

void SearchStack01(int pnt,int tm){
	int x;
    for(x=pnt+1;x<n;x++){
       if(at[x]<=tm){
          rq[noe]=x+1;
          noe++;}
    }//for
}//void
void SearchStack02(int pnt, int tm){
	int x,y;
    for(x=pnt+1;x<n;x++){
       //---CheckQue
       int fl=0;
       for(y=0;y<noe;y++){
          if(rq[y]==x+1){
             fl++;
			 }
			 }
       if(at[x]<=tm && fl==0 && btm[x]!=0){
          rq[noe]=x+1;
          noe++;}
    }//for
}//void
void AddQue(int pnt){
    rq[noe]=pnt+1;
    noe++;
}
