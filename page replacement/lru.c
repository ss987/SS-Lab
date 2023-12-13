#include<stdio.h>
int lru(int time[],int n){
    int i,min=time[0],loc=0;
    for(i=1;i<n;i++){
        if(time[i]<min){
            min=time[i];
            loc=i;
        }
    }
    return loc;
}
int main(){
    int count=0,loc,time[20],np,nf,refstr[50],i,frame[10],j,k,avail,fault=0,flag1,flag2;
    printf("Enter no of pg:");
    scanf("%d",&np);
    printf("Enter pg:");
    for(i=0;i<np;i++){
        scanf("%d",&refstr[i]);
    }
    printf("Enter no of frame:");
    scanf("%d",&nf);
    for(i=0;i<nf;i++){
        frame[i]=-1;
    }
    printf("Incoming\t\tframe\t\tFault\n");
    for(i=0;i<np;i++){
        flag1=0;
        flag2=0;
        printf("%d\t\t",refstr[i]);
        for(j=0;j<nf;j++){
            if(frame[j]==refstr[i]){
                count++;
                time[j]=count;
                flag1=flag2=1;
                for(k=0;k<nf;k++){
                    printf("%d ",frame[k]);
                }
                printf("H\n");
            }
        }
        if(flag1==0){
            for(j=0;j<nf;j++){
                if(frame[j]==-1){
                    count++;
                    fault++;
                    frame[j]=refstr[i];
                    time[j]=count;
                    flag2=1;
                    for(k=0;k<nf;k++){
                        printf("%d ",frame[k]);
                    }
                    printf("F\n");
                    break;
                }
            }
        }
        if(flag2==0){
            loc=lru(time,nf);
            count++;
            time[loc]=count;
            fault++;
            frame[loc]=refstr[i];
            for(k=0;k<nf;k++){
                        printf("%d ",frame[k]);
                    }
                    printf("F\n");
        }
        

    }
}