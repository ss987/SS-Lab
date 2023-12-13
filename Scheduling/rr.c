#include<stdio.h>
int front=-1,rear=-1,queue[100];
void insert(int n){
    if(front==-1)
        front++;
    rear++;
    queue[rear]=n;
}
int delete(){
    int n;
    n=queue[front];
    front++;
    return n;
}
int main(){
    int at[20],bt[20],ct[20],pid[20],rt[20],wt[20],tat[20],twt=0,ttat=0,awt,atat,n,i,exist[20]={0},time=0,tq,j;
    printf("Enter no");
    scanf("%d",&n);
    printf("enter at n bt\n");
    for(i=0;i<n;i++){
        scanf("%d",&at[i]);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
        pid[i]=i;
    }
    printf("Enter tq");
    scanf("%d",&tq);
    insert(0);
    exist[0]=1;
    while(front<=rear){
        int p;
        p=delete();
        if(tq>=rt[p]){
            time+=rt[p];
            rt[p]=0;
        }
        else{
            time+=tq;
            rt[p]-=tq;
        }
        for(j=0;j<n;j++){
            if(exist[j]==0 && at[j]<=time){
                insert(j);
                exist[j]=1;
            }
        }
        if (rt[p] == 0) {
        ct[p] = time;
        tat[p] = ct[p] - at[p];
        wt[p] = tat[p] - bt[p];
        ttat += tat[p];
        twt += wt[p];
}

        else{
            insert(p);
        }
    }
    for(j=0;j<n;j++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[j],at[j],bt[j],ct[j],tat[j],wt[j]);
    }
    
    return 0;
}